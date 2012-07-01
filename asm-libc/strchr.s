section .text

global strchr

strchr:
	;; prologue
	push ebp
	mov ebp, esp

	push ecx
	
	mov eax, [ebp + 8]	; str
	mov cl,  [ebp + 12]	; c

_loop:
	mov ch, [eax]		; store current char in ch

	cmp ch, 0		; null == end of string
	je _empty
	cmp ch, cl		; char found
	je _return

	jmp _inc

;; index++

_inc:
	inc eax
	jmp _loop

;; return values
	
_return:
	pop ecx
	leave
	ret

_empty:
	cmp cl, 0
	je _return
	mov eax, 0
	pop ecx
	leave
	ret