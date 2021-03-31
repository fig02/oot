#include "global.h"
#include "alloca.h"

SeamInfo seam = {
    NULL,
    NULL,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    {0, 0, 0},
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
};

void Seams_DrawText(GlobalContext* globalCtx, Gfx** buf) {
    GfxPrint* printer = alloca(sizeof(GfxPrint));
    Player* player = PLAYER;

    GfxPrint_Init(printer);
    GfxPrint_Open(printer, *buf);
    GfxPrint_SetColor(printer, 255, 255, 255, 255);

    GfxPrint_SetPos(printer, 3, 8);
    GfxPrint_Printf(printer, "floor poly: %8X", seam.floor);

    GfxPrint_SetPos(printer, 3, 9);
    GfxPrint_Printf(printer, " wall poly: %8X", seam.wall);

    GfxPrint_SetPos(printer, 3, 10);
    GfxPrint_Printf(printer, "xzMovement: %d", seam.xzMovement);

    GfxPrint_SetPos(printer, 3, 11);
    GfxPrint_Printf(printer, "check2: %d", seam.check2);

    GfxPrint_SetPos(printer, 3, 12);
    GfxPrint_Printf(printer, "block2: %d", seam.block2);

    GfxPrint_SetPos(printer, 3, 13);
    GfxPrint_Printf(printer, "lineTest: %d", seam.lineTest);

    GfxPrint_SetPos(printer, 3, 14);
    GfxPrint_Printf(printer, "isNotFlat: %d", seam.isNotFlat);

    GfxPrint_SetPos(printer, 3, 15);
    GfxPrint_Printf(printer, "inStaticBox: %d", seam.inStaticBox);

    GfxPrint_SetPos(printer, 3, 16);
    GfxPrint_Printf(printer, "sphVsStaticWall: %d", seam.sphVsStaticWall);

    GfxPrint_SetPos(printer, 3, 17);
    GfxPrint_Printf(printer, "zIntersected: %d", seam.zIntersected);
    GfxPrint_SetPos(printer, 3, 18);
    GfxPrint_Printf(printer, "xIntersected: %d", seam.xIntersected);

    GfxPrint_SetPos(printer, 3, 19);
    GfxPrint_Printf(printer, "nxIsZero: %d", seam.nxIsZero);
    GfxPrint_SetPos(printer, 3, 20);
    GfxPrint_Printf(printer, "triCheck: %d", seam.triCheck);
    GfxPrint_SetPos(printer, 3, 21);
    GfxPrint_Printf(printer, "cirTriSq: %d", seam.cirTriSq);
    GfxPrint_SetPos(printer, 3, 22);
    GfxPrint_Printf(printer, "sqDistCheck: %d", seam.sqDistCheck);
    GfxPrint_SetPos(printer, 3, 23);
    GfxPrint_Printf(printer, "detCheck: %d", seam.detCheck);

    DrawSphere(globalCtx, &seam.sphCenter, 180, 0, 0, 18.0f);

    *buf = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);
}