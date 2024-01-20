
k_shift_statu equ 02h
bioscagir equ 16h 
display equ 02h
doscagir equ 21h

car_ret equ 0Dh

k_shift segment

ana_prog proc far
	assume cs:k_shift
basla:
	mov ah,k_shift_statu    ;klavyeden oku
	
	int bioscagir          ;
	
	mov bx,ax  				;
	
	call binheks
	
	mov dl,car_ret     ;Enter + Basa Al        
	mov ah,display
	int doscagir
	
	jmp basla 
	
	ret ;return
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

k_shift ends

end basla
	
	
	
	
	
	
	
	
	
	
	