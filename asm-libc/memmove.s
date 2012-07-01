section .text

global memmove
	
memmove:
	;; prologue
	push ebp
	mov ebp, esp

	push ebx
	push ecx

	mov eax, [ebp + 8]	;dest
	mov ebx, [ebp + 12]	;src
	mov ecx, [ebp + 16]	;size

	cmp eax, ebx
	jb _greater

_below: 			; dest < src
	dec ecx
	add ebx, ecx
	add eax, ecx
	inc ecx
	
_bloop:
	cmp ecx, 0
	je _return
	
	mov dl, [ebx]
	mov [eax], dl

	dec eax
	dec ebx
	dec ecx
	jmp _bloop

_greater:			; src < dest
	cmp ecx, 0
	je _return

	mov dl, [ebx]
	mov [eax], dl

	inc eax
	inc ebx
	dec ecx
	jmp _greater
	
;;  return
_return:
	mov eax, [ebp + 8]

	pop ecx
	pop ebx

	leave
	ret