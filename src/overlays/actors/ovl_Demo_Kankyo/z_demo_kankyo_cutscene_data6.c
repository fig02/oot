#include "z_demo_kankyo.h"
#include "z64cutscene_commands.h"

// clang-format off
CutsceneData gChildWarpOutCS[] = {
    CS_HEADER(5, 1167),
    CS_TRANSITION(CS_TRANS_GRAY_FILL_OUT, 36, 46),
    CS_TRANSITION(CS_TRANS_GRAY_FILL_IN, 30, 35),
    CS_CAM_EYE_SPLINE_REL_TO_PLAYER(0, 1138),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42714CA8, 60.32486f), 30, 63, 61, 0xA8A5),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42714CA8, 60.32486f), 30, 63, 61, 0xA3D9),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42714CA8, 60.32486f), 30, 63, 61, 0xF3A5),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42714CA9, 60.324863f), 29, 61, 59, 0xA5D5),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42714CA9, 60.324863f), 29, 61, 59, 0xA5E7),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42714CA9, 60.324863f), 29, 61, 59, 0xA5EC),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42714CA9, 60.324863f), 29, 61, 59, 0xBCA5),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x42714CA9, 60.324863f), 29, 61, 59, 0xEEC0),
    CS_CAM_AT_SPLINE_REL_TO_PLAYER(0, 1167),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42714CA8, 60.32486f), 54, 79, 31, 0xA8A5),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42714CA8, 60.32486f), 54, 80, 31, 0xA3D9),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 10, CS_FLOAT(0x42714CA8, 60.32486f), 54, 79, 31, 0xF3A5),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 7, CS_FLOAT(0x42714CA9, 60.324863f), 15, 42, 30, 0xA5D5),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42714CA9, 60.324863f), 15, 42, 30, 0xA5E7),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 1000, CS_FLOAT(0x42714CA9, 60.324863f), 15, 42, 30, 0xA5EC),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42714CA9, 60.324863f), 15, 42, 30, 0xBCA5),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x42714CA9, 60.324863f), 15, 42, 30, 0xEEC0),
    CS_MISC_LIST(1),
        CS_MISC(CS_MISC_STOP_CUTSCENE, 95, 96, 0x0000, 0x00000000, 0x00000000, 0xFFFFFFEF, 0xFFFFFFCD, 0x00000000, 0xFFFFFFEF, 0xFFFFFFCD, 0x00000000, 0x00000000, 0x00000000),
    CS_STOP_PROCESSING(),
};
// clang-format on
