#include "z_demo_kankyo.h"
#include "z64cutscene_commands.h"

// clang-format off
CutsceneData gChildWarpInToTCS[] = {
    CS_HEADER(2, 1118),
    CS_CAM_EYE_SPLINE_REL_TO_PLAYER(0, 1089),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428EA647, 71.32476f), 53, 53, 40, 0x010F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 53, 53, 40, 0x0120),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 53, 53, 40, 0x0131),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D3328, 70.599915f), 58, 89, 47, 0x01F4),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D3328, 70.599915f), 58, 89, 47, 0x01F6),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D3328, 70.599915f), 58, 89, 47, 0x0207),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D3328, 70.599915f), 58, 89, 47, 0x0000),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x428D3328, 70.599915f), 58, 89, 47, 0x0000),
    CS_CAM_AT_SPLINE_REL_TO_PLAYER(0, 1118),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 7, CS_FLOAT(0x428D0CAF, 70.52477f), 11, 29, 10, 0x010F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 7, CS_FLOAT(0x428CCCC2, 70.39992f), 11, 29, 10, 0x0120),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 7, CS_FLOAT(0x428D3328, 70.599915f), 11, 29, 10, 0x0131),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 7, CS_FLOAT(0x428D3328, 70.599915f), 29, 58, 25, 0x01F4),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x428D3328, 70.599915f), 29, 58, 25, 0x01F6),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 1000, CS_FLOAT(0x428D3328, 70.599915f), 29, 58, 25, 0x0207),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x428D3328, 70.599915f), 29, 58, 25, 0x0000),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x428D3328, 70.599915f), 29, 58, 25, 0x0000),
    CS_STOP_PROCESSING(),
};
// clang-format on
