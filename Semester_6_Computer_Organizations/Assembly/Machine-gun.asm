tufek segment

ana_program	proc far

	assume cs:tufek
	org 100h
	
basla:
	mov cx,1	;mermi sayısı
	
ates_et:
	push cx		;LIFO ile alta aldik pointeri
	call ates	;ates isminde ki alt programı çağır
	mov si,4	;iki atış arasındaki sessizlik için
	
iki_atis_arasi:
	cmp si,0	;si reg'in içini 0 ile karşılaştır  FLAGS 
	je iki_atis_arasi_sonu
	call sessizlik
	dec si
	jmp iki_atis_arasi
	
iki_atis_arasi_sonu:
	pop cx
	loop ates_et
	int 20h

ana_program endp


ates proc near 
	mov dx,300h    ;data
	mov bx,20h		;???
	in al,61h    	;port mort
	and al,11111100b ; andleme isi
ses:
	xor al,2  	;xor lama islemi ama neyle????????						
	out 61h,al  ; 61. portakini aporlore ver
	add dx,1649h  ;random seed
	mov cl,3  		;count left =3
	ror dx,cl 		;datanin icine count left kadar kaydir
	mov cx,dx       ;dx i cx e at
	and cx,01FFh    ; ust limit alt limit
	or cx,10        ; aslinda bu alt
	
bekle:
	loop bekle
	dec bx
	jnz ses
	and al,11111100b
	out 61h,al
	
	ret
ates endp
	
	
sessizlik proc near
	mov cx,0h
ara_ver:
	loop ara_ver	
	ret
sessizlik endp

tufek ends

end basla
	
	