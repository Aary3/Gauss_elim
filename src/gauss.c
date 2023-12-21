#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	double dzielnik;		
	double wielk;
	double maks=0;
	int mrzad;
	double kopia;
	for(int i=0;i<mat->r;i++){
		for(int j=i;j<mat->r;j++){//znajduje maks a i zapisuje "lokacje"
			if(mat->data[j][i]>maks){
				mrzad=j;
				maks=mat->data[j][i];
			}
		}
		if(mrzad!=i){	//jesli maks nie w schodkowo pierwszej linii
			kopia=b->data[i][0];
			b->data[i][0]=b->data[mrzad][0];
			b->data[mrzad][0]=kopia;	//podmiana wynikow
			for(int j=0;j<c;j++){//to zamien je miejscami
				kopia=mat->data[i][j];
				mat->data[i][j]=mat->data[mrzad][j];
				mat->data[mrzad][j]=kopia;
			}
		}
		dzielnik=mat->data[i][i]; //dzielnik=a dla ax
		if(dzielnik==0)
			return 1; //czyosobliwa(niepowinno byc po znalezeniu elem gl.
		for(int j=i+1;j<mat->c;j++){//petla przechodzi po kolejnych rownaniach
			wielk=mat->data[j][i]; //wielk=ax dla kolejnych rownan
			b->data[j][0]-=b->data[i][0]*wielk/dzielnik;	//odejmowanie wyniku
			for(int k=i;k<mat->r;k++){//odejmowanie reszty
				mat->data[j][k]-=mat->data[i][k]*wielk/dzielnik;		
			}
		}
	}
	return 0;
}

