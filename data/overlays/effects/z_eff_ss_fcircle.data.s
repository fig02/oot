.include "macro.inc"

 # assembler directives
 .set noat      # allow manual use of $at
 .set noreorder # don't insert nops after branches
 .set gp=64     # allow use of 64-bit general purpose registers

.section .data

.balign 16

glabel Effect_Ss_Fcircle_InitVars
.word 0x0000001F
.word EffectSsFcircle_Init
.word 0x00000000, 0x00000000

