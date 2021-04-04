#include "global.h"

void Lib_MemSet(u8* dest, size_t size, u8 val) {
    u32 i;

    // clang-format off
    for (i = 0; i < size; i++) { *dest++ = val; }
    // clang-format on
}

f32 Math_CosS(s16 angle) {
    return coss(angle) * SHT_MINV;
}

f32 Math_SinS(s16 angle) {
    return sins(angle) * SHT_MINV;
}

/**
 * Changes pValue by step (scaled by the update rate) towards target, setting it equal when the target is reached.
 * Returns true when target is reached, false otherwise.
 */
s32 Math_ScaledStepToS(s16* pValue, s16 target, s16 step) {
    if (step != 0) {
        f32 updateScale = R_UPDATE_RATE * 0.5f;

        if ((s16)(*pValue - target) > 0) {
            step = -step;
        }

        *pValue += (s16)(step * updateScale);

        if (((s16)(*pValue - target) * step) >= 0) {
            *pValue = target;
            return true;
        }
    } else if (target == *pValue) {
        return true;
    }

    return false;
}

/**
 * Changes pValue by step towards target, setting it equal when the target is reached.
 * Returns true when target is reached, false otherwise.
 */
s32 Math_StepToS(s16* pValue, s16 target, s16 step) {
    if (step != 0) {
        if (target < *pValue) {
            step = -step;
        }

        *pValue += step;

        if (((*pValue - target) * step) >= 0) {
            *pValue = target;
            return true;
        }
    } else if (target == *pValue) {
        return true;
    }

    return false;
}

/**
 * Changes pValue by step towards target, setting it equal when the target is reached.
 * Returns true when target is reached, false otherwise.
 */
s32 Math_StepToF(f32* pValue, f32 target, f32 step) {
    if (step != 0.0f) {
        if (target < *pValue) {
            step = -step;
        }

        *pValue += step;

        if (((*pValue - target) * step) >= 0) {
            *pValue = target;
            return true;
        }
    } else if (target == *pValue) {
        return true;
    }

    return false;
}

/**
 *  Changes pValue by step. If pvalue reaches limit angle or its opposite, sets it equal to limit angle.
 * Returns true when limit angle or its opposite is reached, false otherwise.
 */
s32 Math_StepUntilAngleS(s16* pValue, s16 limit, s16 step) {
    s16 orig = *pValue;

    *pValue += step;

    if (((s16)(*pValue - limit) * (s16)(orig - limit)) <= 0) {
        *pValue = limit;
        return true;
    }

    return false;
}

/**
 * Changes pValue by step. If pvalue reaches limit, sets it equal to limit.
 * Returns true when limit is reached, false otherwise.
 */
s32 Math_StepUntilS(s16* pValue, s16 limit, s16 step) {
    s16 orig = *pValue;

    *pValue += step;

    if (((*pValue - limit) * (orig - limit)) <= 0) {
        *pValue = limit;
        return true;
    }

    return false;
}

/**
 * Changes pValue by step towards target angle, setting it equal when the target is reached.
 * Returns true when target is reached, false otherwise.
 */
s32 Math_StepToAngleS(s16* pValue, s16 target, s16 step) {
    s32 diff = target - *pValue;

    if (diff < 0) {
        step = -step;
    }

    if (diff >= 0x8000) {
        step = -step;
        diff = -0xFFFF - -diff;
    } else if (diff <= -0x8000) {
        diff += 0xFFFF;
        step = -step;
    }

    if (step != 0) {
        *pValue += step;

        if ((diff * step) <= 0) {
            *pValue = target;
            return true;
        }
    } else if (target == *pValue) {
        return true;
    }

    return false;
}

/**
 * Changes pValue by step. If pvalue reaches limit, sets it equal to limit.
 * Returns true when limit is reached, false otherwise.
 */
s32 Math_StepUntilF(f32* pValue, f32 limit, f32 step) {
    f32 orig = *pValue;

    *pValue += step;

    if (((*pValue - limit) * (orig - limit)) <= 0) {
        *pValue = limit;
        return true;
    }

    return false;
}

/**
 * Changes pValue toward target by incrStep if pValue is smaller and by decrStep if it is greater, setting it equal when
 * target is reached. Returns true when target is reached, false otherwise.
 */
s32 Math_AsymStepToF(f32* pValue, f32 target, f32 incrStep, f32 decrStep) {
    f32 step = (target >= *pValue) ? incrStep : decrStep;

    if (step != 0.0f) {
        if (target < *pValue) {
            step = -step;
        }

        *pValue += step;

        if (((*pValue - target) * step) >= 0) {
            *pValue = target;
            return 1;
        }
    } else if (target == *pValue) {
        return 1;
    }

    return 0;
}

void func_80077D10(f32* arg0, s16* arg1, Input* input) {
    f32 relX = input->rel.stick_x;
    f32 relY = input->rel.stick_y;

    *arg0 = sqrtf(SQ(relX) + SQ(relY));
    *arg0 = (60.0f < *arg0) ? 60.0f : *arg0;

    *arg1 = Math_Atan2S(relY, -relX);
}

s16 Rand_S16Offset(s16 base, s16 range) {
    return (s16)(Rand_ZeroOne() * range) + base;
}

s16 Rand_S16OffsetStride(s16 base, s16 stride, s16 range) {
    return (s16)(Rand_ZeroOne() * range) * stride + base;
}

void Math_Vec3f_Copy(Vec3f* dest, Vec3f* src) {
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
}

void Math_Vec3s_ToVec3f(Vec3f* dest, Vec3s* src) {
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
}

void Math_Vec3f_Sum(Vec3f* a, Vec3f* b, Vec3f* dest) {
    dest->x = a->x + b->x;
    dest->y = a->y + b->y;
    dest->z = a->z + b->z;
}

void Math_Vec3f_Diff(Vec3f* a, Vec3f* b, Vec3f* dest) {
    dest->x = a->x - b->x;
    dest->y = a->y - b->y;
    dest->z = a->z - b->z;
}

void Math_Vec3s_DiffToVec3f(Vec3f* dest, Vec3s* a, Vec3s* b) {
    dest->x = a->x - b->x;
    dest->y = a->y - b->y;
    dest->z = a->z - b->z;
}

void Math_Vec3f_Scale(Vec3f* vec, f32 scaleF) {
    vec->x *= scaleF;
    vec->y *= scaleF;
    vec->z *= scaleF;
}

f32 Math_Vec3f_DistXYZ(Vec3f* a, Vec3f* b) {
    f32 dx = b->x - a->x;
    f32 dy = b->y - a->y;
    f32 dz = b->z - a->z;

    return sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
}

f32 Math_Vec3f_DistXYZAndStoreDiff(Vec3f* a, Vec3f* b, Vec3f* dest) {
    dest->x = b->x - a->x;
    dest->y = b->y - a->y;
    dest->z = b->z - a->z;

    return sqrtf(SQ(dest->x) + SQ(dest->y) + SQ(dest->z));
}

f32 Math_Vec3f_DistXZ(Vec3f* a, Vec3f* b) {
    f32 dx = b->x - a->x;
    f32 dz = b->z - a->z;

    return sqrtf(SQ(dx) + SQ(dz));
}

f32 Math_Vec3f_DiffY(Vec3f* a, Vec3f* b) {
    return b->y - a->y;
}

s16 Math_Vec3f_Yaw(Vec3f* a, Vec3f* b) {
    f32 dx = b->x - a->x;
    f32 dz = b->z - a->z;

    return Math_Atan2S(dz, dx);
}

s16 Math_Vec3f_Pitch(Vec3f* a, Vec3f* b) {
    return Math_Atan2S(Math_Vec3f_DistXZ(a, b), a->y - b->y);
}

void IChain_Apply_u8(u8* ptr, InitChainEntry* ichain);
void IChain_Apply_s8(u8* ptr, InitChainEntry* ichain);
void IChain_Apply_u16(u8* ptr, InitChainEntry* ichain);
void IChain_Apply_s16(u8* ptr, InitChainEntry* ichain);
void IChain_Apply_u32(u8* ptr, InitChainEntry* ichain);
void IChain_Apply_s32(u8* ptr, InitChainEntry* ichain);
void IChain_Apply_f32(u8* ptr, InitChainEntry* ichain);
void IChain_Apply_f32div1000(u8* ptr, InitChainEntry* ichain);
void IChain_Apply_Vec3f(u8* ptr, InitChainEntry* ichain);
void IChain_Apply_Vec3fdiv1000(u8* ptr, InitChainEntry* ichain);
void IChain_Apply_Vec3s(u8* ptr, InitChainEntry* ichain);

void (*sInitChainHandlers[])(u8* ptr, InitChainEntry* ichain) = {
    IChain_Apply_u8,    IChain_Apply_s8,           IChain_Apply_u16,   IChain_Apply_s16,
    IChain_Apply_u32,   IChain_Apply_s32,          IChain_Apply_f32,   IChain_Apply_f32div1000,
    IChain_Apply_Vec3f, IChain_Apply_Vec3fdiv1000, IChain_Apply_Vec3s,
};

void Actor_ProcessInitChain(Actor* actor, InitChainEntry* ichain) {
    do {
        sInitChainHandlers[ichain->type]((u8*)actor, ichain);
    } while ((ichain++)->cont);
}

void IChain_Apply_u8(u8* ptr, InitChainEntry* ichain) {
    *(u8*)(ptr + ichain->offset) = ichain->value;
}

void IChain_Apply_s8(u8* ptr, InitChainEntry* ichain) {
    *(s8*)(ptr + ichain->offset) = ichain->value;
}

void IChain_Apply_u16(u8* ptr, InitChainEntry* ichain) {
    *(u16*)(ptr + ichain->offset) = ichain->value;
}

void IChain_Apply_s16(u8* ptr, InitChainEntry* ichain) {
    *(s16*)(ptr + ichain->offset) = ichain->value;
}

void IChain_Apply_u32(u8* ptr, InitChainEntry* ichain) {
    *(u32*)(ptr + ichain->offset) = ichain->value;
}

void IChain_Apply_s32(u8* ptr, InitChainEntry* ichain) {
    *(s32*)(ptr + ichain->offset) = ichain->value;
}

void IChain_Apply_f32(u8* ptr, InitChainEntry* ichain) {
    *(f32*)(ptr + ichain->offset) = ichain->value;
}

void IChain_Apply_f32div1000(u8* ptr, InitChainEntry* ichain) {
    *(f32*)(ptr + ichain->offset) = ichain->value / 1000.0f;
}

void IChain_Apply_Vec3f(u8* ptr, InitChainEntry* ichain) {
    Vec3f* vec = (Vec3f*)(ptr + ichain->offset);
    f32 val = ichain->value;

    vec->z = val;
    vec->y = val;
    vec->x = val;
}

void IChain_Apply_Vec3fdiv1000(u8* ptr, InitChainEntry* ichain) {
    Vec3f* vec = (Vec3f*)(ptr + ichain->offset);
    f32 val;

    osSyncPrintf("pp=%x data=%f\n", vec, ichain->value / 1000.0f);
    val = ichain->value / 1000.0f;

    vec->z = val;
    vec->y = val;
    vec->x = val;
}

void IChain_Apply_Vec3s(u8* ptr, InitChainEntry* ichain) {
    Vec3s* vec = (Vec3s*)(ptr + ichain->offset);
    s16 val = ichain->value;

    vec->z = val;
    vec->y = val;
    vec->x = val;
}

/**
 * Changes pValue by step towards target. If this step is more than fraction of the remaining distance, step by that
 * instead, with a minimum step of minStep. Returns remaining distance to target.
 */
f32 Math_SmoothStepToF(f32* pValue, f32 target, f32 fraction, f32 step, f32 minStep) {
    if (*pValue != target) {
        f32 stepSize = (target - *pValue) * fraction;

        if ((stepSize >= minStep) || (stepSize <= -minStep)) {
            if (stepSize > step) {
                stepSize = step;
            }

            if (stepSize < -step) {
                stepSize = -step;
            }

            *pValue += stepSize;
        } else {
            if (stepSize < minStep) {
                *pValue += minStep;
                stepSize = minStep;

                if (target < *pValue) {
                    *pValue = target;
                }
            }
            if (stepSize > -minStep) {
                *pValue += -minStep;

                if (*pValue < target) {
                    *pValue = target;
                }
            }
        }
    }

    return fabsf(target - *pValue);
}

/**
 * Changes pValue by step towards target. If step is more than fraction of the remaining distance, step by that instead.
 */
void Math_ApproachF(f32* pValue, f32 target, f32 fraction, f32 step) {
    if (*pValue != target) {
        f32 stepSize = (target - *pValue) * fraction;

        if (stepSize > step) {
            stepSize = step;
        } else if (stepSize < -step) {
            stepSize = -step;
        }

        *pValue += stepSize;
    }
}

/**
 * Changes pValue by step towards zero. If step is more than fraction of the remaining distance, step by that instead.
 */
void Math_ApproachZeroF(f32* pValue, f32 fraction, f32 step) {
    f32 stepSize = *pValue * fraction;

    if (stepSize > step) {
        stepSize = step;
    } else if (stepSize < -step) {
        stepSize = -step;
    }

    *pValue -= stepSize;
}

/**
 * Changes pValue by step towards target angle in degrees. If this step is more than fraction of the remaining distance,
 * step by that instead, with a minimum step of minStep. Returns the value of the step taken.
 */
f32 Math_SmoothStepToDegF(f32* pValue, f32 target, f32 fraction, f32 step, f32 minStep) {
    f32 stepSize = 0.0f;
    f32 diff = target - *pValue;

    if (*pValue != target) {
        if (diff > 180.0f) {
            diff = -(360.0f - diff);
        } else if (diff < -180.0f) {
            diff = 360.0f + diff;
        }

        stepSize = diff * fraction;

        if ((stepSize >= minStep) || (stepSize <= -minStep)) {
            if (stepSize > step) {
                stepSize = step;
            }

            if (stepSize < -step) {
                stepSize = -step;
            }

            *pValue += stepSize;
        } else {
            if (stepSize < minStep) {
                stepSize = minStep;
                *pValue += stepSize;
                if (*pValue > target) {
                    *pValue = target;
                }
            }
            if (stepSize > -minStep) {
                stepSize = -minStep;
                *pValue += stepSize;
                if (*pValue < target) {
                    *pValue = target;
                }
            }
        }
    }

    if (*pValue >= 360.0f) {
        *pValue -= 360.0f;
    }

    if (*pValue < 0.0f) {
        *pValue += 360.0f;
    }

    return stepSize;
}

/**
 * Changes pValue by step towards target. If this step is more than 1/scale of the remaining distance, step by that
 * instead, with a minimum step of minStep. Returns remaining distance to target.
 */
s16 Math_SmoothStepToS(s16* pValue, s16 target, s16 scale, s16 step, s16 minStep) {
    s16 stepSize = 0;
    s16 diff = target - *pValue;

    if (*pValue != target) {
        stepSize = diff / scale;

        if ((stepSize > minStep) || (stepSize < -minStep)) {
            if (stepSize > step) {
                stepSize = step;
            }

            if (stepSize < -step) {
                stepSize = -step;
            }

            *pValue += stepSize;
        } else {
            if (diff >= 0) {
                *pValue += minStep;

                if ((s16)(target - *pValue) <= 0) {
                    *pValue = target;
                }
            } else {
                *pValue -= minStep;

                if ((s16)(target - *pValue) >= 0) {
                    *pValue = target;
                }
            }
        }
    }

    return diff;
}

/**
 * Changes pValue by step towards target. If step is more than 1/scale of the remaining distance, step by that instead.
 */
void Math_ApproachS(s16* pValue, s16 target, s16 scale, s16 maxStep) {
    s16 diff = target - *pValue;

    diff /= scale;

    if (diff > maxStep) {
        *pValue += maxStep;
    } else if (diff < -maxStep) {
        *pValue -= maxStep;
    } else {
        *pValue += diff;
    }
}

void Color_RGBA8_Copy(Color_RGBA8* dst, Color_RGBA8* src) {
    dst->r = src->r;
    dst->g = src->g;
    dst->b = src->b;
    dst->a = src->a;
}

void func_80078884(u16 sfxId) {
    Audio_PlaySoundGeneral(sfxId, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_800788CC(u16 sfxId) {
    Audio_PlaySoundGeneral(sfxId, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_80078914(Vec3f* arg0, u16 sfxId) {
    Audio_PlaySoundGeneral(sfxId, arg0, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

// =================

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
            f32 a_y = Math_FAtanF(1.f / 2.f);

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
    Matrix_Pop();
}

void DrawSphere(GlobalContext* globalCtx, Vec3f* pos, u8 r, u8 g, u8 b, f32 radius) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    u32 rm;
    u32 blc1;
    u32 blc2;
    u8 alpha;
    u32 gm;
    u8 xlu;
    Mtx* p_m;
    xlu = false;

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
    if(seam.sphVsStaticWall) {
        r = 255;
        g = 0;
        b = 0;
    } else {
        r = 255;
        g = 255;
        b = 255;
    }
    gDPSetPrimColor(gfxCtx->polyXlu.p++, 0, 0, r, g, b, 255);

    draw_ico_sphere(&gfxCtx->polyXlu.p, &gfxCtx->polyXlu.d, pos->x, pos->y, pos->z, radius, gfxCtx);
}