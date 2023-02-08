/*
 * Input Delay Tester
 * I took over the game's sample gamestate to do this, which is why it says "sample" everywhere lol
 */

#include "global.h"

static Color_RGB8 sColors[] = {
    { 255, 255, 255 }, // white
    { 255, 0, 0 },     // red
    { 255, 127, 0 },   // orange
    { 255, 255, 0 },   // yellow
    { 0, 255, 0 },     // green
    { 0, 0, 255 },     // blue
    { 127, 0, 255 },   // purple
};

OSTime sGraphTimes[30];

void Sample_Update(SampleState* this) {
    Input* controller1 = &this->state.input[0];
    u32 triggerButtons = (BTN_A | BTN_B | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);
    u32 infoButtons = (BTN_L | BTN_R | BTN_Z);

    if (CHECK_BTN_ANY(controller1->press.button, triggerButtons)) {
        Audio_PlaySfxGeneral(NA_SE_IT_WALL_HIT_SOFT, &gSfxDefaultPos, 4, &gSfxDefaultFreqAndVolScale,
                             &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
        this->triggered = true;
    } else {
        this->triggered = false;
    }

    if (CHECK_BTN_ANY(controller1->press.button, infoButtons)) {
        this->showInfo ^= 1;
    }

    if (CHECK_BTN_ALL(controller1->press.button, BTN_START)) {
        this->color++;

        if (this->color >= ARRAY_COUNT(sColors)) {
            this->color = 0;
        }
    }

    if (this->showInfo) {
        s32 i;
        s32 numFrames = ARRAY_COUNT(sGraphTimes);
        OSTime avg = 0;

        this->frame++;
        this->frame %= numFrames;

        sGraphTimes[this->frame] = gGraphUpdatePeriod;

        for (i = 0; i < numFrames; i++) {
            avg += sGraphTimes[i];
        }

        avg /= numFrames;
        this->fps = 1 / (((f32)OS_CYCLES_TO_USEC(avg) / 1000.0f) / 1000.0f);
        
    }
}

void Sample_Draw(SampleState* this) {
    GraphicsContext* gfxCtx = this->state.gfxCtx;
    View* view = &this->view;

    if (this->triggered) {
        Color_RGB8* color = &sColors[this->color];
        Gfx_SetupFrame(gfxCtx, color->r, color->g, color->b);
    } else {
        Gfx_SetupFrame(gfxCtx, 0, 0, 0);
    }

    view->flags = VIEW_VIEWING | VIEW_VIEWPORT | VIEW_PROJECTION_PERSPECTIVE;
    View_Apply(view, VIEW_ALL);

    if (this->showInfo) {
        GfxPrint printer;

        OPEN_DISPS(gfxCtx, __FILE__, __LINE__);

        GfxPrint_Init(&printer);
        GfxPrint_Open(&printer, POLY_OPA_DISP);

        GfxPrint_SetColor(&printer, 255, 255, 255, 255);
        GfxPrint_SetPos(&printer, 7, 2);
        GfxPrint_Printf(&printer, "Input Delay Tester by Fig");

        GfxPrint_SetPos(&printer, 2, 7);
        GfxPrint_Printf(&printer, "FPS: %f", this->fps);

        GfxPrint_SetPos(&printer, 2, 20);
        GfxPrint_Printf(&printer, "A/B/C: Flash screen");

        GfxPrint_SetPos(&printer, 2, 22);
        GfxPrint_Printf(&printer, "L/R/Z: Toggle text display");

        GfxPrint_SetPos(&printer, 2, 24);
        GfxPrint_Printf(&printer, "Start: Change flash color");

        POLY_OPA_DISP = GfxPrint_Close(&printer);
        GfxPrint_Destroy(&printer);

        CLOSE_DISPS(gfxCtx, __FILE__, __LINE__);
    }
}

void Sample_Main(GameState* thisx) {
    SampleState* this = (SampleState*)thisx;

    Sample_Update(this);
    Sample_Draw(this);
}

void Sample_Destroy(GameState* thisx) {
}

void Sample_SetupView(SampleState* this) {
    View* view = &this->view;
    GraphicsContext* gfxCtx = this->state.gfxCtx;

    View_Init(view, gfxCtx);
    SET_FULLSCREEN_VIEWPORT(view);
    View_SetPerspective(view, 60.0f, 10.0f, 12800.0f);

    {
        Vec3f eye;
        Vec3f lookAt;
        Vec3f up;

        eye.x = 0.0f;
        eye.y = 0.0f;
        eye.z = 3000.0f;
        lookAt.x = 0.0f;
        lookAt.y = 0.0f;
        lookAt.z = 0.0f;
        up.x = 0.0f;
        up.z = 0.0f;
        up.y = 1.0f;

        View_LookAt(view, &eye, &lookAt, &up);
    }
}

void Sample_Init(GameState* thisx) {
    SampleState* this = (SampleState*)thisx;

    this->state.main = Sample_Main;
    this->state.destroy = Sample_Destroy;

    R_UPDATE_RATE = 1;
    Sample_SetupView(this);

    SEQCMD_RESET_AUDIO_HEAP(0, 10);

    this->color = 0;
    this->showInfo = true;
    this->frame = 0;
}
