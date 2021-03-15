/*
 * File: z_en_dog.c
 * Overlay: ovl_En_Dog
 * Description: Dog
 */

#include "z_en_dog.h"
#include "objects/object_dog/object_dog.h"

#define FLAGS 0x00000000

#define THIS ((EnDog*)thisx)

void EnDog_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDog_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDog_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDog_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDog_FollowPath(EnDog* this, GlobalContext* globalCtx);
void EnDog_ChooseMovement(EnDog* this, GlobalContext* globalCtx);
void EnDog_FollowLink(EnDog* this, GlobalContext* globalCtx);
void EnDog_RunAway(EnDog* this, GlobalContext* globalCtx);
void EnDog_FaceLink(EnDog* this, GlobalContext* globalCtx);
void EnDog_Wait(EnDog* this, GlobalContext* globalCtx);

typedef enum {
    /* 0x00 */ DOG_WALK,
    /* 0x01 */ DOG_RUN,
    /* 0x02 */ DOG_BARK,
    /* 0x03 */ DOG_SIT,
    /* 0x04 */ DOG_SIT_HOLD,
    /* 0x05 */ DOG_BOW,
    /* 0x06 */ DOG_BOW_HOLD
} DogBehavior;

const ActorInit En_Dog_InitVars = {
    ACTOR_EN_DOG,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DOG,
    sizeof(EnDog),
    (ActorFunc)EnDog_Init,
    (ActorFunc)EnDog_Destroy,
    (ActorFunc)EnDog_Update,
    (ActorFunc)EnDog_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT6,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 16, 20, 0, { 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, 50 };

typedef enum {
    /* 0 */ DOG_ANIM_WALK_INSTANT,
    /* 1 */ DOG_ANIM_WALK_MORPH,
    /* 2 */ DOG_ANIM_RUN,
    /* 3 */ DOG_ANIM_BARK,
    /* 4 */ DOG_ANIM_SIT_START,
    /* 5 */ DOG_ANIM_SIT_HOLD,
    /* 6 */ DOG_ANIM_BOW_START,
    /* 7 */ DOG_ANIM_BOW_HOLD
} DogAnimationEntry;

static ActorAnimationEntry sAnimationEntries[] = {
    { &gDogWalkAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gDogWalkAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -6.0f },
    { &gDogRunAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -6.0f },
    { &gDogBarkAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -6.0f },
    { &gDogSitAnim, 1.0f, 0.0f, 4.0f, ANIMMODE_ONCE, -6.0f },
    { &gDogSitAnim, 1.0f, 5.0f, 25.0f, ANIMMODE_LOOP_PARTIAL, -6.0f },
    { &gDogBowStartAnim, 1.0f, 0.0f, 6.0f, ANIMMODE_ONCE, -6.0f },
    { &gDogBowHoldAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -6.0f },
};

void EnDog_PlayWalkSFX(EnDog* this) {
    AnimationHeader* dogWalkAnim = &gDogWalkAnim;

    if (this->skelAnime.animation == dogWalkAnim) {
        if ((this->skelAnime.curFrame == 1.0f) || (this->skelAnime.curFrame == 7.0f)) {
            Audio_PlayActorSound2(&this->actor, NA_SE_EV_CHIBI_WALK);
        }
    }
}

void EnDog_PlayRunSFX(EnDog* this) {
    AnimationHeader* dogRunAnim = &gDogRunAnim;

    if (this->skelAnime.animation == dogRunAnim) {
        if ((this->skelAnime.curFrame == 2.0f) || (this->skelAnime.curFrame == 4.0f)) {
            Audio_PlayActorSound2(&this->actor, NA_SE_EV_CHIBI_WALK);
        }
    }
}

void EnDog_PlayBarkSFX(EnDog* this) {
    AnimationHeader* dogBarkAnim = &gDogBarkAnim;

    if (this->skelAnime.animation == dogBarkAnim) {
        if ((this->skelAnime.curFrame == 13.0f) || (this->skelAnime.curFrame == 19.0f)) {
            Audio_PlayActorSound2(&this->actor, NA_SE_EV_SMALL_DOG_BARK);
        }
    }
}

s32 EnDog_PlayAnimAndSFX(EnDog* this) {
    s32 animIndex;

    if (this->behavior != this->nextBehavior) {
        if (this->nextBehavior == DOG_SIT_HOLD) {
            this->nextBehavior = DOG_SIT;
        }

        if (this->nextBehavior == DOG_BOW_HOLD) {
            this->nextBehavior = DOG_BOW;
        }

        this->behavior = this->nextBehavior;

        switch (this->behavior) {
            case DOG_WALK:
                animIndex = DOG_ANIM_WALK_MORPH;
                break;
            case DOG_RUN:
                animIndex = DOG_ANIM_RUN;
                break;
            case DOG_BARK:
                animIndex = DOG_ANIM_BARK;
                break;
            case DOG_SIT:
                animIndex = DOG_ANIM_SIT_START;
                break;
            case DOG_BOW:
                animIndex = DOG_ANIM_BOW_START;
                break;
        }

        Actor_ChangeAnimation(&this->skelAnime, sAnimationEntries, animIndex);
    }

    switch (this->behavior) {
        case DOG_SIT:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Actor_ChangeAnimation(&this->skelAnime, sAnimationEntries, DOG_ANIM_SIT_HOLD);
                this->behavior = this->nextBehavior = DOG_SIT_HOLD;
            }
            break;
        case DOG_BOW:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Actor_ChangeAnimation(&this->skelAnime, sAnimationEntries, DOG_ANIM_BOW_HOLD);
                this->behavior = this->nextBehavior = DOG_BOW_HOLD;
            }
            break;
        case DOG_WALK:
            EnDog_PlayWalkSFX(this);
            break;
        case DOG_RUN:
            EnDog_PlayRunSFX(this);
            break;
        case DOG_BARK:
            EnDog_PlayBarkSFX(this);
            if (this) {} // needed for regalloc
            break;
    }

    return 0;
}

s8 EnDog_CanFollow(EnDog* this, GlobalContext* globalCtx) {
    // checks for hurtbox collided, but the dogs hurtbox is never updated.
    // nothing checks for return value 2 as well, so it seems hitting dogs was a cut feature
    if (this->collider.base.acFlags & AC_HIT) {
        this->collider.base.acFlags &= ~AC_HIT;
        return 2;
    }

    if (globalCtx->sceneNum == SCENE_MARKET_DAY) {
        return 0;
    }

    if (this->collider.base.maskB & OC2_HIT_PLAYER) {
        this->collider.base.maskB &= ~OC2_HIT_PLAYER;

        if (gSaveContext.dogParams != 0) {
            return 0;
        }

        gSaveContext.dogParams = (this->actor.params & 0x7FFF);
        return 1;
    }

    return 0;
}

s32 EnDog_UpdateWaypoint(EnDog* this, GlobalContext* globalCtx) {
    s32 direction;

    if (this->path == NULL) {
        return 0;
    }

    if (this->reverse) {
        direction = -1;
    } else {
        direction = 1;
    }

    this->waypoint += direction;

    if (this->reverse) {
        if (this->waypoint < 0) {
            this->waypoint = this->path->count - 1;
        }
    } else {
        if ((this->path->count - 1) < this->waypoint) {
            this->waypoint = 0;
        }
    }

    return 1;
}

s32 EnDog_Orient(EnDog* this, GlobalContext* globalCtx) {
    s16 targetYaw;
    f32 waypointDistSq;

    waypointDistSq = Path_OrientAndGetDistSq(&this->actor, this->path, this->waypoint, &targetYaw);
    Math_SmoothStepToS(&this->actor.world.rot.y, targetYaw, 10, 1000, 1);

    if ((waypointDistSq > 0.0f) && (waypointDistSq < 1000.0f)) {
        return EnDog_UpdateWaypoint(this, globalCtx);
    } else {
        return 0;
    }
}

void EnDog_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDog* this = THIS;
    s16 followingDog;
    s32 pad;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 24.0f);
    SkelAnime_InitFlex(globalCtx, &this->skelAnime, &gDogSkel, NULL, this->jointTable, this->morphTable, 13);
    Actor_ChangeAnimation(&this->skelAnime, sAnimationEntries, 0);

    if ((this->actor.params & 0x8000) == 0) {
        this->actor.params = (this->actor.params & 0xF0FF) | ((((this->actor.params & 0x0F00) >> 8) + 1) << 8);
    }

    followingDog = ((gSaveContext.dogParams & 0x0F00) >> 8);

    if (followingDog == ((this->actor.params & 0x0F00) >> 8) && ((this->actor.params & 0x8000) == 0)) {
        Actor_Kill(&this->actor);
        return;
    }

    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, &this->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&this->actor.colChkInfo, 0, &sColChkInfoInit);
    Actor_SetScale(&this->actor, 0.0075f);
    this->waypoint = 0;
    this->actor.gravity = -1.0f;
    this->path = Path_GetByIndex(globalCtx, (this->actor.params & 0x00F0) >> 4, 0xF);

    switch (globalCtx->sceneNum) {
        case SCENE_MARKET_NIGHT:
            if ((!gSaveContext.dogIsLost) && (((this->actor.params & 0x0F00) >> 8) == 1)) {
                Actor_Kill(&this->actor);
            }
            break;
        case SCENE_IMPA: // Richard's Home
            if ((this->actor.params & 0x8000) == 0) {
                if (!gSaveContext.dogIsLost) {
                    this->nextBehavior = DOG_SIT;
                    this->actionFunc = EnDog_Wait;
                    this->actor.speedXZ = 0.0f;
                    return;
                } else {
                    Actor_Kill(&this->actor);
                    return;
                }
            }
            break;
    }

    if ((this->actor.params & 0x8000) != 0) {
        this->nextBehavior = DOG_WALK;
        this->actionFunc = EnDog_FollowLink;
    } else {
        this->nextBehavior = DOG_SIT;
        this->actionFunc = EnDog_ChooseMovement;
    }
}

void EnDog_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDog* this = THIS;

    Collider_DestroyCylinder(globalCtx, &this->collider);
}

void EnDog_FollowPath(EnDog* this, GlobalContext* globalCtx) {
    s32 behaviors[] = { DOG_SIT, DOG_BOW, DOG_BARK };
    s32 unused[] = { 40, 80, 20 };
    f32 speed;
    s32 frame;

    if (EnDog_CanFollow(this, globalCtx) == 1) {
        this->actionFunc = EnDog_FollowLink;
    }

    if (DECR(this->behaviorTimer) != 0) {
        speed = (this->nextBehavior == DOG_WALK) ? 1.0f : 4.0f;
        Math_SmoothStepToF(&this->actor.speedXZ, speed, 0.4f, 1.0f, 0.0f);
        EnDog_Orient(this, globalCtx);
        this->actor.shape.rot = this->actor.world.rot;

        // Used to change between two text boxes for Richard's owner in the Market Day scene
        // depending on where he is on his path. En_Hy checks these event flags.
        if (this->waypoint < 9) {
            // Richard is close to her, text says something about his coat
            gSaveContext.eventInf[3] |= 1;
        } else {
            // Richard is far, text says something about running fast
            gSaveContext.eventInf[3] &= ~1;
        }
    } else {
        frame = globalCtx->state.frames % 3;
        this->nextBehavior = behaviors[frame];
        // no clue why they're using the behavior id to calculate timer. possibly meant to use the unused array?
        this->behaviorTimer = Rand_S16Offset(60, behaviors[frame]);
        this->actionFunc = EnDog_ChooseMovement;
    }
}

void EnDog_ChooseMovement(EnDog* this, GlobalContext* globalCtx) {
    if (EnDog_CanFollow(this, globalCtx) == 1) {
        this->actionFunc = EnDog_FollowLink;
    }

    if (DECR(this->behaviorTimer) == 0) {
        this->behaviorTimer = Rand_S16Offset(200, 100);

        if (globalCtx->state.frames % 2) {
            this->nextBehavior = DOG_WALK;
        } else {
            this->nextBehavior = DOG_RUN;
        }

        if (this->nextBehavior == DOG_RUN) {
            this->behaviorTimer /= 2;
        }

        this->actionFunc = EnDog_FollowPath;
    }

    Math_SmoothStepToF(&this->actor.speedXZ, 0.0f, 0.4f, 1.0f, 0.0f);
}

void EnDog_FollowLink(EnDog* this, GlobalContext* globalCtx) {
    f32 speed;

    if (gSaveContext.dogParams == 0) {
        this->nextBehavior = DOG_SIT;
        this->actionFunc = EnDog_Wait;
        this->actor.speedXZ = 0.0f;
        return;
    }

    if (this->actor.xzDistToLink > 400.0f) {
        if (this->nextBehavior != DOG_SIT && this->nextBehavior != DOG_SIT_HOLD) {
            this->nextBehavior = DOG_BOW;
        }
        gSaveContext.dogParams = 0;
        speed = 0.0f;
    } else if (this->actor.xzDistToPlayer > 100.0f) {
        this->nextBehavior = DOG_RUN;
        speed = 4.0f;
    } else if (this->actor.xzDistToLink < 40.0f) {
        if (this->nextBehavior != DOG_BOW && this->nextBehavior != DOG_BOW_HOLD) {
            this->nextBehavior = DOG_BOW;
        }
        speed = 0.0f;
    } else {
        this->nextBehavior = DOG_WALK;
        speed = 1.0f;
    }

    Math_ApproachF(&this->actor.speedXZ, speed, 0.6f, 1.0f);

    if (!(this->actor.xzDistToPlayer > 400.0f)) {
        Math_SmoothStepToS(&this->actor.world.rot.y, this->actor.yawTowardsPlayer, 10, 1000, 1);
        this->actor.shape.rot = this->actor.world.rot;
    }
}

void EnDog_RunAway(EnDog* this, GlobalContext* globalCtx) {
    if (this->actor.xzDistToPlayer < 200.0f) {
        Math_ApproachF(&this->actor.speedXZ, 4.0f, 0.6f, 1.0f);
        Math_SmoothStepToS(&this->actor.world.rot.y, (this->actor.yawTowardsPlayer ^ 0x8000), 10, 1000, 1);
    } else {
        this->actionFunc = EnDog_FaceLink;
    }

    this->actor.shape.rot = this->actor.posRot.rot;
}

void EnDog_FaceLink(EnDog* this, GlobalContext* globalCtx) {
    s16 rotTowardLink;
    s16 prevRotY;
    f32 absAngleDiff;

    // if the dog is more than 200 units away from Link, turn to face him then wait
    if (this->actor.xzDistToLink >= 200.0f) {
        this->nextBehavior = DOG_WALK;
        Math_ApproachF(&this->actor.speedXZ, 1.0f, 0.6f, 1.0f);
        rotTowardLink = this->actor.yawTowardsLink;
        prevRotY = this->actor.posRot.rot.y;
        Math_SmoothStepToS(&this->actor.posRot.rot.y, rotTowardLink, 10, 1000, 1);
        absAngleDiff = this->actor.posRot.rot.y;
        absAngleDiff -= prevRotY;
        absAngleDiff = fabsf(absAngleDiff);

        if (absAngleDiff < 200.0f) {
            this->nextBehavior = DOG_SIT;
            this->actionFunc = EnDog_Wait;
            this->actor.speedXZ = 0.0f;
        }
    } else {
        this->nextBehavior = DOG_RUN;
        this->actionFunc = EnDog_RunAway;
    }
    this->actor.shape.rot = this->actor.world.rot;
}

void EnDog_Wait(EnDog* this, GlobalContext* globalCtx) {
    this->unusedAngle = (this->actor.yawTowardsPlayer - this->actor.shape.rot.y);

    // If another dog is following Link and he gets within 200 units of waiting dog, run away
    if ((gSaveContext.dogParams != 0) && (this->actor.xzDistToPlayer < 200.0f)) {
        this->nextBehavior = DOG_RUN;
        this->actionFunc = EnDog_RunAway;
    }
}

void EnDog_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDog* this = THIS;
    s32 pad;

    EnDog_PlayAnimAndSFX(this);
    SkelAnime_Update(&this->skelAnime);
    Actor_UpdateBgCheckInfo(globalCtx, &this->actor, this->collider.dim.radius, this->collider.dim.height * 0.5f, 0.0f,
                            5);
    Actor_MoveForward(&this->actor);
    this->actionFunc(this, globalCtx);
    Collider_CylinderUpdate(&this->actor, &this->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
}

s32 EnDog_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    return false;
}

void EnDog_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
}

void EnDog_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDog* this = THIS;
    Color_RGBA8 dogColors[] = { { 255, 255, 200, 0 }, { 150, 100, 50, 0 } };

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dog.c", 972);

    func_80093D18(globalCtx->state.gfxCtx);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, dogColors[this->actor.params & 0xF].r, dogColors[this->actor.params & 0xF].g,
                   dogColors[this->actor.params & 0xF].b, dogColors[this->actor.params & 0xF].a);

    SkelAnime_DrawFlexOpa(globalCtx, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                          EnDog_OverrideLimbDraw, EnDog_PostLimbDraw, this);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dog.c", 994);
}
