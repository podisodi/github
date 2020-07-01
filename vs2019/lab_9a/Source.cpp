#include <stdio.h>
#include <locale.h>
#include <algorithm>

void out_matr(int** matr, int dim) {
	for (int row = 0; row < dim; row++) {
		for (int col = 0; col < dim; col++) {
			printf("%d \t", matr[col][row]);
		}
		printf("\n");
	}
}

void reset_column(int*col, int dim) {
	for (int row = 0; row < dim; row++) {
		 col[row] = 0;
	}
}

void sort_column(int *col, int dim) {
	for (int startIndex = 0; startIndex < dim - 1; ++startIndex) {
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < dim; ++currentIndex) {
			if (col[currentIndex] < col[smallestIndex])
				smallestIndex = currentIndex;
		}
		std::swap(col[startIndex], col[smallestIndex]);
	}
}
bool is_equal(int* col1, int* col2, int dim) {
	for (int row = 0; row < dim; row++) {
		if (col1[row] != col2[row]) {
			return false;
		}
	}
	return true;
}

int main() {
	setlocale(LC_CTYPE, "");
	printf("Введите число n - размерность матрицы a[n][n] ");
	int n;
	scanf_s("%d", &n);
	int** a, row, col;
	a = new int* [n];
	for (col = 0; col < n; col++) {
		a[col] = new int[n];
		printf("Введите %d  целых чисел, не равных 0, столбца %d \n", n, col);
		for (row = 0; row < n; row++) {
			do {
				scanf_s("%d", &a[col][row]);
				if (a[col][row] == 0) {
					printf("Недопустимое значение 0, повторите ввод!\n");
				}
			} while (a[col][row] == 0);
		};
	};
	printf("Исходная матрица a[%d][%d]\n", n, n);
	out_matr(a, n);
	for (col = 0; col < n; col++) {
		sort_column(a[col], n);
	}
	for (int start_col = 0; start_col < n - 1; start_col++) {
		for (col = start_col+1; col < n; col++) {
			if (is_equal(a[start_col], a[col], n)) {
				reset_column(a[col], n);
				printf("Столбец %d и столбец %d  эквивалентны\n", start_col, col );
			}
		}
	}
	printf("Матрица a[%d][%d] после изменения\n", n, n);
	out_matr(a, n);
	delete[]a;
	return 0;
}
