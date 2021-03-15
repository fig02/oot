/*
 * File: z_en_vase.c
 * Overlay: ovl_En_Vase
 * Description: An unused, orange pot based on ALTTP. Lacks collision.
 */

#include "z_en_vase.h"
#include "objects/object_vase/object_vase.h"

#define FLAGS 0x00000010

#define THIS ((EnVase*)thisx)

void EnVase_Init(Actor* thisx, GlobalContext* globalCtx);
void EnVase_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnVase_Update(Actor* thisx, GlobalContext* globalCtx);
void EnVase_Draw(Actor* thisx, GlobalContext* globalCtx);

void Dorrie_Wait(EnVase* this, GlobalContext* globalCtx);

const ActorInit En_Vase_InitVars = {
    ACTOR_EN_VASE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_VASE,
    sizeof(EnVase),
    (ActorFunc)EnVase_Init,
    (ActorFunc)EnVase_Destroy,
    (ActorFunc)EnVase_Update,
    (ActorFunc)EnVase_Draw,
};

static ColliderCylinderInit sCylinderInit1 = {
    {
        COLTYPE_NONE,
        AT_TYPE_PLAYER,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1 | OC2_UNK1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFFFFFFF, 0x00, 0x04 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 100, 70, 0, { 0, 0, 0 } },
};

typedef enum { DORRIE_WAIT, DORRIE_MOVE_DELAY, DORRIE_MOVE, DORRIE_TURN } DorrieState;

void EnVase_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnVase* this = THIS;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&this->dyna, DPM_PLAYER);
    CollisionHeader_GetVirtual(&gDorrieCol_collisionHeader, &colHeader);
    this->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, colHeader);
    Actor_SetScale(&this->dyna.actor, 0.045f);
    SkelAnime_Init(globalCtx, &this->skelAnime, &gDorrieSkel, &gDorrieIdleSm64_anim_002Anim, this->jointTable,
                   this->morphTable, 22);
    Lights_PointNoGlowSetInfo(&this->lightInfo, thisx->world.pos.x, thisx->world.pos.y + 15.0f, thisx->world.pos.z, 255,
                              255, 255, 500);
    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, &this->dyna.actor, &sCylinderInit1);
    this->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &this->lightInfo);
    this->finAngle = 0x3000;
    this->targetTurn = this->dyna.actor.shape.rot.y + 0x8000;
    this->dyna.actor.world.rot.y = this->dyna.actor.shape.rot.y;
    this->actionFunc = Dorrie_Wait;
    this->state = DORRIE_WAIT;
    this->dyna.actor.speedXZ = 0.0f;
    this->introDone = false;
}

void Dorrie_Move(EnVase* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    Math_ScaledStepToS(&this->dyna.actor.shape.rot.y, player->actor.shape.rot.y, 300);
    this->dyna.actor.world.rot.y = this->dyna.actor.shape.rot.y;
    this->dyna.actor.speedXZ = 5.0f;

    if ((this->state == DORRIE_MOVE) && !(this->dyna.unk_160 & 2)) {
        this->actionFunc = Dorrie_Wait;
        this->state = DORRIE_WAIT;
        this->dyna.actor.speedXZ = 0.0f;
        this->dyna.actor.gravity = -1.0f;
    }
}

void Dorrie_Talk(EnVase* this, GlobalContext* globalCtx) {
    u8 dialogState = func_8010BDBC(&globalCtx->msgCtx);

    if (dialogState != 4) {
        if (dialogState == 6 && func_80106BC8(globalCtx)) { // advanced final textbox
            this->actionFunc = Dorrie_Wait;

            if (!this->introDone) {
                this->introDone = true;
                this->state = DORRIE_TURN;
            }
        }
    }
}

#define TALK_RANGE 250.0f

void Dorrie_Wait(EnVase* this, GlobalContext* globalCtx) {
    s16 yawDiff = this->dyna.actor.yawTowardsPlayer - this->dyna.actor.shape.rot.y;
    Player* player = PLAYER;

    if (func_8002F194(&this->dyna.actor, globalCtx)) {
        this->actionFunc = Dorrie_Talk;
    } else {
        if ((this->dyna.actor.xzDistToPlayer < TALK_RANGE) && (ABS(yawDiff) <= 0x4000)) {
            this->dyna.actor.textId = 0x202C;
            func_8002F2CC(&this->dyna.actor, globalCtx, TALK_RANGE);
        }
    }

    if ((this->state == DORRIE_WAIT) && (this->dyna.unk_160 & 2)) {
        this->timer = 20;
        this->state = DORRIE_MOVE_DELAY;
    }

    if ((this->state == DORRIE_MOVE_DELAY) && (this->timer == 0)) {
        this->state = DORRIE_MOVE;
        this->actionFunc = Dorrie_Move;
    }

    if (this->state == DORRIE_TURN) {
        s32 done = Math_ScaledStepToS(&this->dyna.actor.shape.rot.y, this->targetTurn, 500);
        this->dyna.actor.world.rot.y = this->dyna.actor.shape.rot.y;

        if (done) {
            this->state = DORRIE_WAIT;
        }
    }
}

void EnVase_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

#define INITIAL_ANGLE 0x2000
#define FINAL_ANGLE 0x5000
#define SPEED 300
s32 dir = 0;

void EnVase_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnVase* this = THIS;
    Input* cont1 = &globalCtx->state.input[0];
    f32 w;

    if (this->timer > 0) {
        this->timer--;
    }

    this->actionFunc(this, globalCtx);

    Actor_MoveForward(thisx);
    Actor_UpdateBgCheckInfo(globalCtx, &this->dyna.actor, 75.0f, 60.0f, 70.0f, 0x1D);

    Lights_PointNoGlowSetInfo(&this->lightInfo, thisx->world.pos.x, thisx->world.pos.y + 15.0f, thisx->world.pos.z, 255,
                              255, 255, 500);
    if (dir == 1) {
        if (Math_ScaledStepToS(&this->finAngle, INITIAL_ANGLE, SPEED)) {
            dir ^= 1;
        }
    } else {
        if (Math_ScaledStepToS(&this->finAngle, FINAL_ANGLE, SPEED)) {
            dir ^= 1;
        }
    }

    if (this->dyna.actor.bgCheckFlags & 0x20) {
        // Float on water surface
        this->dyna.actor.gravity = 0.0f;
        Math_SmoothStepToF(&this->dyna.actor.velocity.y, 0.0f, 1.0f, 2.0f, 0.0f);
        Math_SmoothStepToF(&this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.y + this->dyna.actor.yDistToWater,
                           1.0f, 2.0f, 0.0f);
    } else {
        this->dyna.actor.gravity = -1.0f;
    }

    if ((this->dyna.actor.bgCheckFlags & 3) && (this->dyna.actor.velocity.y <= 0.0f)) {
        this->dyna.actor.velocity.y = 0.0f;
    }

    CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
}

#define FIN_BACK_RIGHT 14
#define FIN_FRONT_RIGHT 16
#define FIN_BACK_LEFT 18
#define FIN_FRONT_LEFT 20

s32 EnVase_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnVase* this = THIS;

    if (limbIndex == FIN_FRONT_RIGHT || limbIndex == FIN_BACK_RIGHT) {
        rot->x = this->finAngle;
    }

    if (limbIndex == FIN_FRONT_LEFT || limbIndex == FIN_BACK_LEFT) {
        rot->x = -this->finAngle;
    }

    return false;
}

void Dorrie_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnVase* this = THIS;
    Vec3f sp1C = { 700.0f, 600.0f, 0.0f };

    if (limbIndex == 8) {
        Matrix_MultVec3f(&sp1C, &this->dyna.actor.focus.pos);
    }
}

void EnVase_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnVase* this = THIS;

    SkelAnime_DrawOpa(globalCtx, this->skelAnime.skeleton, this->skelAnime.jointTable, EnVase_OverrideLimbDraw,
                      Dorrie_PostLimbDraw, this);
}
