section .text

global strcspn
extern strchr

strcspn:
	push ebp
	mov ebp, esp

	push esi
	push ebx
	push ecx
	
	mov ebx, [ebp + 8] 	; str
	mov ecx, [ebp + 12]	; reject

_loop:
	push dword [ebx]	; for each char of str
	push ecx
	call strchr		; exists in reject ??
	pop ecx
	pop esi

	cmp eax, 0		; while false
	je _incr

	sub ebx, [ebp + 8]
	mov eax, ebx
_return:	
	pop ecx
	pop ebx
	pop esi
	leave
	ret
	
_incr:
	inc ebx
	cmp dword [ebx], 0
	je _return
	jmp _loop