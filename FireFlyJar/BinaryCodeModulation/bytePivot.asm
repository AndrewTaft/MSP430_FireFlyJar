            .global BCM_BytePivot
BCM_BytePivot:
			push	r10			;push r10 to the stack
			mov.b	#80h,r15	; set r15 as bit mask
			add.w	#7,r13		; set r13(dest) to the end of the array
			mov.b	#0,0(r14)	; set the flag for pin in use to 0
outerloop:
			clr.b	r11			; clear r11 register
			mov.b	#8,r10		; set r10 as inner counter
innerloop:
			bit.b	@r12+,r15	; compare bitness of src field
			rrc.b	r11			; move the carry bit into msb of r11
			dec.b	r10			; decrease counter
			jnz		innerloop	; restart inner loop
			sub.w	#8, r12		; reset r12 to start of source
			mov.b	r11, 0(r13)	; move r11 to dest
			cmp.w	#0, r11		; check r11 for non zero
			jz		skipset		; if zero skip setting flag
			mov.b	#1, 0(r14)	; set r14 if value
skipset:
			dec.w	r13			; move to next dest field
			rra.w	r15			; move bit flag right one
			jnz		outerloop	; restart outer loop for next dest field
			clr.b	r12			; set return as 0
			pop		r10			; pop r10 back off the stack
			ret
