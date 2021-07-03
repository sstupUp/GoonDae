		.data
num1:		.word  8
num2:		.word  16	
numsum:	.word  0
str:		.asciz "%d\n"
	
		.text
		.globl main
main:		ldr r0, =num1
		ldr r1, =num2
		ldr r2, =numsum
		ldr r0, [r0]
		ldr r1, [r1]
		add r0, r0, r1		
		str r0, [r2]
		mov r1, r0
		ldr r0, =str
		stmfd sp!, {lr}
		bl  printf
		ldmfd sp!, {lr}
		mov pc, lr
		
