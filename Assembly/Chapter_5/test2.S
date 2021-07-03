		.data
enter:		.asciz "Enter x:"
format:	.asciz "%d"
result:	.asciz "%d! = %d"


		.text
		.globl main
facto:	cmp 	r0, #2
	mov 	r1, #1
	blt 	done
	stmfd	sp!, {lr}
	mov	r1, r0
	sub	r0, r0, #1
	b	facto
done:	ldmfd	sp!, {lr}
	mul	r0, r1, r0
	mov	pc, lr

main:	stmfd 	sp!, {lr}
	sub	sp, sp, #4
while:	ldr	r0, =enter
	bl	printf
	ldr	r0,=format
	mov	r1, sp
	bl	scanf
	mov	r3, r0
	ldmfd	sp!, {lr}
	cmp	r3, #1
	bleq	facto
	moveq	r1, r3
	ldreq	r0, =result
	bleq	printf
	beq	while
	mov	r0, #0
	ldmfd	sp!, {lr}
	mov pc, lr
	
