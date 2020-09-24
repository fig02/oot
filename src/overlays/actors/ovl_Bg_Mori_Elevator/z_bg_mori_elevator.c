#include "z_bg_mori_elevator.h"

#define FLAGS 0x00000010

#define THIS ((BgMoriElevator*)thisx)

void BgMoriElevator_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMoriElevator_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMoriElevator_Update(Actor* thisx, GlobalContext* globalCtx);

void BgMoriElevator_SetupWaitAfterInit(BgMoriElevator* this);
void BgMoriElevator_WaitAfterInit(BgMoriElevator* this, GlobalContext* globalCtx);
void BgMoriElevator_SetupSetPosition(BgMoriElevator* this);
void BgMoriElevator_SetPosition(BgMoriElevator* this, GlobalContext* globalCtx);
void BgMoriElevator_Draw(Actor* thisx, GlobalContext* globalCtx);
void BgMoriElevator_StopMovement(BgMoriElevator* this);
void func_808A2008(BgMoriElevator* this, GlobalContext* globalCtx);
void BgMoriElevator_MoveIntoGround(BgMoriElevator* this, GlobalContext* globalCtx);
void BgMoriElevator_MoveAboveGround(BgMoriElevator* this, GlobalContext* globalCtx);

static s16 sIsSpawned = 0;

const ActorInit Bg_Mori_Elevator_InitVars = {
    ACTOR_BG_MORI_ELEVATOR,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriElevator),
    (ActorFunc)BgMoriElevator_Init,
    (ActorFunc)BgMoriElevator_Destroy,
    (ActorFunc)BgMoriElevator_Update,
    NULL,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 3000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

extern UNK_TYPE D_060035F8;
extern Gfx D_06002AD0[];

f32 func_808A1800(f32* pValue, f32 target, f32 scale, f32 maxStep, f32 minStep) {
    f32 var = (target - *pValue) * scale;

    if (*pValue < target) {
        if (maxStep < var) {
            var = maxStep;
        } else {
            if (var < minStep) {
                var = minStep;
            }
        }
        *pValue = (*pValue + var);

        if (target < *pValue) {
            *pValue = target;
        }
    } else {
        if (target < *pValue) {
            if (var < (-maxStep)) {
                var = (-maxStep);
            } else {
                if ((-minStep) < var) {
                    var = (-minStep);
                }
            }
            *pValue = (*pValue + var);
            if (*pValue < target) {
                *pValue = target;
            }
        } else {
            var = 0.0f;
        }
    }
    return var;
}

void func_808A18FC(BgMoriElevator* this, f32 distTo) {
    f32 temp;

    temp = fabsf(distTo) * 0.09f;
    func_800F436C(&this->dyna.actor.projectedPos, NA_SE_EV_ELEVATOR_MOVE2 - SFX_FLAG, CLAMP(temp, 0.0f, 1.0f));
}

void BgMoriElevator_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgMoriElevator* this = THIS;
    s32 pad;
    s32 localConst;
    localConst = 0;

    this->unk_172 = sIsSpawned;
    this->moriTexObjIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_TEX);
    if (this->moriTexObjIndex < 0) {
        Actor_Kill(thisx);
        // Forest Temple obj elevator Bank Danger!
        osSyncPrintf("Error : 森の神殿 obj elevator バンク危険！(%s %d)\n", "../z_bg_mori_elevator.c", 277);
    } else {
        switch (sIsSpawned) {
            case 0:
                // Forest Temple elevator CT
                osSyncPrintf("森の神殿 elevator CT\n");
                sIsSpawned = 1;
                this->dyna.actor.room = -1;
                Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
                DynaPolyInfo_SetActorMove(&this->dyna, DPM_PLAYER);
                DynaPolyInfo_Alloc(&D_060035F8, &localConst);
                this->dyna.dynaPolyId =
                    DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, thisx, localConst);
                BgMoriElevator_SetupWaitAfterInit(this);
                break;
            case 1:
                Actor_Kill(thisx);
                break;
        }
    }
}

void BgMoriElevator_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgMoriElevator* this = THIS;

    if (this->unk_172 == 0) {
        // Forest Temple elevator DT
        osSyncPrintf("森の神殿 elevator DT\n");
        DynaPolyInfo_Free(globalCtx, &globalCtx->colCtx.dyna, this->dyna.dynaPolyId);
        sIsSpawned = 0;
    }
}

s32 BgMoriElevator_IsPlayerRiding(BgMoriElevator* this, GlobalContext* globalCtx) {
    return ((this->dyna.unk_160 & 2) && !(this->unk_170 & 2) &&
            ((PLAYER->actor.posRot.pos.y - this->dyna.actor.posRot.pos.y) < 80.0f));
}

void BgMoriElevator_SetupWaitAfterInit(BgMoriElevator* this) {
    this->actionFunc = BgMoriElevator_WaitAfterInit;
}

void BgMoriElevator_WaitAfterInit(BgMoriElevator* this, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, this->moriTexObjIndex)) {
        if (Flags_GetSwitch(globalCtx, this->dyna.actor.params & 0x3F)) {
            if (globalCtx->roomCtx.curRoom.num == 2) {
                this->dyna.actor.posRot.pos.y = 73.0f;
                BgMoriElevator_SetupSetPosition(this);
            } else {
                // Error: Forest Temple obj elevator Room setting is dangerous
                osSyncPrintf("Error : 森の神殿 obj elevator 部屋設定が危険(%s %d)\n", "../z_bg_mori_elevator.c", 371);
            }
        } else {
            BgMoriElevator_SetupSetPosition(this);
        }
        this->dyna.actor.draw = BgMoriElevator_Draw;
    }
}

void func_808A1C30(BgMoriElevator* this) {
    this->actionFunc = BgMoriElevator_MoveIntoGround;
}

void BgMoriElevator_MoveIntoGround(BgMoriElevator* this, GlobalContext* globalCtx) {
    f32 distToTarget;

    func_808A1800(&this->dyna.actor.velocity.y, 2.0f, 0.05f, 1.0f, 0.0f);
    distToTarget = func_808A1800(&this->dyna.actor.posRot.pos.y, 73.0f, 0.08f, this->dyna.actor.velocity.y, 1.5f);
    if (fabsf(distToTarget) < 0.001f) {
        BgMoriElevator_SetupSetPosition(this);
        Audio_PlayActorSound2(&this->dyna.actor, NA_SE_EV_ELEVATOR_STOP);
    } else {
        func_808A18FC(this, distToTarget);
    }
}

void func_808A1CF4(BgMoriElevator* this, GlobalContext* globalCtx) {
    this->actionFunc = BgMoriElevator_MoveAboveGround;
    func_800800F8(globalCtx, 0xC9E, 0x46, &this->dyna.actor, 0);
    func_800800F8(globalCtx, 0x3FC, 0xF, &this->dyna.actor, 0);
}

void BgMoriElevator_MoveAboveGround(BgMoriElevator* this, GlobalContext* globalCtx) {
    f32 distToTarget;

    func_808A1800(&this->dyna.actor.velocity.y, 2.0f, 0.05f, 1.0f, 0.0f);
    distToTarget = func_808A1800(&this->dyna.actor.posRot.pos.y, 233.0f, 0.08f, this->dyna.actor.velocity.y, 1.5f);
    if (fabsf(distToTarget) < 0.001f) {
        BgMoriElevator_SetupSetPosition(this);
        Audio_PlayActorSound2(&this->dyna.actor, NA_SE_EV_ELEVATOR_STOP);
    } else {
        func_808A18FC(this, distToTarget);
    }
}

void BgMoriElevator_SetupSetPosition(BgMoriElevator* this) {
    this->actionFunc = BgMoriElevator_SetPosition;
}

void BgMoriElevator_SetPosition(BgMoriElevator* this, GlobalContext* globalCtx) {
    s32 pad;

    if (BgMoriElevator_IsPlayerRiding(this, globalCtx)) {
        if (globalCtx->roomCtx.curRoom.num == 2) {
            this->targetY = -779.0f;
            BgMoriElevator_StopMovement(this);
        } else if (globalCtx->roomCtx.curRoom.num == 17) {
            this->targetY = 233.0f;
            BgMoriElevator_StopMovement(this);
        } else {
            // Error:Forest Temple obj elevator Room setting is dangerous(% s % d)
            osSyncPrintf("Error : 森の神殿 obj elevator 部屋設定が危険(%s %d)\n", "../z_bg_mori_elevator.c", 479);
        }
    } else if ((globalCtx->roomCtx.curRoom.num == 2) && (this->dyna.actor.posRot.pos.y < -275.0f)) {
        this->targetY = 233.0f;
        BgMoriElevator_StopMovement(this);
    } else if ((globalCtx->roomCtx.curRoom.num == 17) && (-275.0f < this->dyna.actor.posRot.pos.y)) {
        this->targetY = -779.0f;
        BgMoriElevator_StopMovement(this);
    } else if ((globalCtx->roomCtx.curRoom.num == 2) && Flags_GetSwitch(globalCtx, this->dyna.actor.params & 0x3F) &&
               (this->unk_16C == 0)) {
        this->targetY = 73.0f;
        func_808A1C30(this);
    } else if ((globalCtx->roomCtx.curRoom.num == 2) && !Flags_GetSwitch(globalCtx, this->dyna.actor.params & 0x3F) &&
               (this->unk_16C != 0)) {
        this->targetY = 233.0f;
        func_808A1CF4(this, globalCtx);
    }
}

void BgMoriElevator_StopMovement(BgMoriElevator* this) {
    this->actionFunc = func_808A2008;
    this->dyna.actor.velocity.y = 0.0f;
}

void func_808A2008(BgMoriElevator* this, GlobalContext* globalCtx) {
    f32 distTo;

    func_808A1800(&this->dyna.actor.velocity.y, 12.0f, 0.1f, 1.0f, 0.0f);
    distTo = func_808A1800(&this->dyna.actor.posRot.pos.y, this->targetY, 0.1f, this->dyna.actor.velocity.y, 0.3f);
    if (fabsf(distTo) < 0.001f) {
        BgMoriElevator_SetupSetPosition(this);
        Audio_PlayActorSound2(&this->dyna.actor, NA_SE_EV_ELEVATOR_STOP);

    } else {
        func_808A18FC(this, distTo);
    }
}

void BgMoriElevator_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgMoriElevator* this = THIS;

    this->actionFunc(this, globalCtx);
    this->unk_170 = this->dyna.unk_160;
    this->unk_16C = Flags_GetSwitch(globalCtx, (thisx->params & 0x3F));
}

void BgMoriElevator_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriElevator* this = THIS;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_elevator.c", 575);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(oGfxCtx->polyOpa.p++, 0x08, globalCtx->objectCtx.status[this->moriTexObjIndex].segment);
    gSPMatrix(oGfxCtx->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_elevator.c", 580),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(oGfxCtx->polyOpa.p++, D_06002AD0);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_elevator.c", 584);
}
