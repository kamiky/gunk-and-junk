section .text

global strcasecmp

strcasecmp:
	;; prologue
	push ebp
	mov ebp, esp

	push ebx
	push ecx
	push edx
	push esi
	
	;; args
	mov ebx, [ebp + 8] 	; str1
	mov ecx, [ebp + 12]	; str2
	mov edx, 0		; index
	
;; plusieurs cmp necessaires ?
_loop:
	call _handle_case
	
	cmp ah, al		; while equal
	je _incr		; inc

	;; end of string ?
	cmp ah, 0
	je _lower
	
	cmp al, 0
	je _greater
	;; compare value
	cmp ah, al
	jg _greater
	cmp ah, al
	jl _lower

;; Index++ 

_incr:
	cmp al, 0
	je _equal
	inc edx
	jmp _loop

;; Return values
	
_greater:
	mov eax, 1
	jmp _leave
_lower:
	mov eax, -1
	jmp _leave
_equal:
	mov eax, 0
_leave:	
	pop esi
	pop edx
	pop ecx
	pop ebx
	leave
_return:
	ret

;; cases

_handle_case:
	mov ah, [ecx + edx]
	call _lowercase
	mov al, ah
	mov ah, [ebx + edx]	; for each char
	call _lowercase
	ret
	
_no_case:
	mov al, [ecx + edx]	
	mov ah, [ebx + edx]
	ret
	
_lowercase:
	cmp ah, 'A'
	jb _return
	cmp ah,'Z'
	jg _return
	add ah, 32
	ret	