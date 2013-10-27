CardRotation
============

	***	Logica problemei	***
	
Avand o matrice data, o putem "invarti" in 8 moduri posibile, obtinand 8 matrici:

	IDENTIC ------ chiar matricea initiala
	T90 ---------- matricea rotita in sens trigonometric 90 de grade
	T180 --------- ......................................180........
	T270 --------- ......................................270........
	V ------------ matricea oglindita pe vertical, numita in continuare verticala
	VT90 --------- verticala rotita in sens trigonometric 90 de grade
	VT180 -------- .......................................180........
	VT270 -------- .......................................270........
		
Deducem 3 formule pentru a determina cum rotim in sens trigonometric 90, 180, respectiv 270 de grade
o matrice data. Astfel, aplicand aceste formule cartelei initiale putem obtine matricele T90, T180 si T270,
iar aplicand formulele verticalei, obtinem VT90, VT180 si VT270. Formulele sunt:

	T90 [i][j] = cartela [j]     [N-1-i]
	T180[i][j] = cartela [N-1-i] [N-1-j]
	T270[i][j] = cartela [N-1-j] [i]
	V   [i][j] = cartela [i]     [N-1-j]
.
	
	***	Implementarea	***
	
Pasii in rezolvarea problemei sunt:
	
1.  Se citesc dimensiunea cartelei si numarul de sabloane
2.  Se citeste cartela
3.  Se construieste verticala
4.  Printr-o singura parcurgere a sablonului se verifica daca sablonul corespunde cu vre-una din matricele rotite.
	Aceasta verificare se realizeaza prin atribuirea valorilor de 0 sau 1 ok-urilor denumite sugestiv.
5.	 Daca o ok-ul corespunzator unui rotiri este 1, se afiseaza denumirea rotirii si se trece la urmatorul sablon.
	Daca nu corespunde cu nicio rotire, va fi afisat mesajul "NU"
