	.file	"main.cpp"
	.section	.text$_ZStorSt13_Ios_OpenmodeS_,"x"
	.linkonce discard
	.globl	_ZStorSt13_Ios_OpenmodeS_
	.def	_ZStorSt13_Ios_OpenmodeS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZStorSt13_Ios_OpenmodeS_
_ZStorSt13_Ios_OpenmodeS_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	orl	%edx, %eax
	popq	%rbp
	ret
	.seh_endproc
.lcomm _ZStL8__ioinit,1,1
	.section	.text$_ZSt3absd,"x"
	.linkonce discard
	.globl	_ZSt3absd
	.def	_ZSt3absd;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt3absd
_ZSt3absd:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	16(%rbp), %xmm1
	movsd	.LC0(%rip), %xmm0
	andpd	%xmm1, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.text
	.globl	_Z10printArrayPdi
	.def	_Z10printArrayPdi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z10printArrayPdi
_Z10printArrayPdi:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L4
.L6:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	16(%rbp), %rax
	movsd	(%rax), %xmm0
	movapd	%xmm0, %xmm1
	leaq	_ZSt4cout(%rip), %rcx
	call	_ZNSolsEd
	movl	$32, %edx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	-4(%rbp), %eax
	addl	$1, %eax
	andl	$7, %eax
	testl	%eax, %eax
	jne	.L5
	leaq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rcx
	call	_ZNSolsEPFRSoS_E
.L5:
	addl	$1, -4(%rbp)
.L4:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	setl	%al
	testb	%al, %al
	jne	.L6
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	_Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	_Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.globl	_Z12readUserFileSsPd
	.def	_Z12readUserFileSsPd;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z12readUserFileSsPd
_Z12readUserFileSsPd:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$808, %rsp
	.seh_stackalloc	808
	leaq	128(%rsp), %rbp
	movaps	%xmm6, 512(%rbp)
	.seh_savexmm	%xmm6, 640
	movaps	%xmm7, 528(%rbp)
	.seh_savexmm	%xmm7, 656
	movaps	%xmm8, 544(%rbp)
	.seh_savexmm	%xmm8, 672
	movaps	%xmm9, 560(%rbp)
	.seh_savexmm	%xmm9, 688
	movaps	%xmm10, 576(%rbp)
	.seh_savexmm	%xmm10, 704
	movaps	%xmm11, 592(%rbp)
	.seh_savexmm	%xmm11, 720
	movaps	%xmm12, 608(%rbp)
	.seh_savexmm	%xmm12, 736
	movaps	%xmm13, 624(%rbp)
	.seh_savexmm	%xmm13, 752
	movaps	%xmm14, 640(%rbp)
	.seh_savexmm	%xmm14, 768
	movaps	%xmm15, 656(%rbp)
	.seh_savexmm	%xmm15, 784
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, 752(%rbp)
	movq	%rdx, 760(%rbp)
	leaq	__gxx_personality_sj0(%rip), %rax
	movq	%rax, -48(%rbp)
	leaq	.LLSDA1099(%rip), %rax
	movq	%rax, -40(%rbp)
	leaq	-32(%rbp), %rax
	leaq	512(%rbp), %rdx
	movq	%rdx, (%rax)
	leaq	.L11(%rip), %rdx
	movq	%rdx, 8(%rax)
	movq	%rsp, 16(%rax)
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_Unwind_SjLj_Register
	leaq	16(%rbp), %rax
	movl	$-1, -88(%rbp)
	movq	%rax, %rcx
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1Ev
	movl	$1, -88(%rbp)
	movq	752(%rbp), %rcx
	call	_ZNKSs5c_strEv
	movq	%rax, %rdx
	leaq	16(%rbp), %rax
	movl	$8, %r8d
	movq	%rax, %rcx
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode
	movl	$0, 508(%rbp)
	jmp	.L8
.L9:
	movl	508(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	760(%rbp), %rdx
	leaq	16(%rbp), %rax
	movl	$1, -88(%rbp)
	movq	%rax, %rcx
	call	_ZNSirsERd
	addl	$1, 508(%rbp)
.L8:
	leaq	16(%rbp), %rax
	addq	$216, %rax
	movl	$1, -88(%rbp)
	movq	%rax, %rcx
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEE3eofEv
	xorl	$1, %eax
	testb	%al, %al
	jne	.L9
	leaq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEE5closeEv
	leaq	16(%rbp), %rax
	movl	$-1, -88(%rbp)
	movq	%rax, %rcx
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_Unwind_SjLj_Unregister
	nop
	movaps	512(%rbp), %xmm6
	movaps	528(%rbp), %xmm7
	movaps	544(%rbp), %xmm8
	movaps	560(%rbp), %xmm9
	movaps	576(%rbp), %xmm10
	movaps	592(%rbp), %xmm11
	movaps	608(%rbp), %xmm12
	movaps	624(%rbp), %xmm13
	movaps	640(%rbp), %xmm14
	movaps	656(%rbp), %xmm15
	addq	$808, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.L11:
	leaq	-512(%rbp), %rbp
	movq	-80(%rbp), %rax
	movq	%rax, 8(%rbp)
	leaq	16(%rbp), %rax
	movl	$0, -88(%rbp)
	movq	%rax, %rcx
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	movq	8(%rbp), %rax
	movl	$-1, -88(%rbp)
	movq	%rax, %rcx
	call	_Unwind_SjLj_Resume
	nop
	.section	.gcc_except_table,"w"
.LLSDA1099:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1099-.LLSDACSB1099
.LLSDACSB1099:
	.uleb128 0
	.uleb128 0
.LLSDACSE1099:
	.text
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "Input File: \0"
.LC2:
	.ascii "Output File: \0"
	.text
	.globl	_Z12getUserFilesRSsS_
	.def	_Z12getUserFilesRSsS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z12getUserFilesRSsS_
_Z12getUserFilesRSsS_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	leaq	.LC1(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	16(%rbp), %rdx
	leaq	_ZSt3cin(%rip), %rcx
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	leaq	.LC2(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	leaq	_ZSt3cin(%rip), %rcx
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z16writeArrayToFilePdiiSs
	.def	_Z16writeArrayToFilePdiiSs;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z16writeArrayToFilePdiiSs
_Z16writeArrayToFilePdiiSs:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$808, %rsp
	.seh_stackalloc	808
	leaq	128(%rsp), %rbp
	movaps	%xmm6, 512(%rbp)
	.seh_savexmm	%xmm6, 640
	movaps	%xmm7, 528(%rbp)
	.seh_savexmm	%xmm7, 656
	movaps	%xmm8, 544(%rbp)
	.seh_savexmm	%xmm8, 672
	movaps	%xmm9, 560(%rbp)
	.seh_savexmm	%xmm9, 688
	movaps	%xmm10, 576(%rbp)
	.seh_savexmm	%xmm10, 704
	movaps	%xmm11, 592(%rbp)
	.seh_savexmm	%xmm11, 720
	movaps	%xmm12, 608(%rbp)
	.seh_savexmm	%xmm12, 736
	movaps	%xmm13, 624(%rbp)
	.seh_savexmm	%xmm13, 752
	movaps	%xmm14, 640(%rbp)
	.seh_savexmm	%xmm14, 768
	movaps	%xmm15, 656(%rbp)
	.seh_savexmm	%xmm15, 784
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, 752(%rbp)
	movl	%edx, 760(%rbp)
	movl	%r8d, 768(%rbp)
	movq	%r9, 776(%rbp)
	leaq	__gxx_personality_sj0(%rip), %rax
	movq	%rax, -32(%rbp)
	leaq	.LLSDA1101(%rip), %rax
	movq	%rax, -24(%rbp)
	leaq	-16(%rbp), %rax
	leaq	512(%rbp), %rdx
	movq	%rdx, (%rax)
	leaq	.L20(%rip), %rdx
	movq	%rdx, 8(%rax)
	movq	%rsp, 16(%rax)
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	_Unwind_SjLj_Register
	movl	$32, %edx
	movl	$16, %ecx
	call	_ZStorSt13_Ios_OpenmodeS_
	movl	%eax, 28(%rbp)
	movq	776(%rbp), %rax
	movl	$-1, -72(%rbp)
	movq	%rax, %rcx
	call	_ZNKSs5c_strEv
	movq	%rax, %rdx
	leaq	32(%rbp), %rax
	movl	28(%rbp), %r8d
	movq	%rax, %rcx
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
	movl	768(%rbp), %eax
	addl	$1, %eax
	movl	%eax, 508(%rbp)
	jmp	.L15
.L18:
	movl	508(%rbp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	768(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	.L16
	movl	508(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	768(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	.L16
	movl	508(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	752(%rbp), %rax
	movsd	(%rax), %xmm0
	leaq	32(%rbp), %rax
	movl	$1, -72(%rbp)
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZNSolsEd
	movl	$32, %edx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	jmp	.L17
.L16:
	movl	508(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	768(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L17
	leaq	32(%rbp), %rax
	movl	$1, -72(%rbp)
	leaq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
.L17:
	addl	$1, 508(%rbp)
.L15:
	movl	760(%rbp), %eax
	subl	$1, %eax
	imull	768(%rbp), %eax
	cmpl	508(%rbp), %eax
	setg	%al
	testb	%al, %al
	jne	.L18
	leaq	32(%rbp), %rax
	movl	$1, -72(%rbp)
	movq	%rax, %rcx
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEE5closeEv
	leaq	32(%rbp), %rax
	movl	$-1, -72(%rbp)
	movq	%rax, %rcx
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	_Unwind_SjLj_Unregister
	nop
	movaps	512(%rbp), %xmm6
	movaps	528(%rbp), %xmm7
	movaps	544(%rbp), %xmm8
	movaps	560(%rbp), %xmm9
	movaps	576(%rbp), %xmm10
	movaps	592(%rbp), %xmm11
	movaps	608(%rbp), %xmm12
	movaps	624(%rbp), %xmm13
	movaps	640(%rbp), %xmm14
	movaps	656(%rbp), %xmm15
	addq	$808, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.L20:
	leaq	-512(%rbp), %rbp
	movq	-64(%rbp), %rax
	movq	%rax, -88(%rbp)
	leaq	32(%rbp), %rax
	movl	$0, -72(%rbp)
	movq	%rax, %rcx
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev
	movq	-88(%rbp), %rax
	movl	$-1, -72(%rbp)
	movq	%rax, %rcx
	call	_Unwind_SjLj_Resume
	nop
	.section	.gcc_except_table,"w"
.LLSDA1101:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1101-.LLSDACSB1101
.LLSDACSB1101:
	.uleb128 0
	.uleb128 0
.LLSDACSE1101:
	.text
	.seh_endproc
	.globl	_Z15initializeArrayPdi
	.def	_Z15initializeArrayPdi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z15initializeArrayPdi
_Z15initializeArrayPdi:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_setframe	%rbp, 16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L23
.L24:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	16(%rbp), %rax
	movl	$0, %edx
	movq	%rdx, (%rax)
	addl	$1, -4(%rbp)
.L23:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	setl	%al
	testb	%al, %al
	jne	.L24
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z10getNewTempPdi
	.def	_Z10getNewTempPdi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z10getNewTempPdi
_Z10getNewTempPdi:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	cltq
	subq	$8, %rax
	salq	$3, %rax
	addq	16(%rbp), %rax
	movsd	(%rax), %xmm1
	movl	24(%rbp), %eax
	cltq
	addq	$8, %rax
	salq	$3, %rax
	addq	16(%rbp), %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	movl	24(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$3, %rax
	addq	16(%rbp), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movl	24(%rbp), %eax
	cltq
	subq	$1, %rax
	salq	$3, %rax
	addq	16(%rbp), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movsd	.LC4(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z11updateArrayPdRdii
	.def	_Z11updateArrayPdRdii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z11updateArrayPdRdii
_Z11updateArrayPdRdii:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	subq	$64, %rsp
	.seh_stackalloc	64
	movaps	%xmm6, -16(%rbp)
	.seh_savexmm	%xmm6, 48
	.seh_setframe	%rbp, 64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	%r9d, 40(%rbp)
	movq	16(%rbp), %rax
	addq	$72, %rax
	movsd	(%rax), %xmm6
	movl	$9, %edx
	movq	16(%rbp), %rcx
	call	_Z10getNewTempPdi
	movapd	%xmm6, %xmm1
	subsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	call	_ZSt3absd
	movq	24(%rbp), %rax
	movsd	%xmm0, (%rax)
	movl	40(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	.L27
.L30:
	movl	-20(%rbp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	40(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	.L28
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	40(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	.L28
	movl	-20(%rbp), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_Z10getNewTempPdi
	movsd	%xmm0, -32(%rbp)
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	16(%rbp), %rax
	movsd	(%rax), %xmm1
	movsd	-32(%rbp), %xmm0
	subsd	%xmm1, %xmm0
	call	_ZSt3absd
	movq	24(%rbp), %rax
	movsd	(%rax), %xmm1
	ucomisd	%xmm1, %xmm0
	seta	%al
	testb	%al, %al
	je	.L29
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	16(%rbp), %rax
	movsd	(%rax), %xmm1
	movsd	-32(%rbp), %xmm0
	subsd	%xmm1, %xmm0
	call	_ZSt3absd
	movq	24(%rbp), %rax
	movsd	%xmm0, (%rax)
.L29:
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	16(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, (%rax)
.L28:
	addl	$1, -20(%rbp)
.L27:
	movl	32(%rbp), %eax
	subl	$1, %eax
	imull	40(%rbp), %eax
	cmpl	-20(%rbp), %eax
	setg	%al
	testb	%al, %al
	jne	.L30
	movaps	-16(%rbp), %xmm6
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$840, %rsp
	.seh_stackalloc	840
	leaq	128(%rsp), %rbp
	movaps	%xmm6, 544(%rbp)
	.seh_savexmm	%xmm6, 672
	movaps	%xmm7, 560(%rbp)
	.seh_savexmm	%xmm7, 688
	movaps	%xmm8, 576(%rbp)
	.seh_savexmm	%xmm8, 704
	movaps	%xmm9, 592(%rbp)
	.seh_savexmm	%xmm9, 720
	movaps	%xmm10, 608(%rbp)
	.seh_savexmm	%xmm10, 736
	movaps	%xmm11, 624(%rbp)
	.seh_savexmm	%xmm11, 752
	movaps	%xmm12, 640(%rbp)
	.seh_savexmm	%xmm12, 768
	movaps	%xmm13, 656(%rbp)
	.seh_savexmm	%xmm13, 784
	movaps	%xmm14, 672(%rbp)
	.seh_savexmm	%xmm14, 800
	movaps	%xmm15, 688(%rbp)
	.seh_savexmm	%xmm15, 816
	.seh_setframe	%rbp, 128
	.seh_endprologue
	leaq	__gxx_personality_sj0(%rip), %rax
	movq	%rax, -16(%rbp)
	leaq	.LLSDA1105(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	%rbp, %rax
	leaq	544(%rbp), %rdx
	movq	%rdx, (%rax)
	leaq	.L42(%rip), %rdx
	movq	%rdx, 8(%rax)
	movq	%rsp, 16(%rax)
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_Unwind_SjLj_Register
	call	__main
	leaq	496(%rbp), %rax
	movl	$-1, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsC1Ev
	leaq	480(%rbp), %rax
	movl	$1, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsC1Ev
	leaq	480(%rbp), %rdx
	leaq	496(%rbp), %rax
	movl	$2, -56(%rbp)
	movq	%rax, %rcx
	call	_Z12getUserFilesRSsS_
	movq	$0, 432(%rbp)
	movq	$0, 440(%rbp)
	movq	$0, 448(%rbp)
	movq	$0, 456(%rbp)
	movq	$0, 464(%rbp)
	leaq	48(%rbp), %rax
	movl	$48, %edx
	movq	%rax, %rcx
	call	_Z15initializeArrayPdi
	leaq	496(%rbp), %rdx
	leaq	512(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSsC1ERKSs
	leaq	432(%rbp), %rdx
	leaq	512(%rbp), %rax
	movl	$3, -56(%rbp)
	movq	%rax, %rcx
	call	_Z12readUserFileSsPd
	leaq	512(%rbp), %rax
	movl	$2, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	movsd	464(%rbp), %xmm1
	movsd	.LC5(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, 472(%rbp)
	movl	$1, 540(%rbp)
	jmp	.L32
.L33:
	movq	456(%rbp), %rax
	movl	540(%rbp), %edx
	movslq	%edx, %rdx
	salq	$6, %rdx
	leaq	544(%rbp), %rcx
	addq	%rcx, %rdx
	subq	$496, %rdx
	movq	%rax, (%rdx)
	movq	440(%rbp), %rax
	movl	540(%rbp), %edx
	movslq	%edx, %rdx
	salq	$6, %rdx
	leaq	544(%rbp), %rcx
	addq	%rcx, %rdx
	subq	$440, %rdx
	movq	%rax, (%rdx)
	addl	$1, 540(%rbp)
.L32:
	cmpl	$4, 540(%rbp)
	setle	%al
	testb	%al, %al
	jne	.L33
	movl	$0, 536(%rbp)
	jmp	.L34
.L35:
	movq	432(%rbp), %rdx
	movl	536(%rbp), %eax
	cltq
	movq	%rdx, 48(%rbp,%rax,8)
	movq	448(%rbp), %rax
	movl	536(%rbp), %edx
	movslq	%edx, %rdx
	addq	$40, %rdx
	movq	%rax, 48(%rbp,%rdx,8)
	addl	$1, 536(%rbp)
.L34:
	cmpl	$7, 536(%rbp)
	setle	%al
	testb	%al, %al
	jne	.L35
	jmp	.L36
.L37:
	leaq	472(%rbp), %rdx
	leaq	48(%rbp), %rax
	movl	$8, %r9d
	movl	$6, %r8d
	movq	%rax, %rcx
	call	_Z11updateArrayPdRdii
.L36:
	movsd	464(%rbp), %xmm1
	movsd	472(%rbp), %xmm0
	ucomisd	%xmm1, %xmm0
	seta	%al
	testb	%al, %al
	jne	.L37
	leaq	480(%rbp), %rdx
	leaq	528(%rbp), %rax
	movl	$2, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsC1ERKSs
	leaq	528(%rbp), %rdx
	leaq	48(%rbp), %rax
	movl	$4, -56(%rbp)
	movq	%rdx, %r9
	movl	$8, %r8d
	movl	$6, %edx
	movq	%rax, %rcx
	call	_Z16writeArrayToFilePdiiSs
	leaq	528(%rbp), %rax
	movl	$2, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	movl	$0, 44(%rbp)
	leaq	480(%rbp), %rax
	movl	$1, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	leaq	496(%rbp), %rax
	movl	$-1, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	movl	44(%rbp), %eax
	movl	%eax, 40(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_Unwind_SjLj_Unregister
	movl	40(%rbp), %eax
	movaps	544(%rbp), %xmm6
	movaps	560(%rbp), %xmm7
	movaps	576(%rbp), %xmm8
	movaps	592(%rbp), %xmm9
	movaps	608(%rbp), %xmm10
	movaps	624(%rbp), %xmm11
	movaps	640(%rbp), %xmm12
	movaps	656(%rbp), %xmm13
	movaps	672(%rbp), %xmm14
	movaps	688(%rbp), %xmm15
	addq	$840, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.L45:
	movq	%rdx, -80(%rbp)
	leaq	512(%rbp), %rax
	movl	$0, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	movq	-80(%rbp), %rdx
	movq	%rdx, -72(%rbp)
	jmp	.L39
.L46:
	movq	%rdx, -88(%rbp)
	leaq	528(%rbp), %rax
	movl	$0, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	movq	-88(%rbp), %rcx
	movq	%rcx, -72(%rbp)
	jmp	.L39
.L44:
	movq	%rdx, -72(%rbp)
.L39:
	leaq	480(%rbp), %rax
	movl	$0, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	movq	-72(%rbp), %rax
	movq	%rax, -96(%rbp)
	jmp	.L41
.L42:
	leaq	-544(%rbp), %rbp
	movq	-48(%rbp), %rdx
	movl	-56(%rbp), %eax
	cmpl	$1, %eax
	je	.L44
	cmpl	$1, %eax
	jg	.L47
	testl	%eax, %eax
	je	.L43
.L47:
	cmpl	$2, %eax
	je	.L45
	cmpl	$3, %eax
	je	.L46
		.word	0x0b0f
.L43:
	movq	%rdx, -96(%rbp)
.L41:
	leaq	496(%rbp), %rax
	movl	$0, -56(%rbp)
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	movq	-96(%rbp), %rax
	movl	$-1, -56(%rbp)
	movq	%rax, %rcx
	call	_Unwind_SjLj_Resume
	nop
	.section	.gcc_except_table,"w"
.LLSDA1105:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1105-.LLSDACSB1105
.LLSDACSB1105:
	.uleb128 0
	.uleb128 0
	.uleb128 0x1
	.uleb128 0
	.uleb128 0x2
	.uleb128 0
	.uleb128 0x3
	.uleb128 0
.LLSDACSE1105:
	.text
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_setframe	%rbp, 32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L49
	cmpl	$65535, 24(%rbp)
	jne	.L49
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
	nop
.L49:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
_ZL8NUM_ROWS:
	.long	6
	.align 4
_ZL8NUM_COLS:
	.long	8
	.text
	.def	_GLOBAL__sub_I__Z10printArrayPdi;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z10printArrayPdi
_GLOBAL__sub_I__Z10printArrayPdi:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z10printArrayPdi
	.section .rdata,"dr"
	.align 16
.LC0:
	.long	-1
	.long	2147483647
	.long	0
	.long	0
	.align 8
.LC4:
	.long	0
	.long	1074790400
	.align 8
.LC5:
	.long	0
	.long	1072693248
	.def	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNKSs5c_strEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ifstreamIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERd;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt9basic_iosIcSt11char_traitsIcEE3eofEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ifstreamIcSt11char_traitsIcEE5closeEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ofstreamIcSt11char_traitsIcEE5closeEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSsC1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	_ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
