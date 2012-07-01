section .text

global strlen
	
strlen:
	;; prologue
	push ebp
	mov ebp, esp

	;; save
	push ebx
	push ecx
	
	mov ebx, [ebp + 8]
	mov eax, 0

_count:
	mov cl, [ebx + eax]
	cmp cl,0
	jne _incr

	pop ecx
	pop ebx
	
	leave
	ret

_incr:
	inc eax
	jmp _count