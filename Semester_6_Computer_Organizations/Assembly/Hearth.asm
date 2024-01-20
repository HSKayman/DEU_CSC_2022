hearth segment

	assume cs:hearth
	mov dl,03h
	mov ah,02h
	int 21h

	mov dl,07h
	mov ah,02h
	int 21h

	int 20h

hearth ends

	end





