
a.out:     file format elf64-x86-64


Disassembly of section .interp:

0000000000000318 <.interp>:
 318:	2f                   	(bad)
 319:	6c                   	insb   (%dx),%es:(%rdi)
 31a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
 321:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
 326:	78 2d                	js     355 <__abi_tag-0x37>
 328:	78 38                	js     362 <__abi_tag-0x2a>
 32a:	36 2d 36 34 2e 73    	ss sub $0x732e3436,%eax
 330:	6f                   	outsl  %ds:(%rsi),(%dx)
 331:	2e 32 00             	cs xor (%rax),%al

Disassembly of section .note.gnu.property:

0000000000000338 <.note.gnu.property>:
 338:	04 00                	add    $0x0,%al
 33a:	00 00                	add    %al,(%rax)
 33c:	20 00                	and    %al,(%rax)
 33e:	00 00                	add    %al,(%rax)
 340:	05 00 00 00 47       	add    $0x47000000,%eax
 345:	4e 55                	rex.WRX push %rbp
 347:	00 02                	add    %al,(%rdx)
 349:	00 00                	add    %al,(%rax)
 34b:	c0 04 00 00          	rolb   $0x0,(%rax,%rax,1)
 34f:	00 03                	add    %al,(%rbx)
 351:	00 00                	add    %al,(%rax)
 353:	00 00                	add    %al,(%rax)
 355:	00 00                	add    %al,(%rax)
 357:	00 02                	add    %al,(%rdx)
 359:	80 00 c0             	addb   $0xc0,(%rax)
 35c:	04 00                	add    $0x0,%al
 35e:	00 00                	add    %al,(%rax)
 360:	01 00                	add    %eax,(%rax)
 362:	00 00                	add    %al,(%rax)
 364:	00 00                	add    %al,(%rax)
	...

Disassembly of section .note.gnu.build-id:

0000000000000368 <.note.gnu.build-id>:
 368:	04 00                	add    $0x0,%al
 36a:	00 00                	add    %al,(%rax)
 36c:	14 00                	adc    $0x0,%al
 36e:	00 00                	add    %al,(%rax)
 370:	03 00                	add    (%rax),%eax
 372:	00 00                	add    %al,(%rax)
 374:	47                   	rex.RXB
 375:	4e 55                	rex.WRX push %rbp
 377:	00 70 a9             	add    %dh,-0x57(%rax)
 37a:	42 34 3e             	rex.X xor $0x3e,%al
 37d:	75 dd                	jne    35c <__abi_tag-0x30>
 37f:	bf 80 3f f3 ea       	mov    $0xeaf33f80,%edi
 384:	e8 2c 02 be 8b       	call   ffffffff8bbe05b5 <_end+0xffffffff8bbdc59d>
 389:	dc cf                	fmul   %st,%st(7)
 38b:	9d                   	popf

Disassembly of section .note.ABI-tag:

000000000000038c <__abi_tag>:
 38c:	04 00                	add    $0x0,%al
 38e:	00 00                	add    %al,(%rax)
 390:	10 00                	adc    %al,(%rax)
 392:	00 00                	add    %al,(%rax)
 394:	01 00                	add    %eax,(%rax)
 396:	00 00                	add    %al,(%rax)
 398:	47                   	rex.RXB
 399:	4e 55                	rex.WRX push %rbp
 39b:	00 00                	add    %al,(%rax)
 39d:	00 00                	add    %al,(%rax)
 39f:	00 03                	add    %al,(%rbx)
 3a1:	00 00                	add    %al,(%rax)
 3a3:	00 02                	add    %al,(%rdx)
 3a5:	00 00                	add    %al,(%rax)
 3a7:	00 00                	add    %al,(%rax)
 3a9:	00 00                	add    %al,(%rax)
	...

Disassembly of section .gnu.hash:

00000000000003b0 <.gnu.hash>:
 3b0:	02 00                	add    (%rax),%al
 3b2:	00 00                	add    %al,(%rax)
 3b4:	06                   	(bad)
 3b5:	00 00                	add    %al,(%rax)
 3b7:	00 01                	add    %al,(%rcx)
 3b9:	00 00                	add    %al,(%rax)
 3bb:	00 06                	add    %al,(%rsi)
 3bd:	00 00                	add    %al,(%rax)
 3bf:	00 00                	add    %al,(%rax)
 3c1:	00 81 00 00 00 00    	add    %al,0x0(%rcx)
 3c7:	00 06                	add    %al,(%rsi)
 3c9:	00 00                	add    %al,(%rax)
 3cb:	00 00                	add    %al,(%rax)
 3cd:	00 00                	add    %al,(%rax)
 3cf:	00 d1                	add    %dl,%cl
 3d1:	65 ce                	gs (bad)
 3d3:	6d                   	insl   (%dx),%es:(%rdi)

Disassembly of section .dynsym:

00000000000003d8 <.dynsym>:
	...
 3f0:	12 00                	adc    (%rax),%al
 3f2:	00 00                	add    %al,(%rax)
 3f4:	12 00                	adc    (%rax),%al
	...
 406:	00 00                	add    %al,(%rax)
 408:	5e                   	pop    %rsi
 409:	00 00                	add    %al,(%rax)
 40b:	00 20                	add    %ah,(%rax)
	...
 41d:	00 00                	add    %al,(%rax)
 41f:	00 01                	add    %al,(%rcx)
 421:	00 00                	add    %al,(%rax)
 423:	00 12                	add    %dl,(%rdx)
	...
 435:	00 00                	add    %al,(%rax)
 437:	00 7a 00             	add    %bh,0x0(%rdx)
 43a:	00 00                	add    %al,(%rax)
 43c:	20 00                	and    %al,(%rax)
	...
 44e:	00 00                	add    %al,(%rax)
 450:	89 00                	mov    %eax,(%rax)
 452:	00 00                	add    %al,(%rax)
 454:	20 00                	and    %al,(%rax)
	...
 466:	00 00                	add    %al,(%rax)
 468:	24 00                	and    $0x0,%al
 46a:	00 00                	add    %al,(%rax)
 46c:	22 00                	and    (%rax),%al
	...

Disassembly of section .dynstr:

0000000000000480 <.dynstr>:
 480:	00 5f 5f             	add    %bl,0x5f(%rdi)
 483:	73 74                	jae    4f9 <__abi_tag+0x16d>
 485:	61                   	(bad)
 486:	63 6b 5f             	movsxd 0x5f(%rbx),%ebp
 489:	63 68 6b             	movsxd 0x6b(%rax),%ebp
 48c:	5f                   	pop    %rdi
 48d:	66 61                	data16 (bad)
 48f:	69 6c 00 5f 5f 6c 69 	imul   $0x62696c5f,0x5f(%rax,%rax,1),%ebp
 496:	62 
 497:	63 5f 73             	movsxd 0x73(%rdi),%ebx
 49a:	74 61                	je     4fd <__abi_tag+0x171>
 49c:	72 74                	jb     512 <__abi_tag+0x186>
 49e:	5f                   	pop    %rdi
 49f:	6d                   	insl   (%dx),%es:(%rdi)
 4a0:	61                   	(bad)
 4a1:	69 6e 00 5f 5f 63 78 	imul   $0x78635f5f,0x0(%rsi),%ebp
 4a8:	61                   	(bad)
 4a9:	5f                   	pop    %rdi
 4aa:	66 69 6e 61 6c 69    	imul   $0x696c,0x61(%rsi),%bp
 4b0:	7a 65                	jp     517 <__abi_tag+0x18b>
 4b2:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
 4b6:	63 2e                	movsxd (%rsi),%ebp
 4b8:	73 6f                	jae    529 <__abi_tag+0x19d>
 4ba:	2e 36 00 47 4c       	cs ss add %al,0x4c(%rdi)
 4bf:	49                   	rex.WB
 4c0:	42                   	rex.X
 4c1:	43 5f                	rex.XB pop %r15
 4c3:	32 2e                	xor    (%rsi),%ch
 4c5:	32 2e                	xor    (%rsi),%ch
 4c7:	35 00 47 4c 49       	xor    $0x494c4700,%eax
 4cc:	42                   	rex.X
 4cd:	43 5f                	rex.XB pop %r15
 4cf:	32 2e                	xor    (%rsi),%ch
 4d1:	34 00                	xor    $0x0,%al
 4d3:	47                   	rex.RXB
 4d4:	4c                   	rex.WR
 4d5:	49                   	rex.WB
 4d6:	42                   	rex.X
 4d7:	43 5f                	rex.XB pop %r15
 4d9:	32 2e                	xor    (%rsi),%ch
 4db:	33 34 00             	xor    (%rax,%rax,1),%esi
 4de:	5f                   	pop    %rdi
 4df:	49 54                	rex.WB push %r12
 4e1:	4d 5f                	rex.WRB pop %r15
 4e3:	64 65 72 65          	fs gs jb 54c <__abi_tag+0x1c0>
 4e7:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4ee:	4d 
 4ef:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4f1:	6f                   	outsl  %ds:(%rsi),(%dx)
 4f2:	6e                   	outsb  %ds:(%rsi),(%dx)
 4f3:	65 54                	gs push %rsp
 4f5:	61                   	(bad)
 4f6:	62 6c 65             	(bad)
 4f9:	00 5f 5f             	add    %bl,0x5f(%rdi)
 4fc:	67 6d                	insl   (%dx),%es:(%edi)
 4fe:	6f                   	outsl  %ds:(%rsi),(%dx)
 4ff:	6e                   	outsb  %ds:(%rsi),(%dx)
 500:	5f                   	pop    %rdi
 501:	73 74                	jae    577 <__abi_tag+0x1eb>
 503:	61                   	(bad)
 504:	72 74                	jb     57a <__abi_tag+0x1ee>
 506:	5f                   	pop    %rdi
 507:	5f                   	pop    %rdi
 508:	00 5f 49             	add    %bl,0x49(%rdi)
 50b:	54                   	push   %rsp
 50c:	4d 5f                	rex.WRB pop %r15
 50e:	72 65                	jb     575 <__abi_tag+0x1e9>
 510:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 517:	4d 
 518:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 51a:	6f                   	outsl  %ds:(%rsi),(%dx)
 51b:	6e                   	outsb  %ds:(%rsi),(%dx)
 51c:	65 54                	gs push %rsp
 51e:	61                   	(bad)
 51f:	62                   	.byte 0x62
 520:	6c                   	insb   (%dx),%es:(%rdi)
 521:	65                   	gs
	...

Disassembly of section .gnu.version:

0000000000000524 <.gnu.version>:
 524:	00 00                	add    %al,(%rax)
 526:	02 00                	add    (%rax),%al
 528:	01 00                	add    %eax,(%rax)
 52a:	03 00                	add    (%rax),%eax
 52c:	01 00                	add    %eax,(%rax)
 52e:	01 00                	add    %eax,(%rax)
 530:	04 00                	add    $0x0,%al

Disassembly of section .gnu.version_r:

0000000000000538 <.gnu.version_r>:
 538:	01 00                	add    %eax,(%rax)
 53a:	03 00                	add    (%rax),%eax
 53c:	33 00                	xor    (%rax),%eax
 53e:	00 00                	add    %al,(%rax)
 540:	10 00                	adc    %al,(%rax)
 542:	00 00                	add    %al,(%rax)
 544:	00 00                	add    %al,(%rax)
 546:	00 00                	add    %al,(%rax)
 548:	75 1a                	jne    564 <__abi_tag+0x1d8>
 54a:	69 09 00 00 04 00    	imul   $0x40000,(%rcx),%ecx
 550:	3d 00 00 00 10       	cmp    $0x10000000,%eax
 555:	00 00                	add    %al,(%rax)
 557:	00 14 69             	add    %dl,(%rcx,%rbp,2)
 55a:	69 0d 00 00 03 00 49 	imul   $0x49,0x30000(%rip),%ecx        # 30564 <_end+0x2c54c>
 561:	00 00 00 
 564:	10 00                	adc    %al,(%rax)
 566:	00 00                	add    %al,(%rax)
 568:	b4 91                	mov    $0x91,%ah
 56a:	96                   	xchg   %eax,%esi
 56b:	06                   	(bad)
 56c:	00 00                	add    %al,(%rax)
 56e:	02 00                	add    (%rax),%al
 570:	53                   	push   %rbx
 571:	00 00                	add    %al,(%rax)
 573:	00 00                	add    %al,(%rax)
 575:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

0000000000000578 <.rela.dyn>:
 578:	b8 3d 00 00 00       	mov    $0x3d,%eax
 57d:	00 00                	add    %al,(%rax)
 57f:	00 08                	add    %cl,(%rax)
 581:	00 00                	add    %al,(%rax)
 583:	00 00                	add    %al,(%rax)
 585:	00 00                	add    %al,(%rax)
 587:	00 40 11             	add    %al,0x11(%rax)
 58a:	00 00                	add    %al,(%rax)
 58c:	00 00                	add    %al,(%rax)
 58e:	00 00                	add    %al,(%rax)
 590:	c0 3d 00 00 00 00 00 	sarb   $0x0,0x0(%rip)        # 597 <__abi_tag+0x20b>
 597:	00 08                	add    %cl,(%rax)
	...
 5a1:	11 00                	adc    %eax,(%rax)
 5a3:	00 00                	add    %al,(%rax)
 5a5:	00 00                	add    %al,(%rax)
 5a7:	00 08                	add    %cl,(%rax)
 5a9:	40 00 00             	rex add %al,(%rax)
 5ac:	00 00                	add    %al,(%rax)
 5ae:	00 00                	add    %al,(%rax)
 5b0:	08 00                	or     %al,(%rax)
 5b2:	00 00                	add    %al,(%rax)
 5b4:	00 00                	add    %al,(%rax)
 5b6:	00 00                	add    %al,(%rax)
 5b8:	08 40 00             	or     %al,0x0(%rax)
 5bb:	00 00                	add    %al,(%rax)
 5bd:	00 00                	add    %al,(%rax)
 5bf:	00 d8                	add    %bl,%al
 5c1:	3f                   	(bad)
 5c2:	00 00                	add    %al,(%rax)
 5c4:	00 00                	add    %al,(%rax)
 5c6:	00 00                	add    %al,(%rax)
 5c8:	06                   	(bad)
 5c9:	00 00                	add    %al,(%rax)
 5cb:	00 01                	add    %al,(%rcx)
	...
 5d5:	00 00                	add    %al,(%rax)
 5d7:	00 e0                	add    %ah,%al
 5d9:	3f                   	(bad)
 5da:	00 00                	add    %al,(%rax)
 5dc:	00 00                	add    %al,(%rax)
 5de:	00 00                	add    %al,(%rax)
 5e0:	06                   	(bad)
 5e1:	00 00                	add    %al,(%rax)
 5e3:	00 02                	add    %al,(%rdx)
	...
 5ed:	00 00                	add    %al,(%rax)
 5ef:	00 e8                	add    %ch,%al
 5f1:	3f                   	(bad)
 5f2:	00 00                	add    %al,(%rax)
 5f4:	00 00                	add    %al,(%rax)
 5f6:	00 00                	add    %al,(%rax)
 5f8:	06                   	(bad)
 5f9:	00 00                	add    %al,(%rax)
 5fb:	00 04 00             	add    %al,(%rax,%rax,1)
	...
 606:	00 00                	add    %al,(%rax)
 608:	f0 3f                	lock (bad)
 60a:	00 00                	add    %al,(%rax)
 60c:	00 00                	add    %al,(%rax)
 60e:	00 00                	add    %al,(%rax)
 610:	06                   	(bad)
 611:	00 00                	add    %al,(%rax)
 613:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 619 <__abi_tag+0x28d>
 619:	00 00                	add    %al,(%rax)
 61b:	00 00                	add    %al,(%rax)
 61d:	00 00                	add    %al,(%rax)
 61f:	00 f8                	add    %bh,%al
 621:	3f                   	(bad)
 622:	00 00                	add    %al,(%rax)
 624:	00 00                	add    %al,(%rax)
 626:	00 00                	add    %al,(%rax)
 628:	06                   	(bad)
 629:	00 00                	add    %al,(%rax)
 62b:	00 06                	add    %al,(%rsi)
	...

Disassembly of section .rela.plt:

0000000000000638 <.rela.plt>:
 638:	d0 3f                	sarb   $1,(%rdi)
 63a:	00 00                	add    %al,(%rax)
 63c:	00 00                	add    %al,(%rax)
 63e:	00 00                	add    %al,(%rax)
 640:	07                   	(bad)
 641:	00 00                	add    %al,(%rax)
 643:	00 03                	add    %al,(%rbx)
	...

Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 9a 2f 00 00    	push   0x2f9a(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 9c 2f 00 00    	jmp    *0x2f9c(%rip)        # 3fc8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)
    1030:	f3 0f 1e fa          	endbr64
    1034:	68 00 00 00 00       	push   $0x0
    1039:	e9 e2 ff ff ff       	jmp    1020 <_init+0x20>
    103e:	66 90                	xchg   %ax,%ax

Disassembly of section .plt.got:

0000000000001040 <__cxa_finalize@plt>:
    1040:	f3 0f 1e fa          	endbr64
    1044:	ff 25 ae 2f 00 00    	jmp    *0x2fae(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    104a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001050 <__stack_chk_fail@plt>:
    1050:	f3 0f 1e fa          	endbr64
    1054:	ff 25 76 2f 00 00    	jmp    *0x2f76(%rip)        # 3fd0 <__stack_chk_fail@GLIBC_2.4>
    105a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001060 <_start>:
    1060:	f3 0f 1e fa          	endbr64
    1064:	31 ed                	xor    %ebp,%ebp
    1066:	49 89 d1             	mov    %rdx,%r9
    1069:	5e                   	pop    %rsi
    106a:	48 89 e2             	mov    %rsp,%rdx
    106d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1071:	50                   	push   %rax
    1072:	54                   	push   %rsp
    1073:	45 31 c0             	xor    %r8d,%r8d
    1076:	31 c9                	xor    %ecx,%ecx
    1078:	48 8d 3d 28 01 00 00 	lea    0x128(%rip),%rdi        # 11a7 <main>
    107f:	ff 15 53 2f 00 00    	call   *0x2f53(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    1085:	f4                   	hlt
    1086:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    108d:	00 00 00 

0000000000001090 <deregister_tm_clones>:
    1090:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4010 <__TMC_END__>
    1097:	48 8d 05 72 2f 00 00 	lea    0x2f72(%rip),%rax        # 4010 <__TMC_END__>
    109e:	48 39 f8             	cmp    %rdi,%rax
    10a1:	74 15                	je     10b8 <deregister_tm_clones+0x28>
    10a3:	48 8b 05 36 2f 00 00 	mov    0x2f36(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    10aa:	48 85 c0             	test   %rax,%rax
    10ad:	74 09                	je     10b8 <deregister_tm_clones+0x28>
    10af:	ff e0                	jmp    *%rax
    10b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10b8:	c3                   	ret
    10b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010c0 <register_tm_clones>:
    10c0:	48 8d 3d 49 2f 00 00 	lea    0x2f49(%rip),%rdi        # 4010 <__TMC_END__>
    10c7:	48 8d 35 42 2f 00 00 	lea    0x2f42(%rip),%rsi        # 4010 <__TMC_END__>
    10ce:	48 29 fe             	sub    %rdi,%rsi
    10d1:	48 89 f0             	mov    %rsi,%rax
    10d4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10d8:	48 c1 f8 03          	sar    $0x3,%rax
    10dc:	48 01 c6             	add    %rax,%rsi
    10df:	48 d1 fe             	sar    $1,%rsi
    10e2:	74 14                	je     10f8 <register_tm_clones+0x38>
    10e4:	48 8b 05 05 2f 00 00 	mov    0x2f05(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    10eb:	48 85 c0             	test   %rax,%rax
    10ee:	74 08                	je     10f8 <register_tm_clones+0x38>
    10f0:	ff e0                	jmp    *%rax
    10f2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10f8:	c3                   	ret
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <__do_global_dtors_aux>:
    1100:	f3 0f 1e fa          	endbr64
    1104:	80 3d 05 2f 00 00 00 	cmpb   $0x0,0x2f05(%rip)        # 4010 <__TMC_END__>
    110b:	75 2b                	jne    1138 <__do_global_dtors_aux+0x38>
    110d:	55                   	push   %rbp
    110e:	48 83 3d e2 2e 00 00 	cmpq   $0x0,0x2ee2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1115:	00 
    1116:	48 89 e5             	mov    %rsp,%rbp
    1119:	74 0c                	je     1127 <__do_global_dtors_aux+0x27>
    111b:	48 8b 3d e6 2e 00 00 	mov    0x2ee6(%rip),%rdi        # 4008 <__dso_handle>
    1122:	e8 19 ff ff ff       	call   1040 <__cxa_finalize@plt>
    1127:	e8 64 ff ff ff       	call   1090 <deregister_tm_clones>
    112c:	c6 05 dd 2e 00 00 01 	movb   $0x1,0x2edd(%rip)        # 4010 <__TMC_END__>
    1133:	5d                   	pop    %rbp
    1134:	c3                   	ret
    1135:	0f 1f 00             	nopl   (%rax)
    1138:	c3                   	ret
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <frame_dummy>:
    1140:	f3 0f 1e fa          	endbr64
    1144:	e9 77 ff ff ff       	jmp    10c0 <register_tm_clones>

0000000000001149 <myfunc>:
    1149:	f3 0f 1e fa          	endbr64
    114d:	55                   	push   %rbp
    114e:	48 89 e5             	mov    %rsp,%rbp
    1151:	48 83 ec 20          	sub    $0x20,%rsp
    1155:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1159:	89 75 e4             	mov    %esi,-0x1c(%rbp)
    115c:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1163:	00 00 
    1165:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1169:	31 c0                	xor    %eax,%eax
    116b:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    1172:	eb 14                	jmp    1188 <myfunc+0x3f>
    1174:	8b 45 f4             	mov    -0xc(%rbp),%eax
    1177:	48 63 d0             	movslq %eax,%rdx
    117a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    117e:	48 01 d0             	add    %rdx,%rax
    1181:	c6 00 2a             	movb   $0x2a,(%rax)
    1184:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
    1188:	8b 45 f4             	mov    -0xc(%rbp),%eax
    118b:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
    118e:	7c e4                	jl     1174 <myfunc+0x2b>
    1190:	90                   	nop
    1191:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1195:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    119c:	00 00 
    119e:	74 05                	je     11a5 <myfunc+0x5c>
    11a0:	e8 ab fe ff ff       	call   1050 <__stack_chk_fail@plt>
    11a5:	c9                   	leave
    11a6:	c3                   	ret

00000000000011a7 <main>:
    11a7:	f3 0f 1e fa          	endbr64
    11ab:	55                   	push   %rbp
    11ac:	48 89 e5             	mov    %rsp,%rbp
    11af:	48 83 ec 10          	sub    $0x10,%rsp
    11b3:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    11ba:	00 00 
    11bc:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    11c0:	31 c0                	xor    %eax,%eax
    11c2:	c7 45 f4 61 62 63 64 	movl   $0x64636261,-0xc(%rbp)
    11c9:	c7 45 f0 04 00 00 00 	movl   $0x4,-0x10(%rbp)
    11d0:	8b 45 f0             	mov    -0x10(%rbp),%eax
    11d3:	8d 50 01             	lea    0x1(%rax),%edx
    11d6:	48 8d 45 f4          	lea    -0xc(%rbp),%rax
    11da:	89 d6                	mov    %edx,%esi
    11dc:	48 89 c7             	mov    %rax,%rdi
    11df:	e8 65 ff ff ff       	call   1149 <myfunc>
    11e4:	b8 00 00 00 00       	mov    $0x0,%eax
    11e9:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    11ed:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    11f4:	00 00 
    11f6:	74 05                	je     11fd <main+0x56>
    11f8:	e8 53 fe ff ff       	call   1050 <__stack_chk_fail@plt>
    11fd:	c9                   	leave
    11fe:	c3                   	ret

Disassembly of section .fini:

0000000000001200 <_fini>:
    1200:	f3 0f 1e fa          	endbr64
    1204:	48 83 ec 08          	sub    $0x8,%rsp
    1208:	48 83 c4 08          	add    $0x8,%rsp
    120c:	c3                   	ret

Disassembly of section .rodata:

0000000000002000 <_IO_stdin_used>:
    2000:	01 00                	add    %eax,(%rax)
    2002:	02 00                	add    (%rax),%al

Disassembly of section .eh_frame_hdr:

0000000000002004 <__GNU_EH_FRAME_HDR>:
    2004:	01 1b                	add    %ebx,(%rbx)
    2006:	03 3b                	add    (%rbx),%edi
    2008:	38 00                	cmp    %al,(%rax)
    200a:	00 00                	add    %al,(%rax)
    200c:	06                   	(bad)
    200d:	00 00                	add    %al,(%rax)
    200f:	00 1c f0             	add    %bl,(%rax,%rsi,8)
    2012:	ff                   	(bad)
    2013:	ff 6c 00 00          	ljmp   *0x0(%rax,%rax,1)
    2017:	00 3c f0             	add    %bh,(%rax,%rsi,8)
    201a:	ff                   	(bad)
    201b:	ff 94 00 00 00 4c f0 	call   *-0xfb40000(%rax,%rax,1)
    2022:	ff                   	(bad)
    2023:	ff ac 00 00 00 5c f0 	ljmp   *-0xfa40000(%rax,%rax,1)
    202a:	ff                   	(bad)
    202b:	ff 54 00 00          	call   *0x0(%rax,%rax,1)
    202f:	00 45 f1             	add    %al,-0xf(%rbp)
    2032:	ff                   	(bad)
    2033:	ff c4                	inc    %esp
    2035:	00 00                	add    %al,(%rax)
    2037:	00 a3 f1 ff ff e4    	add    %ah,-0x1b00000f(%rbx)
    203d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .eh_frame:

0000000000002040 <__FRAME_END__-0xc8>:
    2040:	14 00                	adc    $0x0,%al
    2042:	00 00                	add    %al,(%rax)
    2044:	00 00                	add    %al,(%rax)
    2046:	00 00                	add    %al,(%rax)
    2048:	01 7a 52             	add    %edi,0x52(%rdx)
    204b:	00 01                	add    %al,(%rcx)
    204d:	78 10                	js     205f <__GNU_EH_FRAME_HDR+0x5b>
    204f:	01 1b                	add    %ebx,(%rbx)
    2051:	0c 07                	or     $0x7,%al
    2053:	08 90 01 00 00 14    	or     %dl,0x14000001(%rax)
    2059:	00 00                	add    %al,(%rax)
    205b:	00 1c 00             	add    %bl,(%rax,%rax,1)
    205e:	00 00                	add    %al,(%rax)
    2060:	00 f0                	add    %dh,%al
    2062:	ff                   	(bad)
    2063:	ff 26                	jmp    *(%rsi)
    2065:	00 00                	add    %al,(%rax)
    2067:	00 00                	add    %al,(%rax)
    2069:	44 07                	rex.R (bad)
    206b:	10 00                	adc    %al,(%rax)
    206d:	00 00                	add    %al,(%rax)
    206f:	00 24 00             	add    %ah,(%rax,%rax,1)
    2072:	00 00                	add    %al,(%rax)
    2074:	34 00                	xor    $0x0,%al
    2076:	00 00                	add    %al,(%rax)
    2078:	a8 ef                	test   $0xef,%al
    207a:	ff                   	(bad)
    207b:	ff 20                	jmp    *(%rax)
    207d:	00 00                	add    %al,(%rax)
    207f:	00 00                	add    %al,(%rax)
    2081:	0e                   	(bad)
    2082:	10 46 0e             	adc    %al,0xe(%rsi)
    2085:	18 4a 0f             	sbb    %cl,0xf(%rdx)
    2088:	0b 77 08             	or     0x8(%rdi),%esi
    208b:	80 00 3f             	addb   $0x3f,(%rax)
    208e:	1a 39                	sbb    (%rcx),%bh
    2090:	2a 33                	sub    (%rbx),%dh
    2092:	24 22                	and    $0x22,%al
    2094:	00 00                	add    %al,(%rax)
    2096:	00 00                	add    %al,(%rax)
    2098:	14 00                	adc    $0x0,%al
    209a:	00 00                	add    %al,(%rax)
    209c:	5c                   	pop    %rsp
    209d:	00 00                	add    %al,(%rax)
    209f:	00 a0 ef ff ff 10    	add    %ah,0x10ffffef(%rax)
	...
    20ad:	00 00                	add    %al,(%rax)
    20af:	00 14 00             	add    %dl,(%rax,%rax,1)
    20b2:	00 00                	add    %al,(%rax)
    20b4:	74 00                	je     20b6 <__GNU_EH_FRAME_HDR+0xb2>
    20b6:	00 00                	add    %al,(%rax)
    20b8:	98                   	cwtl
    20b9:	ef                   	out    %eax,(%dx)
    20ba:	ff                   	(bad)
    20bb:	ff 10                	call   *(%rax)
	...
    20c5:	00 00                	add    %al,(%rax)
    20c7:	00 1c 00             	add    %bl,(%rax,%rax,1)
    20ca:	00 00                	add    %al,(%rax)
    20cc:	8c 00                	mov    %es,(%rax)
    20ce:	00 00                	add    %al,(%rax)
    20d0:	79 f0                	jns    20c2 <__GNU_EH_FRAME_HDR+0xbe>
    20d2:	ff                   	(bad)
    20d3:	ff 5e 00             	lcall  *0x0(%rsi)
    20d6:	00 00                	add    %al,(%rax)
    20d8:	00 45 0e             	add    %al,0xe(%rbp)
    20db:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    20e1:	02 55 0c             	add    0xc(%rbp),%dl
    20e4:	07                   	(bad)
    20e5:	08 00                	or     %al,(%rax)
    20e7:	00 1c 00             	add    %bl,(%rax,%rax,1)
    20ea:	00 00                	add    %al,(%rax)
    20ec:	ac                   	lods   %ds:(%rsi),%al
    20ed:	00 00                	add    %al,(%rax)
    20ef:	00 b7 f0 ff ff 58    	add    %dh,0x58fffff0(%rdi)
    20f5:	00 00                	add    %al,(%rax)
    20f7:	00 00                	add    %al,(%rax)
    20f9:	45 0e                	rex.RB (bad)
    20fb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    2101:	02 4f 0c             	add    0xc(%rdi),%cl
    2104:	07                   	(bad)
    2105:	08 00                	or     %al,(%rax)
	...

0000000000002108 <__FRAME_END__>:
    2108:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init_array:

0000000000003db8 <__frame_dummy_init_array_entry>:
    3db8:	40 11 00             	rex adc %eax,(%rax)
    3dbb:	00 00                	add    %al,(%rax)
    3dbd:	00 00                	add    %al,(%rax)
	...

Disassembly of section .fini_array:

0000000000003dc0 <__do_global_dtors_aux_fini_array_entry>:
    3dc0:	00 11                	add    %dl,(%rcx)
    3dc2:	00 00                	add    %al,(%rax)
    3dc4:	00 00                	add    %al,(%rax)
	...

Disassembly of section .dynamic:

0000000000003dc8 <_DYNAMIC>:
    3dc8:	01 00                	add    %eax,(%rax)
    3dca:	00 00                	add    %al,(%rax)
    3dcc:	00 00                	add    %al,(%rax)
    3dce:	00 00                	add    %al,(%rax)
    3dd0:	33 00                	xor    (%rax),%eax
    3dd2:	00 00                	add    %al,(%rax)
    3dd4:	00 00                	add    %al,(%rax)
    3dd6:	00 00                	add    %al,(%rax)
    3dd8:	0c 00                	or     $0x0,%al
    3dda:	00 00                	add    %al,(%rax)
    3ddc:	00 00                	add    %al,(%rax)
    3dde:	00 00                	add    %al,(%rax)
    3de0:	00 10                	add    %dl,(%rax)
    3de2:	00 00                	add    %al,(%rax)
    3de4:	00 00                	add    %al,(%rax)
    3de6:	00 00                	add    %al,(%rax)
    3de8:	0d 00 00 00 00       	or     $0x0,%eax
    3ded:	00 00                	add    %al,(%rax)
    3def:	00 00                	add    %al,(%rax)
    3df1:	12 00                	adc    (%rax),%al
    3df3:	00 00                	add    %al,(%rax)
    3df5:	00 00                	add    %al,(%rax)
    3df7:	00 19                	add    %bl,(%rcx)
    3df9:	00 00                	add    %al,(%rax)
    3dfb:	00 00                	add    %al,(%rax)
    3dfd:	00 00                	add    %al,(%rax)
    3dff:	00 b8 3d 00 00 00    	add    %bh,0x3d(%rax)
    3e05:	00 00                	add    %al,(%rax)
    3e07:	00 1b                	add    %bl,(%rbx)
    3e09:	00 00                	add    %al,(%rax)
    3e0b:	00 00                	add    %al,(%rax)
    3e0d:	00 00                	add    %al,(%rax)
    3e0f:	00 08                	add    %cl,(%rax)
    3e11:	00 00                	add    %al,(%rax)
    3e13:	00 00                	add    %al,(%rax)
    3e15:	00 00                	add    %al,(%rax)
    3e17:	00 1a                	add    %bl,(%rdx)
    3e19:	00 00                	add    %al,(%rax)
    3e1b:	00 00                	add    %al,(%rax)
    3e1d:	00 00                	add    %al,(%rax)
    3e1f:	00 c0                	add    %al,%al
    3e21:	3d 00 00 00 00       	cmp    $0x0,%eax
    3e26:	00 00                	add    %al,(%rax)
    3e28:	1c 00                	sbb    $0x0,%al
    3e2a:	00 00                	add    %al,(%rax)
    3e2c:	00 00                	add    %al,(%rax)
    3e2e:	00 00                	add    %al,(%rax)
    3e30:	08 00                	or     %al,(%rax)
    3e32:	00 00                	add    %al,(%rax)
    3e34:	00 00                	add    %al,(%rax)
    3e36:	00 00                	add    %al,(%rax)
    3e38:	f5                   	cmc
    3e39:	fe                   	(bad)
    3e3a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3e3d:	00 00                	add    %al,(%rax)
    3e3f:	00 b0 03 00 00 00    	add    %dh,0x3(%rax)
    3e45:	00 00                	add    %al,(%rax)
    3e47:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 3e4d <_DYNAMIC+0x85>
    3e4d:	00 00                	add    %al,(%rax)
    3e4f:	00 80 04 00 00 00    	add    %al,0x4(%rax)
    3e55:	00 00                	add    %al,(%rax)
    3e57:	00 06                	add    %al,(%rsi)
    3e59:	00 00                	add    %al,(%rax)
    3e5b:	00 00                	add    %al,(%rax)
    3e5d:	00 00                	add    %al,(%rax)
    3e5f:	00 d8                	add    %bl,%al
    3e61:	03 00                	add    (%rax),%eax
    3e63:	00 00                	add    %al,(%rax)
    3e65:	00 00                	add    %al,(%rax)
    3e67:	00 0a                	add    %cl,(%rdx)
    3e69:	00 00                	add    %al,(%rax)
    3e6b:	00 00                	add    %al,(%rax)
    3e6d:	00 00                	add    %al,(%rax)
    3e6f:	00 a3 00 00 00 00    	add    %ah,0x0(%rbx)
    3e75:	00 00                	add    %al,(%rax)
    3e77:	00 0b                	add    %cl,(%rbx)
    3e79:	00 00                	add    %al,(%rax)
    3e7b:	00 00                	add    %al,(%rax)
    3e7d:	00 00                	add    %al,(%rax)
    3e7f:	00 18                	add    %bl,(%rax)
    3e81:	00 00                	add    %al,(%rax)
    3e83:	00 00                	add    %al,(%rax)
    3e85:	00 00                	add    %al,(%rax)
    3e87:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 3e8d <_DYNAMIC+0xc5>
	...
    3e95:	00 00                	add    %al,(%rax)
    3e97:	00 03                	add    %al,(%rbx)
    3e99:	00 00                	add    %al,(%rax)
    3e9b:	00 00                	add    %al,(%rax)
    3e9d:	00 00                	add    %al,(%rax)
    3e9f:	00 b8 3f 00 00 00    	add    %bh,0x3f(%rax)
    3ea5:	00 00                	add    %al,(%rax)
    3ea7:	00 02                	add    %al,(%rdx)
    3ea9:	00 00                	add    %al,(%rax)
    3eab:	00 00                	add    %al,(%rax)
    3ead:	00 00                	add    %al,(%rax)
    3eaf:	00 18                	add    %bl,(%rax)
    3eb1:	00 00                	add    %al,(%rax)
    3eb3:	00 00                	add    %al,(%rax)
    3eb5:	00 00                	add    %al,(%rax)
    3eb7:	00 14 00             	add    %dl,(%rax,%rax,1)
    3eba:	00 00                	add    %al,(%rax)
    3ebc:	00 00                	add    %al,(%rax)
    3ebe:	00 00                	add    %al,(%rax)
    3ec0:	07                   	(bad)
    3ec1:	00 00                	add    %al,(%rax)
    3ec3:	00 00                	add    %al,(%rax)
    3ec5:	00 00                	add    %al,(%rax)
    3ec7:	00 17                	add    %dl,(%rdi)
    3ec9:	00 00                	add    %al,(%rax)
    3ecb:	00 00                	add    %al,(%rax)
    3ecd:	00 00                	add    %al,(%rax)
    3ecf:	00 38                	add    %bh,(%rax)
    3ed1:	06                   	(bad)
    3ed2:	00 00                	add    %al,(%rax)
    3ed4:	00 00                	add    %al,(%rax)
    3ed6:	00 00                	add    %al,(%rax)
    3ed8:	07                   	(bad)
    3ed9:	00 00                	add    %al,(%rax)
    3edb:	00 00                	add    %al,(%rax)
    3edd:	00 00                	add    %al,(%rax)
    3edf:	00 78 05             	add    %bh,0x5(%rax)
    3ee2:	00 00                	add    %al,(%rax)
    3ee4:	00 00                	add    %al,(%rax)
    3ee6:	00 00                	add    %al,(%rax)
    3ee8:	08 00                	or     %al,(%rax)
    3eea:	00 00                	add    %al,(%rax)
    3eec:	00 00                	add    %al,(%rax)
    3eee:	00 00                	add    %al,(%rax)
    3ef0:	c0 00 00             	rolb   $0x0,(%rax)
    3ef3:	00 00                	add    %al,(%rax)
    3ef5:	00 00                	add    %al,(%rax)
    3ef7:	00 09                	add    %cl,(%rcx)
    3ef9:	00 00                	add    %al,(%rax)
    3efb:	00 00                	add    %al,(%rax)
    3efd:	00 00                	add    %al,(%rax)
    3eff:	00 18                	add    %bl,(%rax)
    3f01:	00 00                	add    %al,(%rax)
    3f03:	00 00                	add    %al,(%rax)
    3f05:	00 00                	add    %al,(%rax)
    3f07:	00 1e                	add    %bl,(%rsi)
    3f09:	00 00                	add    %al,(%rax)
    3f0b:	00 00                	add    %al,(%rax)
    3f0d:	00 00                	add    %al,(%rax)
    3f0f:	00 08                	add    %cl,(%rax)
    3f11:	00 00                	add    %al,(%rax)
    3f13:	00 00                	add    %al,(%rax)
    3f15:	00 00                	add    %al,(%rax)
    3f17:	00 fb                	add    %bh,%bl
    3f19:	ff                   	(bad)
    3f1a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f1d:	00 00                	add    %al,(%rax)
    3f1f:	00 01                	add    %al,(%rcx)
    3f21:	00 00                	add    %al,(%rax)
    3f23:	08 00                	or     %al,(%rax)
    3f25:	00 00                	add    %al,(%rax)
    3f27:	00 fe                	add    %bh,%dh
    3f29:	ff                   	(bad)
    3f2a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f2d:	00 00                	add    %al,(%rax)
    3f2f:	00 38                	add    %bh,(%rax)
    3f31:	05 00 00 00 00       	add    $0x0,%eax
    3f36:	00 00                	add    %al,(%rax)
    3f38:	ff                   	(bad)
    3f39:	ff                   	(bad)
    3f3a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f3d:	00 00                	add    %al,(%rax)
    3f3f:	00 01                	add    %al,(%rcx)
    3f41:	00 00                	add    %al,(%rax)
    3f43:	00 00                	add    %al,(%rax)
    3f45:	00 00                	add    %al,(%rax)
    3f47:	00 f0                	add    %dh,%al
    3f49:	ff                   	(bad)
    3f4a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f4d:	00 00                	add    %al,(%rax)
    3f4f:	00 24 05 00 00 00 00 	add    %ah,0x0(,%rax,1)
    3f56:	00 00                	add    %al,(%rax)
    3f58:	f9                   	stc
    3f59:	ff                   	(bad)
    3f5a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f5d:	00 00                	add    %al,(%rax)
    3f5f:	00 03                	add    %al,(%rbx)
	...

Disassembly of section .got:

0000000000003fb8 <_GLOBAL_OFFSET_TABLE_>:
    3fb8:	c8 3d 00 00          	enter  $0x3d,$0x0
	...
    3fd0:	30 10                	xor    %dl,(%rax)
	...

Disassembly of section .data:

0000000000004000 <__data_start>:
	...

0000000000004008 <__dso_handle>:
    4008:	08 40 00             	or     %al,0x0(%rax)
    400b:	00 00                	add    %al,(%rax)
    400d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <__abi_tag-0x314>
   a:	74 75                	je     81 <__abi_tag-0x30b>
   c:	20 31                	and    %dh,(%rcx)
   e:	33 2e                	xor    (%rsi),%ebp
  10:	33 2e                	xor    (%rsi),%ebp
  12:	30 2d 36 75 62 75    	xor    %ch,0x75627536(%rip)        # 7562754e <_end+0x75623536>
  18:	6e                   	outsb  %ds:(%rsi),(%dx)
  19:	74 75                	je     90 <__abi_tag-0x2fc>
  1b:	32 7e 32             	xor    0x32(%rsi),%bh
  1e:	34 2e                	xor    $0x2e,%al
  20:	30 34 29             	xor    %dh,(%rcx,%rbp,1)
  23:	20 31                	and    %dh,(%rcx)
  25:	33 2e                	xor    (%rsi),%ebp
  27:	33 2e                	xor    (%rsi),%ebp
  29:	30 00                	xor    %al,(%rax)

Disassembly of section .debug_aranges:

0000000000000000 <.debug_aranges>:
   0:	2c 00                	sub    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	02 00                	add    (%rax),%al
   6:	00 00                	add    %al,(%rax)
   8:	00 00                	add    %al,(%rax)
   a:	08 00                	or     %al,(%rax)
   c:	00 00                	add    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	49 11 00             	adc    %rax,(%r8)
  13:	00 00                	add    %al,(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	00 b6 00 00 00 00    	add    %dh,0x0(%rsi)
	...

Disassembly of section .debug_info:

0000000000000000 <.debug_info>:
   0:	05 01 00 00 05       	add    $0x5000001,%eax
   5:	00 01                	add    %al,(%rcx)
   7:	08 00                	or     %al,(%rax)
   9:	00 00                	add    %al,(%rax)
   b:	00 04 00             	add    %al,(%rax,%rax,1)
   e:	00 00                	add    %al,(%rax)
  10:	00 0c 4b             	add    %cl,(%rbx,%rcx,2)
  13:	00 00                	add    %al,(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	00 00                	add    %al,(%rax)
  19:	00 49 11             	add    %cl,0x11(%rcx)
  1c:	00 00                	add    %al,(%rax)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	b6 00                	mov    $0x0,%dh
	...
  2c:	00 00                	add    %al,(%rax)
  2e:	01 08                	add    %ecx,(%rax)
  30:	07                   	(bad)
  31:	98                   	cwtl
  32:	00 00                	add    %al,(%rax)
  34:	00 01                	add    %al,(%rcx)
  36:	04 07                	add    $0x7,%al
  38:	9d                   	popf
  39:	00 00                	add    %al,(%rax)
  3b:	00 01                	add    %al,(%rcx)
  3d:	01 08                	add    %ecx,(%rax)
  3f:	aa                   	stos   %al,%es:(%rdi)
  40:	00 00                	add    %al,(%rax)
  42:	00 01                	add    %al,(%rcx)
  44:	02 07                	add    (%rdi),%al
  46:	c6 00 00             	movb   $0x0,(%rax)
  49:	00 01                	add    %al,(%rcx)
  4b:	01 06                	add    %eax,(%rsi)
  4d:	ac                   	lods   %ds:(%rsi),%al
  4e:	00 00                	add    %al,(%rax)
  50:	00 01                	add    %al,(%rcx)
  52:	02 05 e0 00 00 00    	add    0xe0(%rip),%al        # 138 <__abi_tag-0x254>
  58:	05 04 05 69 6e       	add    $0x6e690504,%eax
  5d:	74 00                	je     5f <__abi_tag-0x32d>
  5f:	01 08                	add    %ecx,(%rax)
  61:	05 bd 00 00 00       	add    $0xbd,%eax
  66:	06                   	(bad)
  67:	08 71 00             	or     %dh,0x0(%rcx)
  6a:	00 00                	add    %al,(%rax)
  6c:	07                   	(bad)
  6d:	66 00 00             	data16 add %al,(%rax)
  70:	00 01                	add    %al,(%rcx)
  72:	01 06                	add    %eax,(%rsi)
  74:	b3 00                	mov    $0x0,%bl
  76:	00 00                	add    %al,(%rax)
  78:	08 71 00             	or     %dh,0x0(%rcx)
  7b:	00 00                	add    %al,(%rax)
  7d:	88 00                	mov    %al,(%rax)
  7f:	00 00                	add    %al,(%rax)
  81:	09 2e                	or     %ebp,(%rsi)
  83:	00 00                	add    %al,(%rax)
  85:	00 03                	add    %al,(%rbx)
  87:	00 0a                	add    %cl,(%rdx)
  89:	b8 00 00 00 01       	mov    $0x1000000,%eax
  8e:	0a 05 58 00 00 00    	or     0x58(%rip),%al        # ec <__abi_tag-0x2a0>
  94:	a7                   	cmpsl  %es:(%rdi),%ds:(%rsi)
  95:	11 00                	adc    %eax,(%rax)
  97:	00 00                	add    %al,(%rax)
  99:	00 00                	add    %al,(%rax)
  9b:	00 58 00             	add    %bl,0x0(%rax)
  9e:	00 00                	add    %al,(%rax)
  a0:	00 00                	add    %al,(%rax)
  a2:	00 00                	add    %al,(%rax)
  a4:	01 9c c7 00 00 00 02 	add    %ebx,0x2000000(%rdi,%rax,8)
  ab:	61                   	(bad)
  ac:	72 72                	jb     120 <__abi_tag-0x26c>
  ae:	00 0b                	add    %cl,(%rbx)
  b0:	0a 78 00             	or     0x0(%rax),%bh
  b3:	00 00                	add    %al,(%rax)
  b5:	02 91 64 02 6c 65    	add    0x656c0264(%rcx),%dl
  bb:	6e                   	outsb  %ds:(%rsi),(%dx)
  bc:	00 0c 09             	add    %cl,(%rcx,%rcx,1)
  bf:	58                   	pop    %rax
  c0:	00 00                	add    %al,(%rax)
  c2:	00 02                	add    %al,(%rdx)
  c4:	91                   	xchg   %eax,%ecx
  c5:	60                   	(bad)
  c6:	00 0b                	add    %cl,(%rbx)
  c8:	d9 00                	flds   (%rax)
  ca:	00 00                	add    %al,(%rax)
  cc:	01 03                	add    %eax,(%rbx)
  ce:	06                   	(bad)
  cf:	49 11 00             	adc    %rax,(%r8)
  d2:	00 00                	add    %al,(%rax)
  d4:	00 00                	add    %al,(%rax)
  d6:	00 5e 00             	add    %bl,0x0(%rsi)
  d9:	00 00                	add    %al,(%rax)
  db:	00 00                	add    %al,(%rax)
  dd:	00 00                	add    %al,(%rax)
  df:	01 9c 03 73 72 63 00 	add    %ebx,0x637273(%rbx,%rax,1)
  e6:	19 6c 00 00          	sbb    %ebp,0x0(%rax,%rax,1)
  ea:	00 02                	add    %al,(%rdx)
  ec:	91                   	xchg   %eax,%ecx
  ed:	58                   	pop    %rax
  ee:	03 6c 65 6e          	add    0x6e(%rbp,%riz,2),%ebp
  f2:	00 22                	add    %ah,(%rdx)
  f4:	58                   	pop    %rax
  f5:	00 00                	add    %al,(%rax)
  f7:	00 02                	add    %al,(%rdx)
  f9:	91                   	xchg   %eax,%ecx
  fa:	54                   	push   %rsp
  fb:	02 69 00             	add    0x0(%rcx),%ch
  fe:	04 09                	add    $0x9,%al
 100:	58                   	pop    %rax
 101:	00 00                	add    %al,(%rax)
 103:	00 02                	add    %al,(%rdx)
 105:	91                   	xchg   %eax,%ecx
 106:	64 00 00             	add    %al,%fs:(%rax)

Disassembly of section .debug_abbrev:

0000000000000000 <.debug_abbrev>:
   0:	01 24 00             	add    %esp,(%rax,%rax,1)
   3:	0b 0b                	or     (%rbx),%ecx
   5:	3e 0b 03             	ds or  (%rbx),%eax
   8:	0e                   	(bad)
   9:	00 00                	add    %al,(%rax)
   b:	02 34 00             	add    (%rax,%rax,1),%dh
   e:	03 08                	add    (%rax),%ecx
  10:	3a 21                	cmp    (%rcx),%ah
  12:	01 3b                	add    %edi,(%rbx)
  14:	0b 39                	or     (%rcx),%edi
  16:	0b 49 13             	or     0x13(%rcx),%ecx
  19:	02 18                	add    (%rax),%bl
  1b:	00 00                	add    %al,(%rax)
  1d:	03 05 00 03 08 3a    	add    0x3a080300(%rip),%eax        # 3a080323 <_end+0x3a07c30b>
  23:	21 01                	and    %eax,(%rcx)
  25:	3b 21                	cmp    (%rcx),%esp
  27:	03 39                	add    (%rcx),%edi
  29:	0b 49 13             	or     0x13(%rcx),%ecx
  2c:	02 18                	add    (%rax),%bl
  2e:	00 00                	add    %al,(%rax)
  30:	04 11                	add    $0x11,%al
  32:	01 25 0e 13 0b 03    	add    %esp,0x30b130e(%rip)        # 30b1346 <_end+0x30ad32e>
  38:	1f                   	(bad)
  39:	1b 1f                	sbb    (%rdi),%ebx
  3b:	11 01                	adc    %eax,(%rcx)
  3d:	12 07                	adc    (%rdi),%al
  3f:	10 17                	adc    %dl,(%rdi)
  41:	00 00                	add    %al,(%rax)
  43:	05 24 00 0b 0b       	add    $0xb0b0024,%eax
  48:	3e 0b 03             	ds or  (%rbx),%eax
  4b:	08 00                	or     %al,(%rax)
  4d:	00 06                	add    %al,(%rsi)
  4f:	0f 00 0b             	str    (%rbx)
  52:	0b 49 13             	or     0x13(%rcx),%ecx
  55:	00 00                	add    %al,(%rax)
  57:	07                   	(bad)
  58:	26 00 49 13          	es add %cl,0x13(%rcx)
  5c:	00 00                	add    %al,(%rax)
  5e:	08 01                	or     %al,(%rcx)
  60:	01 49 13             	add    %ecx,0x13(%rcx)
  63:	01 13                	add    %edx,(%rbx)
  65:	00 00                	add    %al,(%rax)
  67:	09 21                	or     %esp,(%rcx)
  69:	00 49 13             	add    %cl,0x13(%rcx)
  6c:	2f                   	(bad)
  6d:	0b 00                	or     (%rax),%eax
  6f:	00 0a                	add    %cl,(%rdx)
  71:	2e 01 3f             	cs add %edi,(%rdi)
  74:	19 03                	sbb    %eax,(%rbx)
  76:	0e                   	(bad)
  77:	3a 0b                	cmp    (%rbx),%cl
  79:	3b 0b                	cmp    (%rbx),%ecx
  7b:	39 0b                	cmp    %ecx,(%rbx)
  7d:	27                   	(bad)
  7e:	19 49 13             	sbb    %ecx,0x13(%rcx)
  81:	11 01                	adc    %eax,(%rcx)
  83:	12 07                	adc    (%rdi),%al
  85:	40 18 7c 19 01       	sbb    %dil,0x1(%rcx,%rbx,1)
  8a:	13 00                	adc    (%rax),%eax
  8c:	00 0b                	add    %cl,(%rbx)
  8e:	2e 01 3f             	cs add %edi,(%rdi)
  91:	19 03                	sbb    %eax,(%rbx)
  93:	0e                   	(bad)
  94:	3a 0b                	cmp    (%rbx),%cl
  96:	3b 0b                	cmp    (%rbx),%ecx
  98:	39 0b                	cmp    %ecx,(%rbx)
  9a:	27                   	(bad)
  9b:	19 11                	sbb    %edx,(%rcx)
  9d:	01 12                	add    %edx,(%rdx)
  9f:	07                   	(bad)
  a0:	40 18 7c 19 00       	sbb    %dil,0x0(%rcx,%rbx,1)
	...

Disassembly of section .debug_line:

0000000000000000 <.debug_line>:
   0:	79 00                	jns    2 <__abi_tag-0x38a>
   2:	00 00                	add    %al,(%rax)
   4:	05 00 08 00 2a       	add    $0x2a000800,%eax
   9:	00 00                	add    %al,(%rax)
   b:	00 01                	add    %al,(%rcx)
   d:	01 01                	add    %eax,(%rcx)
   f:	fb                   	sti
  10:	0e                   	(bad)
  11:	0d 00 01 01 01       	or     $0x1010100,%eax
  16:	01 00                	add    %eax,(%rax)
  18:	00 00                	add    %al,(%rax)
  1a:	01 00                	add    %eax,(%rax)
  1c:	00 01                	add    %al,(%rcx)
  1e:	01 01                	add    %eax,(%rcx)
  20:	1f                   	(bad)
  21:	01 00                	add    %eax,(%rax)
  23:	00 00                	add    %al,(%rax)
  25:	00 02                	add    %al,(%rdx)
  27:	01 1f                	add    %ebx,(%rdi)
  29:	02 0f                	add    (%rdi),%cl
  2b:	02 4b 00             	add    0x0(%rbx),%cl
  2e:	00 00                	add    %al,(%rax)
  30:	00 4b 00             	add    %cl,0x0(%rbx)
  33:	00 00                	add    %al,(%rax)
  35:	00 05 27 00 09 02    	add    %al,0x2090027(%rip)        # 2090062 <_end+0x208c04a>
  3b:	49 11 00             	adc    %rax,(%r8)
  3e:	00 00                	add    %al,(%rax)
  40:	00 00                	add    %al,(%rax)
  42:	00 14 08             	add    %dl,(%rax,%rcx,1)
  45:	2e 05 0c e6 05 05    	cs add $0x505e60c,%eax
  4b:	74 05                	je     52 <__abi_tag-0x33a>
  4d:	0c 2f                	or     $0x2f,%al
  4f:	05 10 c8 05 1a       	add    $0x1a05c810,%eax
  54:	00 02                	add    %al,(%rdx)
  56:	04 03                	add    $0x3,%al
  58:	3b 05 13 00 02 04    	cmp    0x4020013(%rip),%eax        # 4020071 <_end+0x401c059>
  5e:	01 4a 05             	add    %ecx,0x5(%rdx)
  61:	01 85 05 10 08 68    	add    %eax,0x68081005(%rbp)
  67:	ba 05 0a e5 05       	mov    $0x5e50a05,%edx
  6c:	09 75 05             	or     %esi,0x5(%rbp)
  6f:	05 75 05 0c 08       	add    $0x80c0575,%eax
  74:	3d 05 01 59 02       	cmp    $0x2590105,%eax
  79:	16                   	(bad)
  7a:	00 01                	add    %al,(%rcx)
  7c:	01                   	.byte 0x1

Disassembly of section .debug_str:

0000000000000000 <.debug_str>:
   0:	47                   	rex.RXB
   1:	4e 55                	rex.WRX push %rbp
   3:	20 43 39             	and    %al,0x39(%rbx)
   6:	39 20                	cmp    %esp,(%rax)
   8:	31 33                	xor    %esi,(%rbx)
   a:	2e 33 2e             	cs xor (%rsi),%ebp
   d:	30 20                	xor    %ah,(%rax)
   f:	2d 6d 74 75 6e       	sub    $0x6e75746d,%eax
  14:	65 3d 67 65 6e 65    	gs cmp $0x656e6567,%eax
  1a:	72 69                	jb     85 <__abi_tag-0x307>
  1c:	63 20                	movsxd (%rax),%esp
  1e:	2d 6d 61 72 63       	sub    $0x6372616d,%eax
  23:	68 3d 78 38 36       	push   $0x3638783d
  28:	2d 36 34 20 2d       	sub    $0x2d203436,%eax
  2d:	67 20 2d 4f 30 20 2d 	and    %ch,0x2d20304f(%eip)        # 2d203083 <_end+0x2d1ff06b>
  34:	73 74                	jae    aa <__abi_tag-0x2e2>
  36:	64 3d 63 39 39 20    	fs cmp $0x20393963,%eax
  3c:	2d 66 73 74 61       	sub    $0x61747366,%eax
  41:	63 6b 2d             	movsxd 0x2d(%rbx),%ebp
  44:	70 72                	jo     b8 <__abi_tag-0x2d4>
  46:	6f                   	outsl  %ds:(%rsi),(%dx)
  47:	74 65                	je     ae <__abi_tag-0x2de>
  49:	63 74 6f 72          	movsxd 0x72(%rdi,%rbp,2),%esi
  4d:	2d 61 6c 6c 20       	sub    $0x206c6c61,%eax
  52:	2d 66 61 73 79       	sub    $0x79736166,%eax
  57:	6e                   	outsb  %ds:(%rsi),(%dx)
  58:	63 68 72             	movsxd 0x72(%rax),%ebp
  5b:	6f                   	outsl  %ds:(%rsi),(%dx)
  5c:	6e                   	outsb  %ds:(%rsi),(%dx)
  5d:	6f                   	outsl  %ds:(%rsi),(%dx)
  5e:	75 73                	jne    d3 <__abi_tag-0x2b9>
  60:	2d 75 6e 77 69       	sub    $0x69776e75,%eax
  65:	6e                   	outsb  %ds:(%rsi),(%dx)
  66:	64 2d 74 61 62 6c    	fs sub $0x6c626174,%eax
  6c:	65 73 20             	gs jae 8f <__abi_tag-0x2fd>
  6f:	2d 66 73 74 61       	sub    $0x61747366,%eax
  74:	63 6b 2d             	movsxd 0x2d(%rbx),%ebp
  77:	63 6c 61 73          	movsxd 0x73(%rcx,%riz,2),%ebp
  7b:	68 2d 70 72 6f       	push   $0x6f72702d
  80:	74 65                	je     e7 <__abi_tag-0x2a5>
  82:	63 74 69 6f          	movsxd 0x6f(%rcx,%rbp,2),%esi
  86:	6e                   	outsb  %ds:(%rsi),(%dx)
  87:	20 2d 66 63 66 2d    	and    %ch,0x2d666366(%rip)        # 2d6663f3 <_end+0x2d6623db>
  8d:	70 72                	jo     101 <__abi_tag-0x28b>
  8f:	6f                   	outsl  %ds:(%rsi),(%dx)
  90:	74 65                	je     f7 <__abi_tag-0x295>
  92:	63 74 69 6f          	movsxd 0x6f(%rcx,%rbp,2),%esi
  96:	6e                   	outsb  %ds:(%rsi),(%dx)
  97:	00 6c 6f 6e          	add    %ch,0x6e(%rdi,%rbp,2)
  9b:	67 20 75 6e          	and    %dh,0x6e(%ebp)
  9f:	73 69                	jae    10a <__abi_tag-0x282>
  a1:	67 6e                	outsb  %ds:(%esi),(%dx)
  a3:	65 64 20 69 6e       	gs and %ch,%fs:0x6e(%rcx)
  a8:	74 00                	je     aa <__abi_tag-0x2e2>
  aa:	75 6e                	jne    11a <__abi_tag-0x272>
  ac:	73 69                	jae    117 <__abi_tag-0x275>
  ae:	67 6e                	outsb  %ds:(%esi),(%dx)
  b0:	65 64 20 63 68       	gs and %ah,%fs:0x68(%rbx)
  b5:	61                   	(bad)
  b6:	72 00                	jb     b8 <__abi_tag-0x2d4>
  b8:	6d                   	insl   (%dx),%es:(%rdi)
  b9:	61                   	(bad)
  ba:	69 6e 00 6c 6f 6e 67 	imul   $0x676e6f6c,0x0(%rsi),%ebp
  c1:	20 69 6e             	and    %ch,0x6e(%rcx)
  c4:	74 00                	je     c6 <__abi_tag-0x2c6>
  c6:	73 68                	jae    130 <__abi_tag-0x25c>
  c8:	6f                   	outsl  %ds:(%rsi),(%dx)
  c9:	72 74                	jb     13f <__abi_tag-0x24d>
  cb:	20 75 6e             	and    %dh,0x6e(%rbp)
  ce:	73 69                	jae    139 <__abi_tag-0x253>
  d0:	67 6e                	outsb  %ds:(%esi),(%dx)
  d2:	65 64 20 69 6e       	gs and %ch,%fs:0x6e(%rcx)
  d7:	74 00                	je     d9 <__abi_tag-0x2b3>
  d9:	6d                   	insl   (%dx),%es:(%rdi)
  da:	79 66                	jns    142 <__abi_tag-0x24a>
  dc:	75 6e                	jne    14c <__abi_tag-0x240>
  de:	63 00                	movsxd (%rax),%eax
  e0:	73 68                	jae    14a <__abi_tag-0x242>
  e2:	6f                   	outsl  %ds:(%rsi),(%dx)
  e3:	72 74                	jb     159 <__abi_tag-0x233>
  e5:	20 69 6e             	and    %ch,0x6e(%rcx)
  e8:	74 00                	je     ea <__abi_tag-0x2a2>

Disassembly of section .debug_line_str:

0000000000000000 <.debug_line_str>:
   0:	2f                   	(bad)
   1:	68 6f 6d 65 2f       	push   $0x2f656d6f
   6:	6d                   	insl   (%dx),%es:(%rdi)
   7:	61                   	(bad)
   8:	64 6d                	fs insl (%dx),%es:(%rdi)
   a:	61                   	(bad)
   b:	64 64 6d             	fs fs insl (%dx),%es:(%rdi)
   e:	61                   	(bad)
   f:	78 2f                	js     40 <__abi_tag-0x34c>
  11:	70 72                	jo     85 <__abi_tag-0x307>
  13:	6f                   	outsl  %ds:(%rsi),(%dx)
  14:	6a 65                	push   $0x65
  16:	63 74 73 2f          	movsxd 0x2f(%rbx,%rsi,2),%esi
  1a:	64 73 61             	fs jae 7e <__abi_tag-0x30e>
  1d:	2d 63 6f 6e 63       	sub    $0x636e6f63,%eax
  22:	65 70 74             	gs jo  99 <__abi_tag-0x2f3>
  25:	73 2d                	jae    54 <__abi_tag-0x338>
  27:	70 72                	jo     9b <__abi_tag-0x2f1>
  29:	6f                   	outsl  %ds:(%rsi),(%dx)
  2a:	62 6c 65             	(bad)  {%k5}
  2d:	6d                   	insl   (%dx),%es:(%rdi)
  2e:	73 2f                	jae    5f <__abi_tag-0x32d>
  30:	73 6e                	jae    a0 <__abi_tag-0x2ec>
  32:	69 70 70 65 74 73 2f 	imul   $0x2f737465,0x70(%rax),%esi
  39:	61                   	(bad)
  3a:	6c                   	insb   (%dx),%es:(%rdi)
  3b:	67 6f                	outsl  %ds:(%esi),(%dx)
  3d:	72 69                	jb     a8 <__abi_tag-0x2e4>
  3f:	74 68                	je     a9 <__abi_tag-0x2e3>
  41:	6d                   	insl   (%dx),%es:(%rdi)
  42:	73 2f                	jae    73 <__abi_tag-0x319>
  44:	73 74                	jae    ba <__abi_tag-0x2d2>
  46:	72 69                	jb     b1 <__abi_tag-0x2db>
  48:	6e                   	outsb  %ds:(%rsi),(%dx)
  49:	67 00 73 74          	add    %dh,0x74(%ebx)
  4d:	61                   	(bad)
  4e:	63 6b 73             	movsxd 0x73(%rbx),%ebp
  51:	6d                   	insl   (%dx),%es:(%rdi)
  52:	61                   	(bad)
  53:	73 68                	jae    bd <__abi_tag-0x2cf>
  55:	2e 63 00             	cs movsxd (%rax),%eax
