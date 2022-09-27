#ifndef CLIPPY_H
#define CLIPPY_H

#include "ultra64.h"
#include "global.h"

struct Clippy;

typedef void (*ClippyActionFunc)(struct Clippy*, PlayState*);

typedef struct Clippy {
    Actor actor;
    ClippyActionFunc actionFunc;
    s16 tempObjIndex;
    u8 state;
} Clippy;

#endif
