#ifndef _Z_EN_VASE_H_
#define _Z_EN_VASE_H_

#include "ultra64.h"
#include "global.h"

struct EnVase;

typedef void (*DorrieActionFunc)(struct EnVase*, GlobalContext*);

typedef struct EnVase {
    DynaPolyActor dyna;
    SkelAnime skelAnime;
    Vec3s jointTable[22];
    Vec3s morphTable[22];
    LightNode* lightNode;
    LightInfo lightInfo;
    s32 timer;
    s16 finAngle;
    DorrieActionFunc actionFunc;
    s32 state;
    ColliderCylinder collider;
    u8 introDone;
    s16 targetTurn;
} EnVase; // size = 0x014C

extern const ActorInit En_Vase_InitVars;

#endif
