#include "gauss.h"
#include "math.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
void diagonal(Matrix *mat, int i, Matrix * b);
void change(Matrix *mat, int i, int maks, Matrix *b);

int findMain(Matrix* mat, int column){
	double biggestValue = -1;
	int biggestIndex = -1;
	
	for(int i = column; i < mat->r; i++) {
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
		return 2;
	}
	int i;	
	for(i = 0; i < mat->r - 1 ; i++ ){ // pętla po przekątnej; gdy jesteśmy w ostatnim wierszu to kończymy dlatego r-1
	
		int main = findMain(mat, i);

		swapRows(mat, i, main);
		swapRows(b, i, main);

		if(mat->data[i][i] == 0){ // macierz osobliwa?
			return 1;
		}

		diagonal(mat,i,b); //element diagonalny
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

void diagonal(Matrix *mat, int i, Matrix * b){

        int maks = i; 
        for (int h = i; h <mat->r; h++){ //szukamy najwyższej co do modułu wartości w kolumnie
                if (fabs(mat->data[h][i]) > fabs(mat->data[maks][i])){
                        maks = h;
                }

        }
        if( maks != i ){
                change(mat,i, maks,b);
        }

}

void change(Matrix *mat, int i, int maks, Matrix * b){

        double tmp;
        for ( int h = 0; h < mat->r; h++){ //zamiana w macierzy A

                tmp = mat->data[i][h];
                mat->data[i][h] = mat->data[maks][h];
                mat->data[maks][h] = tmp;


        }
        tmp = b->data[maks][0]; //zamiana w macirzy b
        b->data[maks][0] = b->data[i][0];
        b->data[i][0] = tmp;

}


