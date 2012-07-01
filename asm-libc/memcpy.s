section .text

global memcpy
;; void *memcpy(void *dest, const void *src, size_t n);

memcpy:
	;; prologue
	push ebp
	mov ebp, esp
	
	push ebx
	push ecx
	
	mov eax, [ebp + 8]	; dest
	mov ebx, [ebp + 12]	; src
	mov ecx, [ebp + 16]	; size

_loop:
	cmp ecx, 0
	je _return
	;;  cpy
	mov dl, [ebx]
	mov [eax], dl
	;; inc
	dec ecx
	inc eax
	inc ebx
	jmp _loop
	
_return:
	mov eax, [ebp + 8]

	pop ecx
	pop ebx

	leave
	ret