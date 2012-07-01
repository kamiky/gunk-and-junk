section .text

global memset 		; void *memset(void *s, int c, size_t n);

memset:
	;;  prologue
	push ebp
	mov ebp, esp

	push ebx
	push ecx
	
	mov eax, [ebp + 8]	; addr
	mov ebx, [ebp + 12]	; byte
	mov ecx, [ebp + 16]	; size

	cmp eax, 0
	je _return
	
_loop:
	cmp ecx, 0
	je _return
	
	mov [eax], bl
	;; inc
	dec ecx
	inc eax
	jmp _loop

_return:
	mov eax, [ebp + 8]

	pop ecx
	pop ebx

	leave
	ret