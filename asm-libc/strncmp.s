section .text

global strncmp

strncmp:
	;; prologue
	push ebp
	mov ebp, esp

	;; reg save
	push ebx
	push ecx
	push edx
	push esi
	
	mov ebx, [ebp + 8]	; str1
	mov ecx, [ebp + 12]	; str2
	mov edx, [ebp + 16]	; n
	mov esi, 0		; index

	cmp edx, 0
	je _equal
	
_loop:
	cmp edx, esi		; i == n ?
	je _cmp

	mov ah, [ebx + esi]
	mov al, [ecx + esi]

	cmp ah, al		; i++
	je _incr

_cmp:
	cmp ah, 0		;  end of string ?
	je _lower
	cmp al, 0
	je _greater
				;;  compare
	cmp ah, al
        jg _greater
	cmp ah, al
	jl _lower

	cmp ah, al
	je _equal
	
_incr:
	cmp al, 0		; end of string !!
	je _equal
	inc esi
	jmp _loop

_greater:
	mov eax, 1
	jmp _return
_lower:
	mov eax, -1
	jmp _return
_equal:
	mov eax, 0
_return:
	pop esi
	pop edx
	pop ecx
	pop ebx

	leave
	ret