section .text

global rindex

rindex:
	;; prologue
	push ebp
	mov ebp, esp

	push ebx
	push ecx

	mov eax, 0
	mov ebx, [ebp + 8]	;str
	mov cl, [ebp + 12]	;c

_loop:
	mov ch, [ebx]

	cmp ch, cl
	je _store

	cmp ch, 0
	je _return

	inc ebx

	jmp _loop

_store:
	mov eax, ebx
	cmp ch, 0
	je _return
	inc ebx
	jmp _loop

_return:
	pop ecx
	pop ebx

	leave
	ret