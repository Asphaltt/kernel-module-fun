<!--
 Copyright 2025 Leon Hwang.
 SPDX-License-Identifier: Apache-2.0
-->

# Disasm percpu reading functions

```bash
# disasm percpu_read
Disassembling percpu_read at 0xffffffffc15c5010 (80 bytes) ..
; percpu_read+0x0
0xffffffffc15c5010 <+0/0x0>:      0f 1f 44 00 00     	nopl	(%rax, %rax)
0xffffffffc15c5015 <+5/0x5>:      55                 	pushq	%rbp
0xffffffffc15c5016 <+6/0x6>:      48 89 e5           	movq	%rsp, %rbp
0xffffffffc15c5019 <+9/0x9>:      41 54              	pushq	%r12
0xffffffffc15c501b <+11/0xb>:     49 c7 c4 04 60 03 00	movq	$0x36004, %r12
0xffffffffc15c5022 <+18/0x12>:    53                 	pushq	%rbx
0xffffffffc15c5023 <+19/0x13>:    48 63 df           	movslq	%edi, %rbx
0xffffffffc15c5026 <+22/0x16>:    48 81 fb 00 20 00 00	cmpq	$0x2000, %rbx
0xffffffffc15c502d <+29/0x1d>:    73 19              	jae	0xffffffffc15c5048	; percpu_read+0x38
0xffffffffc15c502f <+31/0x1f>:    48 8b 04 dd 80 fc 24 a8	movq	-0x57db0380(, %rbx, 8), %rax
0xffffffffc15c5037 <+39/0x27>:    5b                 	popq	%rbx
0xffffffffc15c5038 <+40/0x28>:    42 8b 04 20        	movl	(%rax, %r12), %eax
0xffffffffc15c503c <+44/0x2c>:    41 5c              	popq	%r12
0xffffffffc15c503e <+46/0x2e>:    5d                 	popq	%rbp
0xffffffffc15c503f <+47/0x2f>:    31 f6              	xorl	%esi, %esi
0xffffffffc15c5041 <+49/0x31>:    31 ff              	xorl	%edi, %edi
0xffffffffc15c5043 <+51/0x33>:    c3                 	retq
0xffffffffc15c5044 <+52/0x34>:    cc                 	int3
0xffffffffc15c5045 <+53/0x35>:    cc                 	int3
0xffffffffc15c5046 <+54/0x36>:    cc                 	int3
0xffffffffc15c5047 <+55/0x37>:    cc                 	int3
0xffffffffc15c5048 <+56/0x38>:    48 89 de           	movq	%rbx, %rsi
0xffffffffc15c504b <+59/0x3b>:    48 c7 c7 a0 70 5c c1	movq	$18446744072658645152, %rdi
0xffffffffc15c5052 <+66/0x42>:    e8 d9 87 ac e5     	callq	0xffffffffa708d830	; __ubsan_handle_out_of_bounds+0x0 lib/ubsan.c:336
0xffffffffc15c5057 <+71/0x47>:    eb d6              	jmp	0xffffffffc15c502f	; percpu_read+0x1f
0xffffffffc15c5059 <+73/0x49>:    0f 1f 80 00 00 00 00	nopl	(%rax)

# thiscpu_read
Disassembling thiscpu_read at 0xffffffffc15c5070 (28 bytes) ..
; thiscpu_read+0x0
0xffffffffc15c5070 <+0/0x0>:      0f 1f 44 00 00     	nopl	(%rax, %rax)
0xffffffffc15c5075 <+5/0x5>:      55                 	pushq	%rbp
0xffffffffc15c5076 <+6/0x6>:      48 c7 c0 04 60 03 00	movq	$0x36004, %rax
0xffffffffc15c507d <+13/0xd>:     65 48 03 05 7b 49 a5 3e	addq	%gs:0x3ea5497b(%rip), %rax
0xffffffffc15c5085 <+21/0x15>:    8b 00              	movl	(%rax), %eax
0xffffffffc15c5087 <+23/0x17>:    48 89 e5           	movq	%rsp, %rbp
0xffffffffc15c508a <+26/0x1a>:    5d                 	popq	%rbp
0xffffffffc15c508b <+27/0x1b>:    c3                 	retq

# percpu_currcpu_read
Disassembling percpu_currcpu_read at 0xffffffffc15c50a0 (112 bytes) ..
; percpu_currcpu_read+0x0
0xffffffffc15c50a0 <+0/0x0>:      0f 1f 44 00 00     	nopl	(%rax, %rax)
0xffffffffc15c50a5 <+5/0x5>:      65 8b 05 e0 de a6 3e	movl	%gs:0x3ea6dee0(%rip), %eax
0xffffffffc15c50ac <+12/0xc>:     39 f8              	cmpl	%edi, %eax
0xffffffffc15c50ae <+14/0xe>:     74 33              	je	0xffffffffc15c50e3	; percpu_currcpu_read+0x43
0xffffffffc15c50b0 <+16/0x10>:    55                 	pushq	%rbp
0xffffffffc15c50b1 <+17/0x11>:    48 89 e5           	movq	%rsp, %rbp
0xffffffffc15c50b4 <+20/0x14>:    41 54              	pushq	%r12
0xffffffffc15c50b6 <+22/0x16>:    49 c7 c4 04 60 03 00	movq	$0x36004, %r12
0xffffffffc15c50bd <+29/0x1d>:    53                 	pushq	%rbx
0xffffffffc15c50be <+30/0x1e>:    48 63 df           	movslq	%edi, %rbx
0xffffffffc15c50c1 <+33/0x21>:    48 81 fb 00 20 00 00	cmpq	$0x2000, %rbx
0xffffffffc15c50c8 <+40/0x28>:    73 33              	jae	0xffffffffc15c50fd	; percpu_currcpu_read+0x5d
0xffffffffc15c50ca <+42/0x2a>:    48 8b 04 dd 80 fc 24 a8	movq	-0x57db0380(, %rbx, 8), %rax
0xffffffffc15c50d2 <+50/0x32>:    5b                 	popq	%rbx
0xffffffffc15c50d3 <+51/0x33>:    42 8b 04 20        	movl	(%rax, %r12), %eax
0xffffffffc15c50d7 <+55/0x37>:    41 5c              	popq	%r12
0xffffffffc15c50d9 <+57/0x39>:    5d                 	popq	%rbp
0xffffffffc15c50da <+58/0x3a>:    31 f6              	xorl	%esi, %esi
0xffffffffc15c50dc <+60/0x3c>:    31 ff              	xorl	%edi, %edi
0xffffffffc15c50de <+62/0x3e>:    c3                 	retq
0xffffffffc15c50df <+63/0x3f>:    cc                 	int3
0xffffffffc15c50e0 <+64/0x40>:    cc                 	int3
0xffffffffc15c50e1 <+65/0x41>:    cc                 	int3
0xffffffffc15c50e2 <+66/0x42>:    cc                 	int3
0xffffffffc15c50e3 <+67/0x43>:    48 c7 c0 04 60 03 00	movq	$0x36004, %rax
0xffffffffc15c50ea <+74/0x4a>:    65 48 03 05 0e 49 a5 3e	addq	%gs:0x3ea5490e(%rip), %rax
0xffffffffc15c50f2 <+82/0x52>:    8b 00              	movl	(%rax), %eax
0xffffffffc15c50f4 <+84/0x54>:    31 f6              	xorl	%esi, %esi
0xffffffffc15c50f6 <+86/0x56>:    31 ff              	xorl	%edi, %edi
0xffffffffc15c50f8 <+88/0x58>:    c3                 	retq
0xffffffffc15c50f9 <+89/0x59>:    cc                 	int3
0xffffffffc15c50fa <+90/0x5a>:    cc                 	int3
0xffffffffc15c50fb <+91/0x5b>:    cc                 	int3
0xffffffffc15c50fc <+92/0x5c>:    cc                 	int3
0xffffffffc15c50fd <+93/0x5d>:    48 89 de           	movq	%rbx, %rsi
0xffffffffc15c5100 <+96/0x60>:    48 c7 c7 80 70 5c c1	movq	$18446744072658645120, %rdi
0xffffffffc15c5107 <+103/0x67>:   e8 24 87 ac e5     	callq	0xffffffffa708d830	; __ubsan_handle_out_of_bounds+0x0 lib/ubsan.c:336
0xffffffffc15c510c <+108/0x6c>:   eb bc              	jmp	0xffffffffc15c50ca	; percpu_currcpu_read+0x2a
0xffffffffc15c510e <+110/0x6e>:   00 00              	addb	%al, (%rax)
```
