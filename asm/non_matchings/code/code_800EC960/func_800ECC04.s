glabel func_800ECC04
/* B63DA4 800ECC04 3C028013 */  lui   $v0, %hi(D_8013170C) # $v0, 0x8013
/* B63DA8 800ECC08 9042170C */  lbu   $v0, %lo(D_8013170C)($v0)
/* B63DAC 800ECC0C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* B63DB0 800ECC10 AFA40028 */  sw    $a0, 0x28($sp)
/* B63DB4 800ECC14 240300FF */  li    $v1, 255
/* B63DB8 800ECC18 3084FFFF */  andi  $a0, $a0, 0xffff
/* B63DBC 800ECC1C 10620007 */  beq   $v1, $v0, .L800ECC3C
/* B63DC0 800ECC20 AFBF0014 */   sw    $ra, 0x14($sp)
/* B63DC4 800ECC24 308E0FFF */  andi  $t6, $a0, 0xfff
/* B63DC8 800ECC28 24010FFF */  li    $at, 4095
/* B63DCC 800ECC2C 15C10003 */  bne   $t6, $at, .L800ECC3C
/* B63DD0 800ECC30 00804025 */   move  $t0, $a0
/* B63DD4 800ECC34 35041000 */  ori   $a0, $t0, 0x1000
/* B63DD8 800ECC38 3084FFFF */  andi  $a0, $a0, 0xffff
.L800ECC3C:
/* B63DDC 800ECC3C 3401CFFF */  li    $at, 53247
/* B63DE0 800ECC40 14810005 */  bne   $a0, $at, .L800ECC58
/* B63DE4 800ECC44 00804025 */   move  $t0, $a0
/* B63DE8 800ECC48 50620004 */  beql  $v1, $v0, .L800ECC5C
/* B63DEC 800ECC4C 24010FFF */   li    $at, 4095
/* B63DF0 800ECC50 3404DFFF */  li    $a0, 57343
/* B63DF4 800ECC54 3408DFFF */  li    $t0, 57343
.L800ECC58:
/* B63DF8 800ECC58 24010FFF */  li    $at, 4095
.L800ECC5C:
/* B63DFC 800ECC5C 15010005 */  bne   $t0, $at, .L800ECC74
/* B63E00 800ECC60 2418000E */   li    $t8, 14
/* B63E04 800ECC64 50620004 */  beql  $v1, $v0, .L800ECC78
/* B63E08 800ECC68 3401FFFF */   li    $at, 65535
/* B63E0C 800ECC6C 24041FFF */  li    $a0, 8191
/* B63E10 800ECC70 24081FFF */  li    $t0, 8191
.L800ECC74:
/* B63E14 800ECC74 3401FFFF */  li    $at, 65535
.L800ECC78:
/* B63E18 800ECC78 11010048 */  beq   $t0, $at, .L800ECD9C
/* B63E1C 800ECC7C 3C028017 */   lui   $v0, %hi(D_8016BA2B) # $v0, 0x8017
/* B63E20 800ECC80 3C018000 */  lui   $at, 0x8000
/* B63E24 800ECC84 00817821 */  addu  $t7, $a0, $at
/* B63E28 800ECC88 3C018013 */  lui   $at, %hi(D_80130F3C) # $at, 0x8013
/* B63E2C 800ECC8C AC2F0F3C */  sw    $t7, %lo(D_80130F3C)($at)
/* B63E30 800ECC90 3C018017 */  lui   $at, %hi(D_8016BA2A) # $at, 0x8017
/* B63E34 800ECC94 A020BA2A */  sb    $zero, %lo(D_8016BA2A)($at)
/* B63E38 800ECC98 2442BA2B */  addiu $v0, %lo(D_8016BA2B) # addiu $v0, $v0, -0x45d5
/* B63E3C 800ECC9C 3401A000 */  li    $at, 40960
/* B63E40 800ECCA0 11010003 */  beq   $t0, $at, .L800ECCB0
/* B63E44 800ECCA4 A0580000 */   sb    $t8, ($v0)
/* B63E48 800ECCA8 2709FFFF */  addiu $t1, $t8, -1
/* B63E4C 800ECCAC A0490000 */  sb    $t1, ($v0)
.L800ECCB0:
/* B63E50 800ECCB0 310A3FFF */  andi  $t2, $t0, 0x3fff
/* B63E54 800ECCB4 3C018017 */  lui   $at, %hi(D_8016BA2C) # $at, 0x8017
/* B63E58 800ECCB8 A42ABA2C */  sh    $t2, %lo(D_8016BA2C)($at)
/* B63E5C 800ECCBC 3C018013 */  lui   $at, %hi(D_8013187C) # $at, 0x8013
/* B63E60 800ECCC0 240B0008 */  li    $t3, 8
/* B63E64 800ECCC4 A02B187C */  sb    $t3, %lo(D_8013187C)($at)
/* B63E68 800ECCC8 3C018017 */  lui   $at, %hi(D_8016BA29) # $at, 0x8017
/* B63E6C 800ECCCC A020BA29 */  sb    $zero, %lo(D_8016BA29)($at)
/* B63E70 800ECCD0 3C018013 */  lui   $at, %hi(D_80131878) # $at, 0x8013
/* B63E74 800ECCD4 A0201878 */  sb    $zero, %lo(D_80131878)($at)
/* B63E78 800ECCD8 3C018017 */  lui   $at, %hi(D_8016BA2E) # $at, 0x8017
/* B63E7C 800ECCDC A020BA2E */  sb    $zero, %lo(D_8016BA2E)($at)
/* B63E80 800ECCE0 0C03B2BC */  jal   func_800ECAF0
/* B63E84 800ECCE4 AFA8001C */   sw    $t0, 0x1c($sp)
/* B63E88 800ECCE8 3C018017 */  lui   $at, %hi(D_8016B9F9) # $at, 0x8017
/* B63E8C 800ECCEC A022B9F9 */  sb    $v0, %lo(D_8016B9F9)($at)
/* B63E90 800ECCF0 3C018013 */  lui   $at, %hi(D_80130F0C) # $at, 0x8013
/* B63E94 800ECCF4 240C0001 */  li    $t4, 1
/* B63E98 800ECCF8 A02C0F0C */  sb    $t4, %lo(D_80130F0C)($at)
/* B63E9C 800ECCFC 3C018013 */  lui   $at, %hi(D_80130F4C) # $at, 0x8013
/* B63EA0 800ECD00 3C078017 */  lui   $a3, %hi(D_8016BA90) # $a3, 0x8017
/* B63EA4 800ECD04 3C068017 */  lui   $a2, %hi(D_8016BA70) # $a2, 0x8017
/* B63EA8 800ECD08 3C058017 */  lui   $a1, %hi(D_8016BA50) # $a1, 0x8017
/* B63EAC 800ECD0C 3C048017 */  lui   $a0, %hi(D_8016BA30) # $a0, 0x8017
/* B63EB0 800ECD10 8FA8001C */  lw    $t0, 0x1c($sp)
/* B63EB4 800ECD14 A4200F4C */  sh    $zero, %lo(D_80130F4C)($at)
/* B63EB8 800ECD18 2484BA30 */  addiu $a0, %lo(D_8016BA30) # addiu $a0, $a0, -0x45d0
/* B63EBC 800ECD1C 24A5BA50 */  addiu $a1, %lo(D_8016BA50) # addiu $a1, $a1, -0x45b0
/* B63EC0 800ECD20 24C6BA70 */  addiu $a2, %lo(D_8016BA70) # addiu $a2, $a2, -0x4590
/* B63EC4 800ECD24 24E7BA90 */  addiu $a3, %lo(D_8016BA90) # addiu $a3, $a3, -0x4570
/* B63EC8 800ECD28 00001825 */  move  $v1, $zero
.L800ECD2C:
/* B63ECC 800ECD2C 00031040 */  sll   $v0, $v1, 1
/* B63ED0 800ECD30 00826821 */  addu  $t5, $a0, $v0
/* B63ED4 800ECD34 00E3C021 */  addu  $t8, $a3, $v1
/* B63ED8 800ECD38 24630001 */  addiu $v1, $v1, 1
/* B63EDC 800ECD3C A5A00000 */  sh    $zero, ($t5)
/* B63EE0 800ECD40 00A27021 */  addu  $t6, $a1, $v0
/* B63EE4 800ECD44 306300FF */  andi  $v1, $v1, 0xff
/* B63EE8 800ECD48 A5C00000 */  sh    $zero, ($t6)
/* B63EEC 800ECD4C 00C27821 */  addu  $t7, $a2, $v0
/* B63EF0 800ECD50 2861000E */  slti  $at, $v1, 0xe
/* B63EF4 800ECD54 A5E00000 */  sh    $zero, ($t7)
/* B63EF8 800ECD58 1420FFF4 */  bnez  $at, .L800ECD2C
/* B63EFC 800ECD5C A3000000 */   sb    $zero, ($t8)
/* B63F00 800ECD60 31198000 */  andi  $t9, $t0, 0x8000
/* B63F04 800ECD64 13200003 */  beqz  $t9, .L800ECD74
/* B63F08 800ECD68 31094000 */   andi  $t1, $t0, 0x4000
/* B63F0C 800ECD6C 3C018013 */  lui   $at, %hi(D_8013187C) # $at, 0x8013
/* B63F10 800ECD70 A020187C */  sb    $zero, %lo(D_8013187C)($at)
.L800ECD74:
/* B63F14 800ECD74 11200003 */  beqz  $t1, .L800ECD84
/* B63F18 800ECD78 310AD000 */   andi  $t2, $t0, 0xd000
/* B63F1C 800ECD7C 3C018017 */  lui   $at, %hi(D_8016BA28) # $at, 0x8017
/* B63F20 800ECD80 A020BA28 */  sb    $zero, %lo(D_8016BA28)($at)
.L800ECD84:
/* B63F24 800ECD84 5140000A */  beql  $t2, $zero, .L800ECDB0
/* B63F28 800ECD88 8FBF0014 */   lw    $ra, 0x14($sp)
/* B63F2C 800ECD8C 0C03B2DF */  jal   func_800ECB7C
/* B63F30 800ECD90 2404000C */   li    $a0, 12
/* B63F34 800ECD94 10000006 */  b     .L800ECDB0
/* B63F38 800ECD98 8FBF0014 */   lw    $ra, 0x14($sp)
.L800ECD9C:
/* B63F3C 800ECD9C 3C018013 */  lui   $at, %hi(D_80130F3C) # $at, 0x8013
/* B63F40 800ECDA0 AC200F3C */  sw    $zero, %lo(D_80130F3C)($at)
/* B63F44 800ECDA4 3C018013 */  lui   $at, %hi(D_80130F0C) # $at, 0x8013
/* B63F48 800ECDA8 A0200F0C */  sb    $zero, %lo(D_80130F0C)($at)
/* B63F4C 800ECDAC 8FBF0014 */  lw    $ra, 0x14($sp)
.L800ECDB0:
/* B63F50 800ECDB0 27BD0028 */  addiu $sp, $sp, 0x28
/* B63F54 800ECDB4 03E00008 */  jr    $ra
/* B63F58 800ECDB8 00000000 */   nop   

