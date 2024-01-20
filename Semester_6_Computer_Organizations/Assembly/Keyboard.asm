display equ 02h
doscagir equ 21h

klavye segment

ana_prog proc far
	assume cs:klavye
basla:
	mov ah,0
	int 16h
	mov bx,ax
	
	call binheks
	
	mov dl,20h  ;ascii bosluk
	mov ah,display
	int doscagir
	
	mov dl,bl    ;ascii bl 
	mov ah,display
	int doscagir
	
	mov dl,0Dh ;ascii new line
	mov ah,display
	int doscagir
	
	mov dl,0Ah  ;ascii start of line
	mov ah,display
	int doscagir
	
	jmp basla
ana_prog endp

binheks proc near

	mov ch,4
	mov cl,4

dondur:
	rol bx,cl
	mov al,bl
	and al,0Fh
	add al, 30h
	cmp al, 3Ah
	jl ekrana
	add al,07h
ekrana:
	mov dl,al
	mov ah,02h
	int doscagir
	dec ch
	jnz dondur
	
	ret
binheks endp	

klavye ends

end basla
	
	
	
	
	
	
	
	
	
	
	