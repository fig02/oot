glabel func_80B37038
/* 03388 80B37038 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 0338C 80B3703C AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 03390 80B37040 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 03394 80B37044 AFA5002C */  sw      $a1, 0x002C($sp)           
/* 03398 80B37048 90820315 */  lbu     $v0, 0x0315($a0)           ## 00000315
/* 0339C 80B3704C 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 033A0 80B37050 304E0080 */  andi    $t6, $v0, 0x0080           ## $t6 = 00000000
/* 033A4 80B37054 11C00009 */  beq     $t6, $zero, .L80B3707C     
/* 033A8 80B37058 304FFF7D */  andi    $t7, $v0, 0xFF7D           ## $t7 = 00000000
/* 033AC 80B3705C 90980435 */  lbu     $t8, 0x0435($a0)           ## 00000435
/* 033B0 80B37060 90880481 */  lbu     $t0, 0x0481($a0)           ## 00000481
/* 033B4 80B37064 A08F0315 */  sb      $t7, 0x0315($a0)           ## 00000315
/* 033B8 80B37068 3319FFFD */  andi    $t9, $t8, 0xFFFD           ## $t9 = 00000000
/* 033BC 80B3706C 3109FFFD */  andi    $t1, $t0, 0xFFFD           ## $t1 = 00000000
/* 033C0 80B37070 A0990435 */  sb      $t9, 0x0435($a0)           ## 00000435
/* 033C4 80B37074 1000005F */  beq     $zero, $zero, .L80B371F4   
/* 033C8 80B37078 A0890481 */  sb      $t1, 0x0481($a0)           ## 00000481
.L80B3707C:
/* 033CC 80B3707C 92040435 */  lbu     $a0, 0x0435($s0)           ## 00000435
/* 033D0 80B37080 30820002 */  andi    $v0, $a0, 0x0002           ## $v0 = 00000000
/* 033D4 80B37084 54400006 */  bnel    $v0, $zero, .L80B370A0     
/* 033D8 80B37088 8E0C02D4 */  lw      $t4, 0x02D4($s0)           ## 000002D4
/* 033DC 80B3708C 920A0481 */  lbu     $t2, 0x0481($s0)           ## 00000481
/* 033E0 80B37090 314B0002 */  andi    $t3, $t2, 0x0002           ## $t3 = 00000000
/* 033E4 80B37094 51600058 */  beql    $t3, $zero, .L80B371F8     
/* 033E8 80B37098 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 033EC 80B3709C 8E0C02D4 */  lw      $t4, 0x02D4($s0)           ## 000002D4
.L80B370A0:
/* 033F0 80B370A0 29810006 */  slti    $at, $t4, 0x0006           
/* 033F4 80B370A4 54200054 */  bnel    $at, $zero, .L80B371F8     
/* 033F8 80B370A8 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 033FC 80B370AC 860D008A */  lh      $t5, 0x008A($s0)           ## 0000008A
/* 03400 80B370B0 860E00B6 */  lh      $t6, 0x00B6($s0)           ## 000000B6
/* 03404 80B370B4 2605043C */  addiu   $a1, $s0, 0x043C           ## $a1 = 0000043C
/* 03408 80B370B8 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 0340C 80B370BC 01AE1823 */  subu    $v1, $t5, $t6              
/* 03410 80B370C0 00031C00 */  sll     $v1, $v1, 16               
/* 03414 80B370C4 14400005 */  bne     $v0, $zero, .L80B370DC     
/* 03418 80B370C8 00031C03 */  sra     $v1, $v1, 16               
/* 0341C 80B370CC 920F0481 */  lbu     $t7, 0x0481($s0)           ## 00000481
/* 03420 80B370D0 31F80002 */  andi    $t8, $t7, 0x0002           ## $t8 = 00000000
/* 03424 80B370D4 57000009 */  bnel    $t8, $zero, .L80B370FC     
/* 03428 80B370D8 921900B0 */  lbu     $t9, 0x00B0($s0)           ## 000000B0
.L80B370DC:
/* 0342C 80B370DC 04600003 */  bltz    $v1, .L80B370EC            
/* 03430 80B370E0 00031023 */  subu    $v0, $zero, $v1            
/* 03434 80B370E4 10000001 */  beq     $zero, $zero, .L80B370EC   
/* 03438 80B370E8 00601025 */  or      $v0, $v1, $zero            ## $v0 = 00000000
.L80B370EC:
/* 0343C 80B370EC 28414A39 */  slti    $at, $v0, 0x4A39           
/* 03440 80B370F0 54200006 */  bnel    $at, $zero, .L80B3710C     
/* 03444 80B370F4 920A0481 */  lbu     $t2, 0x0481($s0)           ## 00000481
/* 03448 80B370F8 921900B0 */  lbu     $t9, 0x00B0($s0)           ## 000000B0
.L80B370FC:
/* 0344C 80B370FC 92040435 */  lbu     $a0, 0x0435($s0)           ## 00000435
/* 03450 80B37100 00194080 */  sll     $t0, $t9,  2               
/* 03454 80B37104 A20800B0 */  sb      $t0, 0x00B0($s0)           ## 000000B0
/* 03458 80B37108 920A0481 */  lbu     $t2, 0x0481($s0)           ## 00000481
.L80B3710C:
/* 0345C 80B3710C 920200B1 */  lbu     $v0, 0x00B1($s0)           ## 000000B1
/* 03460 80B37110 3089FFFD */  andi    $t1, $a0, 0xFFFD           ## $t1 = 00000000
/* 03464 80B37114 24010006 */  addiu   $at, $zero, 0x0006         ## $at = 00000006
/* 03468 80B37118 314BFFFD */  andi    $t3, $t2, 0xFFFD           ## $t3 = 00000000
/* 0346C 80B3711C A2090435 */  sb      $t1, 0x0435($s0)           ## 00000435
/* 03470 80B37120 10410034 */  beq     $v0, $at, .L80B371F4       
/* 03474 80B37124 A20B0481 */  sb      $t3, 0x0481($s0)           ## 00000481
/* 03478 80B37128 A20202E6 */  sb      $v0, 0x02E6($s0)           ## 000002E6
/* 0347C 80B3712C 0C00D594 */  jal     Actor_SetDropFlag              
/* 03480 80B37130 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 03484 80B37134 920200B1 */  lbu     $v0, 0x00B1($s0)           ## 000000B1
/* 03488 80B37138 24010001 */  addiu   $at, $zero, 0x0001         ## $at = 00000001
/* 0348C 80B3713C A60002F8 */  sh      $zero, 0x02F8($s0)         ## 000002F8
/* 03490 80B37140 10410003 */  beq     $v0, $at, .L80B37150       
/* 03494 80B37144 2401000F */  addiu   $at, $zero, 0x000F         ## $at = 0000000F
/* 03498 80B37148 14410011 */  bne     $v0, $at, .L80B37190       
/* 0349C 80B3714C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B37150:
/* 034A0 80B37150 8E0C02D4 */  lw      $t4, 0x02D4($s0)           ## 000002D4
/* 034A4 80B37154 2401000F */  addiu   $at, $zero, 0x000F         ## $at = 0000000F
/* 034A8 80B37158 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 034AC 80B3715C 11810025 */  beq     $t4, $at, .L80B371F4       
/* 034B0 80B37160 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 034B4 80B37164 240D0050 */  addiu   $t5, $zero, 0x0050         ## $t5 = 00000050
/* 034B8 80B37168 AFAD0010 */  sw      $t5, 0x0010($sp)           
/* 034BC 80B3716C 24060078 */  addiu   $a2, $zero, 0x0078         ## $a2 = 00000078
/* 034C0 80B37170 0C00D09B */  jal     Actor_SetColorFilter              
/* 034C4 80B37174 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 034C8 80B37178 0C00D58A */  jal     Actor_ApplyDamage
              
/* 034CC 80B3717C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 034D0 80B37180 0C2CD746 */  jal     func_80B35D18              
/* 034D4 80B37184 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 034D8 80B37188 1000001B */  beq     $zero, $zero, .L80B371F8   
/* 034DC 80B3718C 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B37190:
/* 034E0 80B37190 240E0008 */  addiu   $t6, $zero, 0x0008         ## $t6 = 00000008
/* 034E4 80B37194 AFAE0010 */  sw      $t6, 0x0010($sp)           
/* 034E8 80B37198 24054000 */  addiu   $a1, $zero, 0x4000         ## $a1 = 00004000
/* 034EC 80B3719C 240600FF */  addiu   $a2, $zero, 0x00FF         ## $a2 = 000000FF
/* 034F0 80B371A0 0C00D09B */  jal     Actor_SetColorFilter              
/* 034F4 80B371A4 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 034F8 80B371A8 920F02E6 */  lbu     $t7, 0x02E6($s0)           ## 000002E6
/* 034FC 80B371AC 2401000E */  addiu   $at, $zero, 0x000E         ## $at = 0000000E
/* 03500 80B371B0 24180028 */  addiu   $t8, $zero, 0x0028         ## $t8 = 00000028
/* 03504 80B371B4 15E10002 */  bne     $t7, $at, .L80B371C0       
/* 03508 80B371B8 00000000 */  nop
/* 0350C 80B371BC A61802E4 */  sh      $t8, 0x02E4($s0)           ## 000002E4
.L80B371C0:
/* 03510 80B371C0 0C00D58A */  jal     Actor_ApplyDamage
              
/* 03514 80B371C4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 03518 80B371C8 14400008 */  bne     $v0, $zero, .L80B371EC     
/* 0351C 80B371CC 00000000 */  nop
/* 03520 80B371D0 0C2CDB23 */  jal     func_80B36C8C              
/* 03524 80B371D4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 03528 80B371D8 8FA4002C */  lw      $a0, 0x002C($sp)           
/* 0352C 80B371DC 0C00CB1F */  jal     Actor_PlayDeathFx              
/* 03530 80B371E0 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 03534 80B371E4 10000004 */  beq     $zero, $zero, .L80B371F8   
/* 03538 80B371E8 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B371EC:
/* 0353C 80B371EC 0C2CD793 */  jal     func_80B35E4C              
/* 03540 80B371F0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B371F4:
/* 03544 80B371F4 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B371F8:
/* 03548 80B371F8 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 0354C 80B371FC 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 03550 80B37200 03E00008 */  jr      $ra                        
/* 03554 80B37204 00000000 */  nop
