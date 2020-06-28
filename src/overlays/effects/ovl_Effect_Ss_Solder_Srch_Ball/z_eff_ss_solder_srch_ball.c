#include "z_eff_ss_solder_srch_ball.h"

f32 floorf(f32 x);

u32 EffSsSolderSrchBall_Init(GlobalContext* globalCtx, u32 index, EffectSs* this,
                             EffSsSolderSrchBallInitParams* initParams);
void EffSsSolderSrchBall_Update(GlobalContext* globalCtx, u32 index, EffectSs* this);
void EffSsSolderSrchBall_Draw(GlobalContext* globalCtx, u32 index, EffectSs* this);

EffectSsInit Effect_Ss_Solder_Srch_Ball_InitVars = {
    EFFECT_SS_SOLDER_SRCH_BALL,
    EffSsSolderSrchBall_Init,

};

u32 EffSsSolderSrchBall_Init(GlobalContext* globalCtx, u32 index, EffectSs* this,
                             EffSsSolderSrchBallInitParams* initParams) {
    this->pos = initParams->pos;
    this->velocity = initParams->velocity;
    this->accel = initParams->accel;
    this->update = EffSsSolderSrchBall_Update;
    this->draw = EffSsSolderSrchBall_Draw;
    this->life = 100;
    this->regs[1] = initParams->unk_24;
    this->unk_3C = initParams->seenLink;
    return 1;
}

void EffSsSolderSrchBall_Update(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    s32 pad;
    f32 playerPosDiffX;
    f32 playerPosDiffY;
    f32 playerPosDiffZ;
    s16* seenLink;
    Player* player = PLAYER;

    seenLink = this->unk_3C;

    playerPosDiffX = player->actor.posRot.pos.x - this->pos.x;
    playerPosDiffY = player->actor.posRot.pos.y - this->pos.y;
    playerPosDiffZ = player->actor.posRot.pos.z - this->pos.z;

    // if the ball does not hit a wall (something blocks it) and the ball is within 70 units of link, set seen to true
    if (!func_8003E30C(&globalCtx->colCtx, &this->pos, 30.0f)) {
        if (sqrtf(SQ(playerPosDiffX) + SQ(playerPosDiffY) + SQ(playerPosDiffZ)) < 70.0f) {
            *seenLink = true;
        }
    } else {
        if (this->life > 1) {
            this->life = 1;
        }
    }
}

static void vtxn_f2l(Vtx* r, Vec3f* v) {
    r->n.ob[0] = floorf(0.5f + v->x * 128.f);
    r->n.ob[1] = floorf(0.5f + v->y * 128.f);
    r->n.ob[2] = floorf(0.5f + v->z * 128.f);
    r->n.flag = 0;
    r->n.tc[0] = 0;
    r->n.tc[1] = 0;
    r->n.n[0] = v->x * 127.f;
    r->n.n[1] = v->y * 127.f;
    r->n.n[2] = v->z * 127.f;
    r->n.a = 0xFF;
}

static void ico_sph_subdivide_edge(Vec3f* r, Vec3f* a, Vec3f* b) {
    Math_Vec3f_Sum(a, b, r);
    Math_Vec3f_Scale(r, (1.0f / Math3D_Vec3fMagnitude(r)));
}

static void draw_ico_sphere(Gfx** p_gfx_p, Gfx** p_gfx_d, f32 x, f32 y, f32 z, f32 radius, GraphicsContext* gfxCtx) {
    static Gfx* p_sph_gfx = NULL;
    static Vtx sph_vtx[42];
    static Gfx sph_gfx[45];
    Gfx* sph_gfx_p;
    s32 i;

    if (!p_sph_gfx) {
        Vec3f vtx[42];
        s32 r0_n = 1, r0_m = r0_n / 5, r0_i = 0 + 0;
        s32 r1_n = 5, r1_m = r1_n / 5, r1_i = r0_i + r0_n;
        s32 r2_n = 10, r2_m = r2_n / 5, r2_i = r1_i + r1_n;
        s32 r3_n = 10, r3_m = r3_n / 5, r3_i = r2_i + r2_n;
        s32 r4_n = 10, r4_m = r4_n / 5, r4_i = r3_i + r3_n;
        s32 r5_n = 5, r5_m = r5_n / 5, r5_i = r4_i + r4_n;
        s32 r6_n = 1, r6_m = r6_n / 5, r6_i = r5_i + r5_n;

        vtx[r0_i + (0 * r0_m + 0) % r0_n].x = 0.0f;
        vtx[r0_i + (0 * r0_m + 0) % r0_n].y = 1.0f;
        vtx[r0_i + (0 * r0_m + 0) % r0_n].z = 0.0f;

        vtx[r6_i + (0 * r6_m + 0) % r6_n].x = 0.0f;
        vtx[r6_i + (0 * r6_m + 0) % r6_n].y = -1.0f;
        vtx[r6_i + (0 * r6_m + 0) % r6_n].z = 0.0f;

        for (i = 0; i < 5; ++i) {
            f32 a_xz = 2.f * M_PI / 10.f;
            f32 a_y = Math_atanf(1.f / 2.f);

            vtx[r2_i + (i * r2_m + 0) % r2_n].x = cosf(a_xz * (i * r2_m + 0)) * cosf(a_y * 1.f);
            vtx[r2_i + (i * r2_m + 0) % r2_n].y = sinf(a_y * 1.f);
            vtx[r2_i + (i * r2_m + 0) % r2_n].z = -sinf(a_xz * (i * r2_m + 0)) * cosf(a_y * 1.f);

            vtx[r4_i + (i * r4_m + 0) % r4_n].x = cosf(a_xz * (i * r4_m + 1)) * cosf(a_y * -1.f);
            vtx[r4_i + (i * r4_m + 0) % r4_n].y = sinf(a_y * -1.f);
            vtx[r4_i + (i * r4_m + 0) % r4_n].z = -sinf(a_xz * (i * r4_m + 1)) * cosf(a_y * -1.f);
        }
        for (i = 0; i < 5; ++i) {
            ico_sph_subdivide_edge(&vtx[r1_i + (i * r1_m + 0) % r1_n], &vtx[r0_i + (i * r0_m + 0) % r0_n],
                                   &vtx[r2_i + (i * r2_m + 0) % r2_n]);
            ico_sph_subdivide_edge(&vtx[r2_i + (i * r2_m + 1) % r2_n], &vtx[r2_i + (i * r2_m + 0) % r2_n],
                                   &vtx[r2_i + (i * r2_m + 2) % r2_n]);
            ico_sph_subdivide_edge(&vtx[r3_i + (i * r3_m + 0) % r3_n], &vtx[r2_i + (i * r2_m + 0) % r2_n],
                                   &vtx[r4_i + (i * r4_m + 0) % r4_n]);
            ico_sph_subdivide_edge(&vtx[r3_i + (i * r3_m + 1) % r3_n], &vtx[r4_i + (i * r4_m + 0) % r4_n],
                                   &vtx[r2_i + (i * r2_m + 2) % r2_n]);
            ico_sph_subdivide_edge(&vtx[r4_i + (i * r4_m + 1) % r4_n], &vtx[r4_i + (i * r4_m + 0) % r4_n],
                                   &vtx[r4_i + (i * r4_m + 2) % r4_n]);
            ico_sph_subdivide_edge(&vtx[r5_i + (i * r5_m + 0) % r5_n], &vtx[r4_i + (i * r4_m + 0) % r4_n],
                                   &vtx[r6_i + (i * r6_m + 0) % r6_n]);
        }

        for (i = 0; i < 42; ++i)
            vtxn_f2l(&sph_vtx[i], &vtx[i]);

        p_sph_gfx = sph_gfx;
        sph_gfx_p = p_sph_gfx;

        gSPSetGeometryMode(sph_gfx_p++, G_CULL_BACK | G_SHADING_SMOOTH);

        gSPVertex(sph_gfx_p++, &sph_vtx[r0_i], r0_n + r1_n + r2_n + r3_n, r0_i - r0_i);
        r3_i -= r0_i;
        r2_i -= r0_i;
        r1_i -= r0_i;
        r0_i -= r0_i;
        for (i = 0; i < 5; ++i) {
            s32 v[24];
            v[0] = r0_i + (i * r0_m + 0) % r0_n;
            v[1] = r1_i + (i * r1_m + 0) % r1_n;
            v[2] = r1_i + (i * r1_m + 1) % r1_n;
            v[3] = r1_i + (i * r1_m + 0) % r1_n;
            v[4] = r2_i + (i * r2_m + 0) % r2_n;
            v[5] = r2_i + (i * r2_m + 1) % r2_n;
            v[6] = r1_i + (i * r1_m + 0) % r1_n;
            v[7] = r2_i + (i * r2_m + 1) % r2_n;
            v[8] = r1_i + (i * r1_m + 1) % r1_n;
            v[9] = r1_i + (i * r1_m + 1) % r1_n;
            v[10] = r2_i + (i * r2_m + 1) % r2_n;
            v[11] = r2_i + (i * r2_m + 2) % r2_n;
            v[12] = r2_i + (i * r2_m + 0) % r2_n;
            v[13] = r3_i + (i * r3_m + 0) % r3_n;
            v[14] = r2_i + (i * r2_m + 1) % r2_n;
            v[15] = r2_i + (i * r2_m + 1) % r2_n;
            v[16] = r3_i + (i * r3_m + 0) % r3_n;
            v[17] = r3_i + (i * r3_m + 1) % r3_n;
            v[18] = r2_i + (i * r2_m + 1) % r2_n;
            v[19] = r3_i + (i * r3_m + 1) % r3_n;
            v[20] = r2_i + (i * r2_m + 2) % r2_n;
            v[21] = r2_i + (i * r2_m + 2) % r2_n;
            v[22] = r3_i + (i * r3_m + 1) % r3_n;
            v[23] = r3_i + (i * r3_m + 2) % r3_n;
            gSP2Triangles(sph_gfx_p++, v[0], v[1], v[2], 0, v[3], v[4], v[5], 0);
            gSP2Triangles(sph_gfx_p++, v[6], v[7], v[8], 0, v[9], v[10], v[11], 0);
            gSP2Triangles(sph_gfx_p++, v[12], v[13], v[14], 0, v[15], v[16], v[17], 0);
            gSP2Triangles(sph_gfx_p++, v[18], v[19], v[20], 0, v[21], v[22], v[23], 0);
        }

        gSPVertex(sph_gfx_p++, &sph_vtx[r4_i], r4_n + r5_n + r6_n, r4_i - r4_i);
        r6_i -= r4_i;
        r5_i -= r4_i;
        r4_i -= r4_i;
        for (i = 0; i < 5; ++i) {
            s32 v[24];
            v[0] = r3_i + (i * r3_m + 1) % r3_n;
            v[1] = r4_i + (i * r4_m + 0) % r4_n;
            v[2] = r4_i + (i * r4_m + 1) % r4_n;
            v[3] = r3_i + (i * r3_m + 1) % r3_n;
            v[4] = r4_i + (i * r4_m + 1) % r4_n;
            v[5] = r3_i + (i * r3_m + 2) % r3_n;
            v[6] = r3_i + (i * r3_m + 2) % r3_n;
            v[7] = r4_i + (i * r4_m + 1) % r4_n;
            v[8] = r4_i + (i * r4_m + 2) % r4_n;
            v[9] = r3_i + (i * r3_m + 2) % r3_n;
            v[10] = r4_i + (i * r4_m + 2) % r4_n;
            v[11] = r3_i + (i * r3_m + 3) % r3_n;
            v[12] = r4_i + (i * r4_m + 0) % r4_n;
            v[13] = r5_i + (i * r5_m + 0) % r5_n;
            v[14] = r4_i + (i * r4_m + 1) % r4_n;
            v[15] = r4_i + (i * r4_m + 1) % r4_n;
            v[16] = r5_i + (i * r5_m + 0) % r5_n;
            v[17] = r5_i + (i * r5_m + 1) % r5_n;
            v[18] = r4_i + (i * r4_m + 1) % r4_n;
            v[19] = r5_i + (i * r5_m + 1) % r5_n;
            v[20] = r4_i + (i * r4_m + 2) % r4_n;
            v[21] = r5_i + (i * r5_m + 0) % r5_n;
            v[22] = r6_i + (i * r6_m + 0) % r6_n;
            v[23] = r5_i + (i * r5_m + 1) % r5_n;
            gSP2Triangles(sph_gfx_p++, v[0], v[1], v[2], 0, v[3], v[4], v[5], 0);
            gSP2Triangles(sph_gfx_p++, v[6], v[7], v[8], 0, v[9], v[10], v[11], 0);
            gSP2Triangles(sph_gfx_p++, v[12], v[13], v[14], 0, v[15], v[16], v[17], 0);
            gSP2Triangles(sph_gfx_p++, v[18], v[19], v[20], 0, v[21], v[22], v[23], 0);
        }

        gSPClearGeometryMode(sph_gfx_p++, G_CULL_BACK | G_SHADING_SMOOTH);
        gSPEndDisplayList(sph_gfx_p++);
    }
    Matrix_Push();
    Matrix_Translate(x, y, z, MTXMODE_NEW);
    Matrix_Scale(radius / 128.f, radius / 128.f, radius / 128.f, MTXMODE_APPLY);
    gSPMatrix((*p_gfx_p)++, Matrix_NewMtx(gfxCtx, "file", 0), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
    gSPDisplayList((*p_gfx_p)++, p_sph_gfx);
    gSPPopMatrix((*p_gfx_p)++, G_MTX_MODELVIEW);
    Matrix_Pull();
}

void EffSsSolderSrchBall_Draw(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    u32 rm;
    u32 blc1;
    u32 blc2;
    u8 alpha;
    u32 gm;
    u8 xlu;
    Mtx* p_m;
    s16* seenLink = this->unk_3C;

    xlu = true;

    if (xlu) {
        rm = Z_CMP | IM_RD | CVG_DST_FULL | FORCE_BL;
        blc1 = GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA);
        blc2 = GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA);
        alpha = 0x80;
    } else {
        rm = Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | FORCE_BL;
        blc1 = GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1);
        blc2 = GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1);
        alpha = 0xFF;
    }

    if (xlu)
        rm |= ZMODE_XLU;
    else
        rm |= ZMODE_OPA;

    gm = G_ZBUFFER | G_SHADE | G_LIGHTING;

    gSPLoadGeometryMode(gfxCtx->polyXlu.p++, gm);
    gSPTexture(gfxCtx->polyXlu.p++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(gfxCtx->polyXlu.p++);
    gDPSetCycleType(gfxCtx->polyXlu.p++, G_CYC_1CYCLE);
    gDPSetRenderMode(gfxCtx->polyXlu.p++, rm | blc1, rm | blc2);
    gDPSetCombineLERP(gfxCtx->polyXlu.p++, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, PRIMITIVE, 0, SHADE, 0, 0, 0,
                      0, ENVIRONMENT);
    gDPSetPrimColor(gfxCtx->polyXlu.p++, 0, 0, 255, 255, 255, 255);
    if (*seenLink) {
        gDPSetPrimColor(gfxCtx->polyXlu.p++, 0, 0, 255, 0, 0, 255);
    }
    //gDPSetEnvColor(gfxCtx->polyXlu.p++, 0xFF, 0xFF, 0xFF, alpha);
    draw_ico_sphere(&gfxCtx->polyXlu.p, &gfxCtx->polyXlu.d, this->pos.x, this->pos.y, this->pos.z, 30.0f, gfxCtx);
}