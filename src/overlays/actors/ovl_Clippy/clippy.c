#include "clippy.h"
#include "assets/objects/object_gi_frog/object_gi_frog.h"

#define FLAGS 0

void Clippy_Init(Actor* thisx, PlayState* play);
void Clippy_Destroy(Actor* thisx, PlayState* play);
void Clippy_Update(Actor* thisx, PlayState* play);
void Clippy_Draw(Actor* thisx, PlayState* play);

void Clippy_WaitForObject(Clippy* this, PlayState* play);
void Clippy_Main(Clippy* this, PlayState* play);
void Clippy_Fall(Clippy* this, PlayState* play);

extern CollisionPoly* gClippyPoly;
extern u8 gClippyEnabled;

typedef enum { CLIPPY_STATE_SET_FLOOR, CLIPPY_STATE_TEST_GROUND_CLIP, CLIPPY_STATE_MOVE } ClippyState;

static u8 sSpawned = false;

const ActorInit Clippy_InitVars = {
    ACTOR_CLIPPY,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(Clippy),
    (ActorFunc)Clippy_Init,
    (ActorFunc)Clippy_Destroy,
    (ActorFunc)Clippy_Update,
    NULL,
};

void Clippy_UpdateBgCheckInfo(Clippy* this, PlayState* play, f32 sphereHeight) {
    Actor_UpdateBgCheckInfo(play, &this->actor, sphereHeight, 5.0f, 15.0f,
                            UPDBGCHECKINFO_FLAG_0 | UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_2 |
                                UPDBGCHECKINFO_FLAG_3 | UPDBGCHECKINFO_FLAG_4);
}

void Clippy_Init(Actor* thisx, PlayState* play) {
    Clippy* this = (Clippy*)thisx;
    s16 oldPermanent = play->objectCtx.unk_09;

    Actor_SetScale(&this->actor, 0.4f);

    if (sSpawned) {
        Actor_Kill(&this->actor);
        return;
    } else {
        sSpawned = true;
    }

    Object_Spawn(&play->objectCtx, OBJECT_GI_FROG);
    play->objectCtx.unk_09 = oldPermanent;
    this->tempObjIndex = Object_GetIndex(&play->objectCtx, OBJECT_GI_FROG);
    this->actionFunc = Clippy_WaitForObject;
}

void Clippy_WaitForObject(Clippy* this, PlayState* play) {
    if (Object_IsLoaded(&play->objectCtx, this->tempObjIndex)) {
        gSegments[6] = VIRTUAL_TO_PHYSICAL(play->objectCtx.status[this->tempObjIndex].segment);
        this->actor.objBankIndex = this->tempObjIndex;
        this->actor.gravity = -2.0f;
        ActorShape_Init(&this->actor.shape, 25.0f, ActorShadow_DrawCircle, 0.75f);
        this->actor.draw = Clippy_Draw;
        this->actionFunc = Clippy_Main;
    }
}

void Clippy_Main(Clippy* this, PlayState* play) {
    switch (this->state) {
        case CLIPPY_STATE_SET_FLOOR:
            Clippy_UpdateBgCheckInfo(this, play, 0.0f);
            gClippyPoly = this->actor.floorPoly;
            this->state = CLIPPY_STATE_TEST_GROUND_CLIP;
            break;

        case CLIPPY_STATE_TEST_GROUND_CLIP:
            osSyncPrintf("Testing for ground clip at { %f %f %f }", this->actor.world.pos.x, this->actor.world.pos.y,
                         this->actor.world.pos.z);

            this->actor.speedXZ = 4.0f;
            Actor_MoveForward(&this->actor);

            gClippyEnabled = true;
            Clippy_UpdateBgCheckInfo(this, play, 0.0f);
            gClippyEnabled = false;

            this->actor.world.pos = this->actor.prevPos;
            this->state = CLIPPY_STATE_MOVE;
            break;

        case CLIPPY_STATE_MOVE:
            this->actor.speedXZ = 0.5f;
            Actor_MoveForward(&this->actor);
            Clippy_UpdateBgCheckInfo(this, play, 50.0f);
            this->state = CLIPPY_STATE_SET_FLOOR;
            break;
    }
}

void Clippy_Fall(Clippy* this, PlayState* play) {
    Actor_MoveForward(&this->actor);
    Clippy_UpdateBgCheckInfo(this, play, 0.0f);

    if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND_TOUCH) {
        this->actionFunc = Clippy_Main;
    }
}

void Clippy_Destroy(Actor* thisx, PlayState* play) {
    Clippy* this = (Clippy*)thisx;
}

void Clippy_Update(Actor* thisx, PlayState* play) {
    Clippy* this = (Clippy*)thisx;

    if (Actor_HasParent(&this->actor, play)) {
        this->actionFunc = Clippy_Fall;
        this->actor.room = -1;
        this->actor.shape.shadowAlpha = 0;

    } else {
        this->actor.shape.shadowAlpha = 255;
        this->actionFunc(this, play);
        func_8002F580(&this->actor, play);
    }
}

void Clippy_Draw(Actor* thisx, PlayState* play) {
    Clippy* this = (Clippy*)thisx;

    func_8002EBCC(&this->actor, play, 0);
    func_8002ED80(&this->actor, play, 0);

    GetItem_Draw(play, GID_FROG);
}
