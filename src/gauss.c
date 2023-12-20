#include "gauss.h"
#include "math.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int findMain(Matrix* mat, int column){
	double biggestValue = -1;
	int biggestIndex = -1;
	
	for(int i = 0; i < mat->r; i++) {
		double value = fabs(mat->data[i][column]);
		if(value > biggestValue) {
			biggestValue = value;
			biggestIndex = i;
		}	
	}
	return biggestIndex;
}

int eliminate(Matrix *mat, Matrix *b){
    
	if (mat->r != mat->c){
		return 1;
	}
	int i;	
	for(i = 0; i < mat->r - 1 ; i++ ){ // pętla po przekątnej; gdy jesteśmy w ostatnim wierszu to kończymy dlatego r-1
	
		int main = findMain(mat, i);

		swapRows(mat, i, main);
		swapRows(b, i, main);

		if(mat->data[i][i] == 0){ // macierz osobliwa?
			return 1;
		}

		for (int j = i + 1; j < mat->r; j++){  // pętla liczy dla każdego wiersza wsp
			if(mat->data[j][i] == 0) { //dzielenie przez 0
				return 1;	
			} 
			double wsp = mat->data[j][i] / mat-> data[i][i]; // wsp to współczynnik
			for (int g = i; g < mat->r; g++ ){ // pętla odejmuje wektor;
				mat->data[j][g] -= mat->data[i][g] * wsp; //odejmowanie wektora
			}
			b->data[j][0] -= b->data[i][0] * wsp;
		}
		
	}

	if(mat->data[i][i] == 0){
                        return 1; // macierz osobliwa?
        }

	return 0;
}

