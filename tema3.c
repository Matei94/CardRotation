//		Matei Razvan-Madalin
//		313CA

#include<stdio.h>

//citeste o matrice patratica
void citire(int [][50], int);

//calculeaza matricea oglindita pe verticala dupa cartela data 
void verticala(int [][50], int [][50], int);

//afiseaza ce mutari se fac cartelei initiale pentru a ajunge la sablonul dat
void afisari(int [][50], int [][50], int [][50], int, int);

int main() {

	int i, j, N, M,
	    cartela[50][50],
		 sablon[50][50],
		 V[50][50];
	
	//se citesc dimensiunea matricei si numarul se sabloane
	scanf("%d %d", &N, &M);
	
	//se citeste cartela
	citire(cartela, N);
	
	//se calculeaza oglindita pe verticala a cartelei
	verticala(V, cartela, N);
	
	//se afiseaza mutarile ce trebuie facute pentru a ajunge la fiecare sablon in parte
	afisari(cartela, V, sablon, N, M);

	return 0;
}

void citire(int cartela[][50], int N) {
	int i, j;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &cartela[i][j]);
		}
	}
}

void verticala(int V[][50], int cartela[][50], int N) {
	int i, j;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			V[i][j] = cartela[i][N-1-j];
		}
	}
}

void afisari(int cartela[][50], int V[][50], int sablon[][50], int N, int M) {
	int okIDENTIC, okT90, okT180, okT270, okV, okVT90, okVT180, okVT270;
	int i, j, count=0;
	do {
		okIDENTIC=1;
		okT90=1; 
		okT180=1; 
		okT270=1; 
		okV=1;
		okVT90=1; 
		okVT180=1; 
		okVT270=1; 
	
		citire(sablon, N);
		count++;
		
		for(i=0; i<N; i++) {
			for(j=0; j<N; j++) {
				if(sablon[i][j] != cartela [i][j]) {
					okIDENTIC=0;
				}
				if(sablon[i][j] != cartela[j][N-1-i]) {
					okT90=0;
				}
				if(sablon[i][j] != cartela[N-1-i][N-1-j]) {
					okT180=0;
				}
				if(sablon[i][j] != cartela[N-1-j][i]) {
					okT270=0;
				}
				if(sablon[i][j] != V[i][j]) {
					okV=0;
				}
				if(sablon[i][j] != V[j][N-1-i]) {
					okVT90=0;
				}
				if(sablon[i][j] != V[N-1-i][N-1-j]) {
					okVT180=0;
				}
				if(sablon[i][j] != V[N-1-j][i]) {
					okVT270=0;
				}
			}
		}
		if(okIDENTIC==1) {
			printf("IDENTIC\n");
			continue;
		}
		
		if(okT90==1) {
			printf("T90\n");
			continue;
		}
		
		if(okT180==1) {
			printf("T180\n");
			continue;
		}
		
		if(okT270==1) {
			printf("T270\n");
			continue;
		}
		
		if(okV==1) {
			printf("V\n");
			continue;
		}
		
		if(okVT90==1) {
			printf("V T90\n");
			continue;
		}
		
		if(okVT180==1) {
			printf("V T180\n");
			continue;
		}
		
		if(okVT270==1) {
			printf("V T270\n");
			continue;
		}
		
		printf("NU\n");

	} while (count < M);
}
