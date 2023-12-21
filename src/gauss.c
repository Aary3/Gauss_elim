#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	double dzielnik;
	for(int i=0;i<mat->c-1;i++){
		int max = i;
		for(int j=i+1;j<mat->r;j++){//normalizacja rownania
			if (mat->data[j][i] > mat->data[max][i] )
				max = j;
		}
		if (max != i ) {			//znajdywanie najwiekszej liczby
			double *tmp = mat->data[i];
			mat->data[i] = mat->data[max];
			mat->data[max] = tmp;
			double bt = b->data[max][0];
			b->data[max][0] = b->data[i][0];
			b->data[i][0] = bt;
		}
		for(int j=i+1;j<mat->c;j++){//petla przechodzi po kolejnych rownaniach wielk=mat->data[j][i];
			if (mat->data[i][i] == 0)
				return 1;	//dzielenie przez 0
			dzielnik = mat->data[j][i] / mat->data[i][i];
			for(int k=i;k<mat->r;k++){//odejmowanie reszty
				mat->data[j][k]-=mat->data[i][k]*dzielnik;		
			}
			b->data[j][0] -= b->data[i][0]*dzielnik;
		}
	}
	return 0;
}

