glabel func_80B9534C
/* 006AC 80B9534C 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 006B0 80B95350 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 006B4 80B95354 AFB10020 */  sw      $s1, 0x0020($sp)           
/* 006B8 80B95358 AFB0001C */  sw      $s0, 0x001C($sp)           
/* 006BC 80B9535C 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 006C0 80B95360 0C00BD04 */  jal     Actor_HasParent              
/* 006C4 80B95364 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 006C8 80B95368 50400006 */  beql    $v0, $zero, .L80B95384     
/* 006CC 80B9536C 960E0088 */  lhu     $t6, 0x0088($s0)           ## 00000088
/* 006D0 80B95370 0C2E5550 */  jal     func_80B95540              
/* 006D4 80B95374 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 006D8 80B95378 1000006D */  beq     $zero, $zero, .L80B95530   
/* 006DC 80B9537C 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 006E0 80B95380 960E0088 */  lhu     $t6, 0x0088($s0)           ## 00000088
.L80B95384:
/* 006E4 80B95384 3C014198 */  lui     $at, 0x4198                ## $at = 41980000
/* 006E8 80B95388 31CF0020 */  andi    $t7, $t6, 0x0020           ## $t7 = 00000000
/* 006EC 80B9538C 51E00017 */  beql    $t7, $zero, .L80B953EC     
/* 006F0 80B95390 92180161 */  lbu     $t8, 0x0161($s0)           ## 00000161
/* 006F4 80B95394 44812000 */  mtc1    $at, $f4                   ## $f4 = 19.00
/* 006F8 80B95398 C6060084 */  lwc1    $f6, 0x0084($s0)           ## 00000084
/* 006FC 80B9539C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00700 80B953A0 4606203C */  c.lt.s  $f4, $f6                   
/* 00704 80B953A4 00000000 */  nop
/* 00708 80B953A8 45020010 */  bc1fl   .L80B953EC                 
/* 0070C 80B953AC 92180161 */  lbu     $t8, 0x0161($s0)           ## 00000161
/* 00710 80B953B0 0C2E542E */  jal     func_80B950B8              
/* 00714 80B953B4 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 00718 80B953B8 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0071C 80B953BC 26050024 */  addiu   $a1, $s0, 0x0024           ## $a1 = 00000024
/* 00720 80B953C0 24060014 */  addiu   $a2, $zero, 0x0014         ## $a2 = 00000014
/* 00724 80B953C4 0C01AEB6 */  jal     Audio_PlaySoundAtPosition
              
/* 00728 80B953C8 240728AA */  addiu   $a3, $zero, 0x28AA         ## $a3 = 000028AA
/* 0072C 80B953CC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00730 80B953D0 0C2E5328 */  jal     func_80B94CA0              
/* 00734 80B953D4 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 00738 80B953D8 0C00B55C */  jal     Actor_Kill
              
/* 0073C 80B953DC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00740 80B953E0 10000053 */  beq     $zero, $zero, .L80B95530   
/* 00744 80B953E4 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00748 80B953E8 92180161 */  lbu     $t8, 0x0161($s0)           ## 00000161
.L80B953EC:
/* 0074C 80B953EC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00750 80B953F0 33190002 */  andi    $t9, $t8, 0x0002           ## $t9 = 00000000
/* 00754 80B953F4 1320000F */  beq     $t9, $zero, .L80B95434     
/* 00758 80B953F8 00000000 */  nop
/* 0075C 80B953FC 0C2E538E */  jal     func_80B94E38              
/* 00760 80B95400 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 00764 80B95404 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00768 80B95408 26050024 */  addiu   $a1, $s0, 0x0024           ## $a1 = 00000024
/* 0076C 80B9540C 24060014 */  addiu   $a2, $zero, 0x0014         ## $a2 = 00000014
/* 00770 80B95410 0C01AEB6 */  jal     Audio_PlaySoundAtPosition
              
/* 00774 80B95414 240728AA */  addiu   $a3, $zero, 0x28AA         ## $a3 = 000028AA
/* 00778 80B95418 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0077C 80B9541C 0C2E5328 */  jal     func_80B94CA0              
/* 00780 80B95420 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 00784 80B95424 0C00B55C */  jal     Actor_Kill
              
/* 00788 80B95428 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0078C 80B9542C 10000040 */  beq     $zero, $zero, .L80B95530   
/* 00790 80B95430 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B95434:
/* 00794 80B95434 0C00B638 */  jal     Actor_MoveForward
              
/* 00798 80B95438 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0079C 80B9543C 44804000 */  mtc1    $zero, $f8                 ## $f8 = 0.00
/* 007A0 80B95440 24080005 */  addiu   $t0, $zero, 0x0005         ## $t0 = 00000005
/* 007A4 80B95444 AFA80014 */  sw      $t0, 0x0014($sp)           
/* 007A8 80B95448 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 007AC 80B9544C 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 007B0 80B95450 3C064198 */  lui     $a2, 0x4198                ## $a2 = 41980000
/* 007B4 80B95454 3C0741A0 */  lui     $a3, 0x41A0                ## $a3 = 41A00000
/* 007B8 80B95458 0C00B92D */  jal     func_8002E4B4              
/* 007BC 80B9545C E7A80010 */  swc1    $f8, 0x0010($sp)           
/* 007C0 80B95460 92020162 */  lbu     $v0, 0x0162($s0)           ## 00000162
/* 007C4 80B95464 3C0141E0 */  lui     $at, 0x41E0                ## $at = 41E00000
/* 007C8 80B95468 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 007CC 80B9546C 30490008 */  andi    $t1, $v0, 0x0008           ## $t1 = 00000000
/* 007D0 80B95470 15200009 */  bne     $t1, $zero, .L80B95498     
/* 007D4 80B95474 26050150 */  addiu   $a1, $s0, 0x0150           ## $a1 = 00000150
/* 007D8 80B95478 44815000 */  mtc1    $at, $f10                  ## $f10 = 28.00
/* 007DC 80B9547C C6100090 */  lwc1    $f16, 0x0090($s0)          ## 00000090
/* 007E0 80B95480 344A0008 */  ori     $t2, $v0, 0x0008           ## $t2 = 00000008
/* 007E4 80B95484 4610503C */  c.lt.s  $f10, $f16                 
/* 007E8 80B95488 00000000 */  nop
/* 007EC 80B9548C 45020003 */  bc1fl   .L80B9549C                 
/* 007F0 80B95490 3C014416 */  lui     $at, 0x4416                ## $at = 44160000
/* 007F4 80B95494 A20A0162 */  sb      $t2, 0x0162($s0)           ## 00000162
.L80B95498:
/* 007F8 80B95498 3C014416 */  lui     $at, 0x4416                ## $at = 44160000
.L80B9549C:
/* 007FC 80B9549C 44819000 */  mtc1    $at, $f18                  ## $f18 = 600.00
/* 00800 80B954A0 C6000090 */  lwc1    $f0, 0x0090($s0)           ## 00000090
/* 00804 80B954A4 4612003C */  c.lt.s  $f0, $f18                  
/* 00808 80B954A8 00000000 */  nop
/* 0080C 80B954AC 45020017 */  bc1fl   .L80B9550C                 
/* 00810 80B954B0 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 00814 80B954B4 0C0189B7 */  jal     Collider_CylinderUpdate
              
/* 00818 80B954B8 AFA5002C */  sw      $a1, 0x002C($sp)           
/* 0081C 80B954BC 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 00820 80B954C0 34211E60 */  ori     $at, $at, 0x1E60           ## $at = 00011E60
/* 00824 80B954C4 02212821 */  addu    $a1, $s1, $at              
/* 00828 80B954C8 AFA50028 */  sw      $a1, 0x0028($sp)           
/* 0082C 80B954CC 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00830 80B954D0 0C01767D */  jal     CollisionCheck_SetAC
              ## CollisionCheck_setAC
/* 00834 80B954D4 8FA6002C */  lw      $a2, 0x002C($sp)           
/* 00838 80B954D8 3C014334 */  lui     $at, 0x4334                ## $at = 43340000
/* 0083C 80B954DC 44812000 */  mtc1    $at, $f4                   ## $f4 = 180.00
/* 00840 80B954E0 C6000090 */  lwc1    $f0, 0x0090($s0)           ## 00000090
/* 00844 80B954E4 8FA50028 */  lw      $a1, 0x0028($sp)           
/* 00848 80B954E8 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0084C 80B954EC 4604003C */  c.lt.s  $f0, $f4                   
/* 00850 80B954F0 00000000 */  nop
/* 00854 80B954F4 45020005 */  bc1fl   .L80B9550C                 
/* 00858 80B954F8 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 0085C 80B954FC 0C017713 */  jal     CollisionCheck_SetOC
              ## CollisionCheck_setOT
/* 00860 80B95500 8FA6002C */  lw      $a2, 0x002C($sp)           
/* 00864 80B95504 C6000090 */  lwc1    $f0, 0x0090($s0)           ## 00000090
/* 00868 80B95508 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
.L80B9550C:
/* 0086C 80B9550C 44813000 */  mtc1    $at, $f6                   ## $f6 = 100.00
/* 00870 80B95510 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00874 80B95514 4606003C */  c.lt.s  $f0, $f6                   
/* 00878 80B95518 00000000 */  nop
/* 0087C 80B9551C 45020004 */  bc1fl   .L80B95530                 
/* 00880 80B95520 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00884 80B95524 0C00BD60 */  jal     func_8002F580              
/* 00888 80B95528 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 0088C 80B9552C 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B95530:
/* 00890 80B95530 8FB0001C */  lw      $s0, 0x001C($sp)           
/* 00894 80B95534 8FB10020 */  lw      $s1, 0x0020($sp)           
/* 00898 80B95538 03E00008 */  jr      $ra                        
/* 0089C 80B9553C 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
