#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	double dzielnik;
	double wielk;
	for(int i=0;i<mat->c;i++){
		dzielnik=mat->data[i][i]; //dzielnik=a dla ax
		if(dzielnik==0)
			return 1; //czyosobliwa
		b->data[i][0]/=dzielnik; //dzielenie wyniku na start
		for(int j=i;j<mat->r;j++){//normalizacja rownania
			mat->data[i][j]/=dzielnik;
		}
		for(int j=i+1;j<mat->c;j++){//petla przechodzi po kolejnych rownaniach
			wielk=mat->data[j][i];
			b->data[j][0]-=b->data[i][0]*wielk;	//odejmowanie wyniku
			for(int k=i;k<mat->r;k++){//odejmowanie reszty
				mat->data[j][k]-=mat->data[i][k]*wielk;		
			}
		}
	}
	return 0;
}

