glabel func_800ECB34
/* B63CD4 800ECB34 AFA40000 */  sw    $a0, ($sp)
/* B63CD8 800ECB38 308400FF */  andi  $a0, $a0, 0xff
/* B63CDC 800ECB3C 308E003F */  andi  $t6, $a0, 0x3f
/* B63CE0 800ECB40 3C038013 */  lui   $v1, %hi(D_80131BF0)
/* B63CE4 800ECB44 006E1821 */  addu  $v1, $v1, $t6
/* B63CE8 800ECB48 90631BF0 */  lbu   $v1, %lo(D_80131BF0)($v1)
/* B63CEC 800ECB4C 24010005 */  li    $at, 5
/* B63CF0 800ECB50 308F0080 */  andi  $t7, $a0, 0x80
/* B63CF4 800ECB54 14610007 */  bne   $v1, $at, .L800ECB74
/* B63CF8 800ECB58 00601025 */   move  $v0, $v1
/* B63CFC 800ECB5C 11E00003 */  beqz  $t7, .L800ECB6C
/* B63D00 800ECB60 00000000 */   nop   
/* B63D04 800ECB64 03E00008 */  jr    $ra
/* B63D08 800ECB68 24020002 */   li    $v0, 2

.L800ECB6C:
/* B63D0C 800ECB6C 03E00008 */  jr    $ra
/* B63D10 800ECB70 24020003 */   li    $v0, 3

.L800ECB74:
/* B63D14 800ECB74 03E00008 */  jr    $ra
/* B63D18 800ECB78 00000000 */   nop   

