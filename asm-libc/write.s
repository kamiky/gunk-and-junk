section .text

global write
extern __errno_location
	
write:
	;; prologue
	push ebp
	mov ebp, esp

	push ebx
	push ecx
	push edx

	mov ebx, [ebp + 8]
	mov ecx, [ebp + 12]
	mov edx, [ebp + 16]

	mov eax, 4
	int 0x80

	cmp eax, -4096
	ja _error
	

_return:
	pop edx
	pop ecx
	pop ebx

	leave
	ret

_error:
	mov ebx, eax            ; store error return value in ebx
	call __errno_location   ; get errno
	neg  ebx                ; get error code
	mov dword [eax], ebx 	; setting errno
	mov eax, -1
	jmp _return
	
	