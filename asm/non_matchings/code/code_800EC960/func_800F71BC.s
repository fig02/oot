glabel func_800F71BC
/* B6E35C 800F71BC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* B6E360 800F71C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* B6E364 800F71C4 240E0001 */  li    $t6, 1
/* B6E368 800F71C8 3C018013 */  lui   $at, %hi(D_80133418) # $at, 0x8013
/* B6E36C 800F71CC AFA40018 */  sw    $a0, 0x18($sp)
/* B6E370 800F71D0 0C03DB0D */  jal   func_800F6C34
/* B6E374 800F71D4 A02E3418 */   sb    $t6, %lo(D_80133418)($at)
/* B6E378 800F71D8 0C03BA4C */  jal   func_800EE930
/* B6E37C 800F71DC 00000000 */   nop   
/* B6E380 800F71E0 0C03CFB5 */  jal   func_800F3ED4
/* B6E384 800F71E4 00000000 */   nop   
/* B6E388 800F71E8 0C03EB7E */  jal   func_800FADF8
/* B6E38C 800F71EC 00000000 */   nop   
/* B6E390 800F71F0 0C03E417 */  jal   func_800F905C
/* B6E394 800F71F4 00000000 */   nop   
/* B6E398 800F71F8 8FBF0014 */  lw    $ra, 0x14($sp)
/* B6E39C 800F71FC 27BD0018 */  addiu $sp, $sp, 0x18
/* B6E3A0 800F7200 03E00008 */  jr    $ra
/* B6E3A4 800F7204 00000000 */   nop   

