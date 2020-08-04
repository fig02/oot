/*
 * File: z_arrow_fire.c
 * Overlay: ovl_Arrow_Fire
 * Description: Fire Arrow. Spawned by and attached to a normal arrow.
 */

#include "z_arrow_fire.h"
#include "overlays/actors/ovl_En_Arrow/z_en_arrow.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"

#define FLAGS 0x02000010

#define THIS ((ArrowFire*)thisx)

void ArrowFire_Init(Actor* thisx, GlobalContext* globalCtx);
void ArrowFire_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ArrowFire_Update(Actor* thisx, GlobalContext* globalCtx);
void ArrowFire_Draw(Actor* thisx, GlobalContext* globalCtx);

void ArrowFire_Charge(ArrowFire* this, GlobalContext* globalCtx);
void ArrowFire_Fly(ArrowFire* this, GlobalContext* globalCtx);
void ArrowFire_Hit(ArrowFire* this, GlobalContext* globalCtx);

#include "z_arrow_fire_gfx.c"

const ActorInit Arrow_Fire_InitVars = {
    ACTOR_ARROW_FIRE,
    ACTORTYPE_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ArrowFire),
    (ActorFunc)ArrowFire_Init,
    (ActorFunc)ArrowFire_Destroy,
    (ActorFunc)ArrowFire_Update,
    (ActorFunc)ArrowFire_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_STOP),
};

void ArrowFire_SetupAction(ArrowFire* this, ArrowFireActionFunc actionFunc) {
    this->actionFunc = actionFunc;
}

void ArrowFire_Init(Actor* thisx, GlobalContext* globalCtx) {
    ArrowFire* this = THIS;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    this->radius = 0;
    this->unk_158 = 1.0f;
    ArrowFire_SetupAction(&this->actor, ArrowFire_Charge);
    Actor_SetScale(this, 0.01f);
    this->alpha = 160;
    this->timer = 0;
    this->unk_15C = 0.0f;
    this->exploded = false;
    this->startBombCount = AMMO(ITEM_BOMB);
}

void ArrowFire_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    func_800876C8(globalCtx);
    // Translates to: "Disappearance"
    LOG_STRING("消滅", "../z_arrow_fire.c", 421);
}

void ArrowFire_Charge(ArrowFire* this, GlobalContext* globalCtx) {
    EnArrow* arrow;

    arrow = (EnArrow*)this->actor.attachedA;
    if ((arrow == NULL) || (arrow->actor.update == NULL)) {
        Actor_Kill(&this->actor);
        return;
    }

    if (this->radius < 10) {
        this->radius += 1;
    }
    // copy position and rotation from the attached arrow
    this->actor.posRot.pos = arrow->actor.posRot.pos;
    this->actor.shape.rot = arrow->actor.shape.rot;
    func_8002F974(&this->actor, NA_SE_IT_BOMB_IGNIT - SFX_FLAG);

    // If arrow's attached is null, Link has fired the arrow
    if (arrow->actor.attachedA == NULL) {
        this->unkPos = this->actor.posRot.pos;
        this->radius = 10;
        ArrowFire_SetupAction(this, ArrowFire_Fly);
        this->alpha = 255;
    }
}

void func_80865ECC(Vec3f* unkPos, Vec3f* firePos, f32 scale) {
    unkPos->x += ((firePos->x - unkPos->x) * scale);
    unkPos->y += ((firePos->y - unkPos->y) * scale);
    unkPos->z += ((firePos->z - unkPos->z) * scale);
}

void ArrowFire_Hit(ArrowFire* this, GlobalContext* globalCtx) {
    f32 scale;
    f32 offset;
    u16 timer;

    if (!this->exploded) {
        EnBom* bomb = (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, this->actor.posRot.pos.x,
                                          this->actor.posRot.pos.y, this->actor.posRot.pos.z, 0, 0, 0, 0);
        bomb->timer = 0;
        this->exploded = true;
    }
    if (this->actor.projectedW < 50.0f) {
        scale = 10.0f;
    } else {
        if (950.0f < this->actor.projectedW) {
            scale = 310.0f;
        } else {
            scale = this->actor.projectedW;
            scale = ((scale - 50.0f) * (1.0f / 3.0f)) + 10.0f;
        }
    }

    timer = this->timer;
    if (timer != 0) {
        this->timer -= 1;

        if (this->timer >= 8) {
            offset = ((this->timer - 8) * (1.0f / 24.0f));
            offset = SQ(offset);
            this->radius = (((1.0f - offset) * scale) + 10.0f);
            this->unk_158 += ((2.0f - this->unk_158) * 0.1f);
            if (this->timer < 16) {
                if (1) {}
                this->alpha = ((this->timer * 0x23) - 0x118);
            }
        }
    }

    if (this->timer >= 9) {
        if (this->unk_15C < 1.0f) {
            this->unk_15C += 0.25f;
        }
    } else {
        if (this->unk_15C > 0.0f) {
            this->unk_15C -= 0.125f;
        }
    }

    if (this->timer < 8) {
        this->alpha = 0;
    }

    if (this->timer == 0) {
        this->timer = 255;
        Actor_Kill(&this->actor);
    }
}

void ArrowFire_Fly(ArrowFire* this, GlobalContext* globalCtx) {
    EnArrow* arrow;
    f32 distanceScaled;
    s32 pad;

    arrow = (EnArrow*)this->actor.attachedA;
    if ((arrow == NULL) || (arrow->actor.update == NULL)) {
        Actor_Kill(&this->actor);
        return;
    }
    if (this->startBombCount == AMMO(ITEM_BOMB)) {
        AMMO(ITEM_BOMB)--;
    }
    
    // copy position and rotation from the attached arrow
    this->actor.posRot.pos = arrow->actor.posRot.pos;
    this->actor.shape.rot = arrow->actor.shape.rot;
    distanceScaled = Math_Vec3f_DistXYZ(&this->unkPos, &this->actor.posRot.pos) * (1.0f / 24.0f);
    this->unk_158 = distanceScaled;
    if (distanceScaled < 1.0f) {
        this->unk_158 = 1.0f;
    }
    func_80865ECC(&this->unkPos, &this->actor.posRot.pos, 0.05f);

    if (arrow->hitWall & 1) {
        Audio_PlayActorSound2(&this->actor, NA_SE_IT_EXPLOSION_FRAME);
        ArrowFire_SetupAction(this, ArrowFire_Hit);
        this->timer = 32;
        this->alpha = 255;
    }
}

void ArrowFire_Update(Actor* thisx, GlobalContext* globalCtx) {
    ArrowFire* this = THIS;
    static Vec3f moveEff = { 0.0f, 0.0f, 32.0f };
    static Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    static Vec3f dustAccel = { 0.0f, 0.6f, 0.0f };
    static Color_RGBA8 sparkEnv = { 255, 255, 150, 255 };
    static Color_RGBA8 sparkPrim = { 255, 0, 0, 0 };
    static Color_RGBA8_n dustColor = { 255, 255, 255, 255 };
    Vec3f effPos;

    this->flashTimer++;

    Matrix_Translate(thisx->posRot.pos.x, thisx->posRot.pos.y, thisx->posRot.pos.z, MTXMODE_NEW);
    Matrix_RotateY(thisx->shape.rot.y * (360.0f / 65535.0f) * (M_PI / 180.0f), MTXMODE_APPLY);
    Matrix_RotateX(thisx->shape.rot.x * (360.0f / 65535.0f) * (M_PI / 180.0f), MTXMODE_APPLY);
    Matrix_MultVec3f(&moveEff, &effPos);
    effPos.y += 3.0f;

    if ((globalCtx->gameplayFrames % 2) == 0) {
        func_80029060(globalCtx, thisx, &effPos, &zeroVec, &zeroVec, &sparkEnv, &sparkPrim, 25, 5);
    }

    func_8002829C(globalCtx, &effPos, &zeroVec, &dustAccel, &dustColor, &dustColor, 25, 5);

    if (globalCtx->msgCtx.msgMode == 0xD || globalCtx->msgCtx.msgMode == 0x11) {
        Actor_Kill(&this->actor);
    } else {
        this->actionFunc(this, globalCtx);
    }

    if ((this->flashTimer & 8) != 0) {
        Math_SmoothScaleMaxMinF(&this->flashIntensity, 140.0f, 1.0f, 140.0f / 7, 0.0f);
    } else {
        Math_SmoothScaleMaxMinF(&this->flashIntensity, 0.0f, 1.0f, 140.0f / 7, 0.0f);
    }
}
extern Gfx D_04007860[];
extern Gfx D_04007A50[];

void ArrowFire_Draw(Actor* thisx, GlobalContext* globalCtx) {
    ArrowFire* this = THIS;
    GraphicsContext* gfxCtx;
    Gfx* dispRefs[4];

    if (this->actor.attachedA != NULL) {
        gfxCtx = globalCtx->state.gfxCtx;
        Graph_OpenDisps(dispRefs, globalCtx->state.gfxCtx, "../z_en_bom.c", 913);

        func_80093D18(globalCtx->state.gfxCtx);
        func_800D1FD4(&globalCtx->mf_11DA0);
        Matrix_Scale(0.35f, 0.35f, 0.35f, MTXMODE_APPLY);
        Matrix_Translate(50.0f, 50.0f, -2500.0f, MTXMODE_APPLY);

        // gold cap
        gSPMatrix(gfxCtx->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_bom.c", 928),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfxCtx->polyOpa.p++, D_04007A50);

        // bomb body
        Matrix_RotateRPY(0x4000, 0, 0, MTXMODE_APPLY);
        gSPMatrix(gfxCtx->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_bom.c", 934),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPPipeSync(gfxCtx->polyOpa.p++);
        gDPSetEnvColor(gfxCtx->polyOpa.p++, this->flashIntensity, 0, 40, 255);
        gDPSetPrimColor(gfxCtx->polyOpa.p++, 0, 0, this->flashIntensity, 0, 40, 255);
        gSPDisplayList(gfxCtx->polyOpa.p++, D_04007860);

        Graph_CloseDisps(dispRefs, globalCtx->state.gfxCtx, "../z_arrow_fire.c", 682);
    }
}
