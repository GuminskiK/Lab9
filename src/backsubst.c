#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
                /**
                 * Tutaj należy umieścić właściwą implemntację.
                **/
        /* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */
        // Matrix[wiersz][kolumna]
        // Zaczynamy od ostatniego wiersza
        const int ilosc_rownan = x->r;
		const int ilosc_kolumn = x->r;
		// Sprawdza czy wymiary są poprawne
        if(x->r != mat->r || mat->r != mat->c || x->c != 1 || b->c != 1 || b->r != x->r) return 2;

		// Zaczynając od ostatniego równania przeczhodzi przez wszystkie
        for (int r = ilosc_rownan - 1; r >= 0; r--) {
				
                const double    mat_a = mat->data[r][r];
                const double    mat_b = b->data[r][0];
                double*                 mat_x = &(x->data[r][0]);

				// Jeżeli wartość na diagonali macierzy to 0 to zwróć wartość 1 
                if(mat_a == 0) return 1;
                // a_1 * x_1 + a_2 * x_2 + a_3 * x_3 = b
                // x_1 = (b - a_2 * x_2 - a_3 * x_3)/a_1
                *mat_x = 0;
                for(int i2 = 0; i2 < ilosc_kolumn; i2++) {
                        *mat_x -= mat->data[r][i2] * x->data[i2][0];
                }
				*mat_x += mat_b;
                *mat_x /= mat_a;

        }

        return 0;
}