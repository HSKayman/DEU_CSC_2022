gurultu segment

ana_program proc far    ;ana program

	assume cs:gurultu
	org 100h			; com tipi dosyalar için offset ayarlama
	
basla:
	mov dx,300h		;bekleme süresi
	in al,61h		;61 nolu gate'in değerini al reg'e yükle
	and al,11111100b ;0. ve 1. bitleri sıfırla
ses:
	xor al,2		;al reg.'in 1. bitinin konumunu değiştir
	out 61h,al		;al reg'in değerini 61. porta gönder
	add dx,1649h	;tohum
	mov cl,3		; döndürme adedi
	ror dx,cl		; rotate right cl adet 
	mov cx,dx
	and cx,01FFh	;???
	or cx,10		;???
	
bekle:
	loop bekle
	
	jmp ses

ana_program	endp

gurultu ends

end basla
