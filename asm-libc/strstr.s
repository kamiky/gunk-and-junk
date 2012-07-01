section .txt

extern strlen
extern strncmp

global strstr

;; WRONG, old copy, not working

_strstr:
	;; prologue
	push ebp
	mov esp, ebp

	;; sauvegarder les donnees avant de mov

	mov ebx, [ebp + 8]
	mov ecx, [ebp + 12]
	push ecx
	call strlen
	pop ecx
	mov edx, eax

_loop:
	cmp byte [ebx], 0
	je _end
	
	push edx
	push ecx
	push ebx
	call strncmp
	pop ebx
	pop ecx
	pop edx

	cmp eax, 0
	je _return

	inc ebx
	jmp _loop

_return:
	mov eax, ebx
	leave
	ret

_end:
	mov eax, 0
	leave
	ret
