#include "z_bg_toki_swd.h"
#include <z64cutscene_commands.h>

// clang-format off
CutsceneData D_808BBD90[] = {
    CS_BEGIN_CUTSCENE(11, 3000),
    CS_UNK_DATA_LIST(0x00000021, 1),
        CS_UNK_DATA(0x00010000, 0x0BB80000, 0x00000000, 0x00000000, 0xFFFFFFF8, 0xFFFFFFFF, 0x00000000, 0xFFFFFFF8, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000),
    CS_PLAYER_ACTION_LIST(3),
        CS_PLAYER_ACTION(0x0005, 0, 1, 0x0000, 0x8000, 0x0000, 0, 0, 820, 0, 0, 820, 0.0f, 0.0f, 1.4E-45f),
        CS_PLAYER_ACTION(0x0002, 1, 16, 0x0000, 0x8000, 0x0000, 0, 0, 820, 0, 0, 720, 0.0f, 0.0f, 1.4E-45f),
        CS_PLAYER_ACTION(0x0005, 16, 176, 0x0000, 0x8000, 0x0000, 0, 0, 720, 0, 0, 720, 0.0f, 0.0f, 1.4E-45f),
    CS_NPC_ACTION_LIST(62, 3),
        CS_NPC_ACTION(0x0004, 40, 70, 0x7D74, 0x0000, 0x0000, -1, 49, 719, 1, 47, 687, 0.06666667f, -0.06666667f, -0.06666667f),
        CS_NPC_ACTION(0x0004, 70, 220, 0x8010, 0x0000, 0x0000, 1, 47, 687, 0, 134, 21, -0.006666667f, 0.58f, 0.006666667f),
        CS_NPC_ACTION(0x0002, 220, 272, 0x8000, 0x0000, 0x0000, 0, 134, 21, 0, 101, 2, 0.0f, -0.63461536f, 0.0f),
    CS_MISC_LIST(1),
        CS_MISC(0x000C, 340, 341, 0x0000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFD, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFD, 0x00000000, 0x00000000, 0x00000000),
    CS_TEXT_LIST(6),
        CS_TEXT_NONE(0, 50),
        CS_TEXT_DISPLAY_TEXTBOX(0x70E6, 50, 60, 0x0000, 0x0000, 0x0000),
        CS_TEXT_NONE(60, 250),
        CS_TEXT_DISPLAY_TEXTBOX(0x70E7, 250, 260, 0x0000, 0x0000, 0x0000),
        CS_TEXT_NONE(260, 290),
        CS_TEXT_DISPLAY_TEXTBOX(0x70E8, 290, 320, 0x0000, 0x0000, 0x0000),
    CS_CAM_POS_LIST(0, 251),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -59, 12, 690, 0x0222),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -59, 12, 690, 0x00FA),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -59, 12, 690, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -59, 12, 690, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -59, 12, 690, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -31, 24, 701, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -31, 24, 701, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -31, 24, 701, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -31, 24, 701, 0x2D70),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -31, 24, 701, 0x0085),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -31, 24, 701, 0x01E6),
        CS_CAM_POS(CS_CMD_STOP, 0x00, 0, 60.0f, -31, 24, 701, 0x0000),
    CS_CAM_POS_LIST(90, 331),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -154, 92, 236, 0x0222),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -154, 92, 236, 0x00FA),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -154, 92, 236, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -154, 92, 236, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -154, 92, 236, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -154, 92, 236, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -154, 92, 236, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.0f, -154, 92, 236, 0x0000),
        CS_CAM_POS(CS_CMD_STOP, 0x00, 0, 60.0f, -154, 92, 236, 0x2D70),
    CS_CAM_POS_LIST(220, 491),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.000004f, -2, 122, 39, 0x0222),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.000004f, -2, 122, 39, 0x00FA),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.000004f, -2, 102, 39, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.000004f, -2, 90, 39, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.000004f, -2, 81, 62, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.000004f, -2, 81, 62, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.000004f, -2, 81, 62, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.000004f, -2, 81, 62, 0x0000),
        CS_CAM_POS(CS_CMD_CONTINUE, 0x00, 0, 60.000004f, -2, 81, 62, 0x2D70),
        CS_CAM_POS(CS_CMD_STOP, 0x00, 0, 60.000004f, -2, 81, 62, 0x0085),
    CS_CAM_FOCUS_POINT_LIST(0, 280),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, 43, 52, 716, 0x0222),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, 43, 52, 716, 0x00FA),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 10, 60.0f, 43, 52, 716, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 10, 60.0f, 43, 52, 716, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 10, 60.0f, 43, 52, 716, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 10, 60.0f, 63, 86, 722, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, 63, 86, 722, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, 63, 86, 722, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, 63, 86, 722, 0x2D70),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, 63, 85, 721, 0x0085),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, 63, 85, 721, 0x01E6),
        CS_CAM_FOCUS_POINT(CS_CMD_STOP, 0x00, 30, 60.0f, 62, 85, 721, 0x0000),
    CS_CAM_FOCUS_POINT_LIST(90, 360),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, -105, 83, 366, 0x0222),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, -104, 83, 364, 0x00FA),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, -63, 83, 339, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, -16, 99, 255, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, -30, 111, 177, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, -80, 112, 121, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, -80, 112, 121, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.0f, -80, 112, 121, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_STOP, 0x00, 30, 60.0f, -80, 112, 121, 0x2D70),
    CS_CAM_FOCUS_POINT_LIST(220, 520),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.000004f, 0, 137, -55, 0x0222),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.000004f, 0, 137, -55, 0x00FA),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.000004f, 0, 117, -55, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.000004f, 0, 105, -55, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.000004f, 0, 98, -31, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.000004f, 0, 98, -31, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.000004f, 0, 98, -31, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.000004f, 0, 98, -31, 0x0000),
        CS_CAM_FOCUS_POINT(CS_CMD_CONTINUE, 0x00, 30, 60.000004f, 0, 98, -31, 0x2D70),
        CS_CAM_FOCUS_POINT(CS_CMD_STOP, 0x00, 30, 60.000004f, 0, 98, -31, 0x0085),
    CS_END(),
};
// clang-format on
