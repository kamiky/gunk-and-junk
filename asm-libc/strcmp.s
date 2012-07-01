section .text

global strcmp
	
strcmp:
	;; prologue
	push ebp
	mov ebp, esp

	push ebx
	push ecx
	push edx
	
	;; args
	mov ebx, [ebp + 8] 	; str1
	mov ecx, [ebp + 12]	; str2
	mov edx, 0		; index
	
;; plusieurs cmp necessaires ?
_loop:
	mov ah, [ebx + edx]	; for each char
	mov al, [ecx + edx]

	cmp ah, al		; while equal
	je _incr		; inc

	;; end of string ?
	cmp ah, 0
	je _lower
	
	cmp al, 0
	je _greater
	
	;; compare
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

	pop edx
	pop ecx
	pop ebx
	
	leave
	ret

_lower:
	mov eax, -1

	pop edx
	pop ecx
	pop ebx

	leave
	ret

_equal:
	mov eax, 0

	pop edx
	pop ecx
	pop ebx

	leave
	ret