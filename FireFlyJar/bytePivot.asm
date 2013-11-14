            .global bytePivot
bytePivot:
			mov.b	#10000000b,r15; set r15 as bit mask
outerloop:
			clr.b	r11			; clear r11 register
			mov.b	#8,r14		; set r14 as inner counter
innerloop:
			bit.b	@r12+,r15	; compare bitness of src field
			rlc.b	r11			; move the carry bit into lsb of r11
			dec.b	r14			; decrease counter
			jnz		innerloop	; restart inner loop
			sub.w	#8, r12		; reset r12 to start of source
			mov.b	r11, 0(r13)	; move r11 to dest
			inc.w	r13			; move to next dest field
			rrc.b	r15			; move bit flag right one
			jnz		outerloop	; restart outer loop for next dest field
			clr.b	r12			; set return as 0
			ret
