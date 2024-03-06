#include "z_demo_im.h"
#include "z64cutscene_commands.h"

// clang-format off
static CutsceneData D_8098786C[] = {
    CS_HEADER(32, 3000),
    CS_UNK_DATA_LIST(0x00000020, 1),
        CS_UNK_DATA(0x00010000, 0x0BB80000, 0x00000000, 0x00000000, 0xFFFFFFFC, 0x00000002, 0x00000000, 0xFFFFFFFC, 0x00000002, 0x00000000, 0x00000000, 0x00000000),
    CS_ACTOR_CUE_LIST(31, 5),
        CS_ACTOR_CUE(0x0001, 0, 697, 0x0000, 0x0000, 0x0000, 0, 216, 0, 0, 216, 0, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
        CS_ACTOR_CUE(0x0002, 697, 698, 0x0000, 0x0000, 0x0000, 0, 216, 0, 0, 216, 0, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
        CS_ACTOR_CUE(0x0004, 698, 768, 0x0000, 0x0000, 0x0000, 0, 216, 0, 0, 216, 0, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
        CS_ACTOR_CUE(0x0002, 768, 817, 0x0000, 0x0000, 0x0000, 0, 216, 0, 0, 82, 0, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
        CS_ACTOR_CUE(0x0003, 817, 2666, 0x0000, 0x0000, 0x0000, 0, 82, 0, 0, 82, 0, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
    CS_PLAYER_CUE_LIST(3),
        CS_PLAYER_CUE(PLAYER_CUEID_13, 0, 300, 0x0000, 0x0000, 0x0000, 0, 6, 0, 0, 6, 0, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
        CS_PLAYER_CUE(PLAYER_CUEID_5, 300, 661, 0x0000, 0xEAAA, 0x0000, 0, 6, 0, 0, 6, 0, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
        CS_PLAYER_CUE(PLAYER_CUEID_19, 661, 1934, 0x0000, 0x6AAA, 0x0000, 0, 6, 0, 0, 6, 0, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
    CS_ACTOR_CUE_LIST(44, 3),
        CS_ACTOR_CUE(0x0001, 0, 145, 0x0000, 0x0000, 0x0000, -97, 6, 169, -97, 6, 169, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
        CS_ACTOR_CUE(0x0002, 145, 615, 0x0000, 0x0000, 0x0000, -97, 6, 169, -97, 6, 169, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
        CS_ACTOR_CUE(0x0003, 615, 1906, 0x0000, 0x0000, 0x0000, -97, 6, 169, -97, 6, 169, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
    CS_ACTOR_CUE_LIST(49, 1),
        CS_ACTOR_CUE(0x0001, 0, 3000, 0x0000, 0x0000, 0x0000, -22, 0, -55, -22, 0, -55, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
    CS_LIGHT_SETTING_LIST(2),
        CS_LIGHT_SETTING(0x0001, 0, 10, 0x0000, 0x00000000, 0xFFFFFFFE, 0x00000000, 0x0000000D, 0xFFFFFFFE, 0x00000000, 0x0000000D),
        CS_LIGHT_SETTING(0x0001, 10, 3000, 0x0000, 0x00000000, 0xFFFFFFFE, 0x00000000, 0x0000000D, 0xFFFFFFFE, 0x00000000, 0x0000000D),
    CS_TRANSITION(CS_TRANS_GRAY_FILL_OUT, 694, 724),
    CS_TRANSITION(CS_TRANS_GRAY_FILL_IN, 960, 990),
    CS_TRANSITION(CS_TRANS_GRAY_FILL_IN, 683, 692),
    CS_ACTOR_CUE_LIST(62, 2),
        CS_ACTOR_CUE(0x0001, 0, 10, 0x0000, 0x0000, 0x0000, 64, 80, 130, 64, 80, 130, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
        CS_ACTOR_CUE(0x0004, 10, 3000, 0x0000, 0x0000, 0x0000, 64, 80, 130, 64, 80, 130, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
    CS_START_SEQ_LIST(1),
        CS_START_SEQ(NA_BGM_MEDALLION_GET, 770, 771, 0x0000, 0x00000000, 0x00000000, 0xFFFFFFC9, 0x0000005C, 0x00000000, 0xFFFFFFC9, 0x0000005C),
    CS_TEXT_LIST(14),
        CS_TEXT_NONE(0, 340),
        CS_TEXT(0x5022, 340, 353, 0x0000, 0x0000, 0x0000),
        CS_TEXT_NONE(353, 374),
        CS_TEXT(0x5025, 374, 404, 0x0000, 0x0000, 0x0000),
        CS_TEXT_NONE(404, 424),
        CS_TEXT(0x502B, 424, 474, 0x0000, 0x0000, 0x0000),
        CS_TEXT_NONE(474, 494),
        CS_TEXT(0x502C, 494, 543, 0x0000, 0x0000, 0x0000),
        CS_TEXT_NONE(543, 564),
        CS_TEXT(0x5026, 564, 613, 0x0000, 0x0000, 0x0000),
        CS_TEXT_NONE(613, 955),
        CS_TEXT(0x0041, 955, 959, 0x0000, 0x0000, 0x0000),
        CS_TEXT_NONE(959, 1020),
        CS_TEXT(0x5023, 1020, 1029, 0x0000, 0x0000, 0x0000),
    CS_DESTINATION(CS_DEST_GRAVEYARD_FROM_CHAMBER_OF_SAGES, 1060, 1061),
    CS_FADE_OUT_SEQ_LIST(1),
        CS_FADE_OUT_SEQ(CS_FADE_OUT_BGM_MAIN, 673, 723, 0x0000, 0x00000000, 0x00000000, 0xFFFFFFC1, 0x00000058, 0x00000000, 0xFFFFFFC1, 0x00000058),
    CS_CAM_EYE_SPLINE(0, 341),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), 33, 225, -58, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), 33, 225, -58, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), 33, 225, -58, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), 33, 106, -58, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), 33, 23, -58, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), 11, 10, -18, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), 11, 10, -18, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), 11, 10, -18, 0xE6A0),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), 11, 10, -18, 0x7C53),
    CS_CAM_EYE_SPLINE(263, 504),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x41B50402, 22.626957f), -49, 13, 158, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x41B50402, 22.626957f), -49, 13, 158, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x41B50402, 22.626957f), -49, 13, 158, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x41B50402, 22.626957f), -21, 22, 150, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4204E872, 33.226997f), -21, 22, 150, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4204E872, 33.226997f), -21, 22, 150, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4204E872, 33.226997f), -21, 22, 150, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4204E872, 33.226997f), -21, 22, 150, 0xE6A0),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x4204E872, 33.226997f), -21, 22, 150, 0x7C53),
    CS_CAM_EYE_SPLINE(363, 824),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), -67, 8, 117, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), -67, 8, 117, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), -67, 8, 117, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), -67, 8, 117, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), -67, 8, 117, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42726667, 60.600002f), -67, 8, 117, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D998E, 70.79991f), -67, 8, 117, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D998E, 70.79991f), -67, 8, 117, 0xE6A0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D998E, 70.79991f), -67, 8, 117, 0x7C53),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D998E, 70.79991f), -67, 8, 117, 0x0000),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x428D998E, 70.79991f), -67, 8, 117, 0x0000),
    CS_CAM_EYE_SPLINE_REL_TO_PLAYER(413, 1504),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x419FFFB1, 19.99985f), -53, 28, 45, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x419FFFB1, 19.99985f), -53, 28, 45, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x419FFFB1, 19.99985f), -53, 28, 45, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x419FFFB1, 19.99985f), -53, 28, 45, 0x7C50),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x419FFFB1, 19.99985f), -53, 28, 45, 0x0000),
    CS_CAM_EYE_SPLINE(483, 1684),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289D68F, 68.91906f), -67, 8, 117, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289D68F, 68.91906f), -67, 8, 117, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289D68F, 68.91906f), -67, 8, 117, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289D68F, 68.91906f), -71, 15, 124, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289D68F, 68.91906f), -73, 29, 131, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289D68F, 68.91906f), -78, 40, 140, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289D68F, 68.91906f), -78, 40, 140, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289D68F, 68.91906f), -78, 40, 140, 0xE6A0),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x4289D68F, 68.91906f), -78, 40, 140, 0x7C53),
    CS_CAM_EYE_SPLINE(553, 1644),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42366658, 45.599945f), -39, 34, 201, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42366658, 45.599945f), -39, 34, 201, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42366658, 45.599945f), -39, 34, 201, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42366658, 45.599945f), -39, 34, 201, 0x7C50),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x42366658, 45.599945f), -39, 34, 201, 0x0000),
    CS_CAM_EYE_SPLINE(623, 819),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D3328, 70.599915f), 9, 13, -17, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D3328, 70.599915f), 9, 13, -17, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D3328, 70.599915f), 9, 13, -17, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x428D3328, 70.599915f), 9, 71, -17, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42FDFF84, 126.999054f), 9, 385, -17, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42FDFF84, 126.999054f), 9, 385, -17, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42FDFF84, 126.999054f), 9, 385, -17, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42FDFF84, 126.999054f), 9, 385, -17, 0xE6A0),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x42FDFF84, 126.999054f), 9, 385, -17, 0x7C53),
    CS_CAM_EYE_SPLINE(693, 1035),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 13, 854, 2, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 9, 853, 5, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -3, 853, 5, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -9, 853, -6, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -2, 852, -17, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 9, 852, -17, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 16, 852, -6, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 9, 852, 5, 0xE6A0),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -3, 851, 5, 0x7C53),
    CS_CAM_EYE_SPLINE_REL_TO_PLAYER(769, 1950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289332C, 68.599945f), 0, 33, -27, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289332C, 68.599945f), 0, 33, -27, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289332C, 68.599945f), 0, 68, -26, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289332C, 68.599945f), 0, 103, -26, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289332C, 68.599945f), 0, 103, -26, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289332C, 68.599945f), 0, 103, -26, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x4289332C, 68.599945f), 0, 103, -26, 0x0000),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x4289332C, 68.599945f), 0, 103, -26, 0xE6A0),
    CS_CAM_AT_SPLINE(0, 370),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42726667, 60.600002f), -21, 21, 42, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x42726667, 60.600002f), -21, 21, 42, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x42726667, 60.600002f), -21, 21, 42, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x42726667, 60.600002f), -78, 86, 144, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x42726667, 60.600002f), -80, 21, 142, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x42726667, 60.600002f), -99, 31, 177, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42726667, 60.600002f), -99, 31, 177, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42726667, 60.600002f), -99, 31, 177, 0xE6A0),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x42726667, 60.600002f), -99, 31, 177, 0x7C53),
    CS_CAM_AT_SPLINE(263, 533),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x41B50402, 22.626957f), -309, 11, 229, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x41B50402, 22.626957f), -309, 11, 229, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x41B50402, 22.626957f), -309, 11, 229, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4204E872, 33.226997f), -258, 133, 191, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4204E872, 33.226997f), -258, 133, 191, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4204E872, 33.226997f), -258, 133, 191, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4204E872, 33.226997f), -258, 133, 191, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4204E872, 33.226997f), -258, 133, 191, 0xE6A0),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x4204E872, 33.226997f), -258, 133, 191, 0x7C53),
    CS_CAM_AT_SPLINE(363, 853),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x42899992, 68.79994f), 68, 109, -103, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x4289FFF8, 68.99994f), 68, 109, -103, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x42899992, 68.79994f), 67, 109, -103, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x4289332C, 68.599945f), 189, 109, 92, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x4289332C, 68.599945f), 57, 108, 341, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x428D998E, 70.79991f), -186, 107, 341, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x428D998E, 70.79991f), -186, 107, 341, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x428D998E, 70.79991f), -186, 107, 341, 0xE6A0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x428D998E, 70.79991f), -186, 107, 341, 0x7C53),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x428D998E, 70.79991f), -186, 107, 341, 0x0000),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x428D998E, 70.79991f), -186, 107, 341, 0x0000),
    CS_CAM_AT_SPLINE_REL_TO_PLAYER(413, 1533),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x419FFFB1, 19.99985f), 171, 122, -106, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x419FFFB1, 19.99985f), 171, 122, -106, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 1000, CS_FLOAT(0x419FFFB1, 19.99985f), 171, 122, -106, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x419FFFB1, 19.99985f), 170, 122, -106, 0x7C50),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x419FFFB1, 19.99985f), 170, 122, -106, 0x0000),
    CS_CAM_AT_SPLINE(483, 1713),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x01, 20, CS_FLOAT(0x4289D68F, 68.91906f), -191, 132, 327, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x4289D68F, 68.91906f), -191, 132, 327, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0xFF, 30, CS_FLOAT(0x4289D68F, 68.91906f), -190, 131, 326, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 40, CS_FLOAT(0x4289D68F, 68.91906f), -189, 154, 324, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x01, 30, CS_FLOAT(0x4289D68F, 68.91906f), -194, 162, 331, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4289D68F, 68.91906f), -199, 172, 339, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 1000, CS_FLOAT(0x4289D68F, 68.91906f), -199, 172, 339, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4289D68F, 68.91906f), -199, 172, 339, 0xE6A0),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x4289D68F, 68.91906f), -199, 172, 339, 0x7C53),
    CS_CAM_AT_SPLINE(553, 1673),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42366658, 45.599945f), -234, 123, 37, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42366658, 45.599945f), -234, 123, 37, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 1000, CS_FLOAT(0x42366658, 45.599945f), -234, 123, 37, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42366658, 45.599945f), -234, 123, 37, 0x7C50),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x42366658, 45.599945f), -233, 123, 37, 0x0000),
    CS_CAM_AT_SPLINE(623, 848),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x428D3328, 70.599915f), -52, 17, 91, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x428D3328, 70.599915f), -52, 17, 91, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x428D3328, 70.599915f), -52, 17, 91, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 15, CS_FLOAT(0x428D3328, 70.599915f), -52, 75, 91, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 10, CS_FLOAT(0x42FDFF84, 126.999054f), -5, 503, 9, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42FDFF84, 126.999054f), -5, 503, 9, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42FDFF84, 126.999054f), -5, 503, 9, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42FDFF84, 126.999054f), -5, 503, 9, 0xE6A0),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x42FDFF84, 126.999054f), -5, 503, 9, 0x7C53),
    CS_CAM_AT_SPLINE(693, 1084),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x42700000, 60.0f), 3, 6, -6, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 40, CS_FLOAT(0x42700000, 60.0f), 3, 6, -6, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x424BFFF7, 50.999966f), 3, 6, -6, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x41A4CC7E, 20.59985f), 3, 6, -6, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 51, CS_FLOAT(0x412CCC23, 10.799838f), 3, 6, -6, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x412665BD, 10.399838f), 3, 6, -6, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x412665BD, 10.399838f), 3, 6, -6, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 50, CS_FLOAT(0x4123328A, 10.199839f), 3, 6, -6, 0xE6A0),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 50, CS_FLOAT(0x412FFF56, 10.999838f), 3, 6, -6, 0x7C53),
    CS_CAM_AT_SPLINE_REL_TO_PLAYER(769, 1979),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4289332C, 68.599945f), 0, 100, 5, 0x20BA),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4289332C, 68.599945f), 0, 101, 6, 0xD5E0),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4289332C, 68.599945f), 1, 99, 41, 0x0950),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4289332C, 68.599945f), 0, 42, 16, 0x7C50),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4289332C, 68.599945f), 0, 42, 16, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 1000, CS_FLOAT(0x4289332C, 68.599945f), 0, 42, 16, 0xFFFF),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x4289332C, 68.599945f), 0, 42, 16, 0x0000),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x4289332C, 68.599945f), 0, 42, 16, 0xE6A0),
    CS_STOP_PROCESSING(),
};
// clang-format on
