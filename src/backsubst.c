#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int r = mat->r;
	int c = mat->c;
	double **data = mat->data;
	if (r != c || x->c != 1 || b->c != 1)
		return 2;

	for (int w = 0; w < r; w++)
		if (data[w][w] == 0)
			return 1;

	for (int w = r-1; w>= 0; w--) {
		double s = 0;
		for (int k = w+1; k < c; k++)
			s += data[w][k] * x->data[0][k];
		x->data[w][0] = (b->data[w][0]-s) / data[w][w];
	}
	return 0;
}


