#include <stdio.h>
#include <locale.h>

void out_matr(int** matr, int dim) {
	for (int row = 0; row < dim; row++) {
		for (int col = 0; col < dim; col++) {
			printf("%d \t", matr[col][row]);
		}
		printf("\n");
	}
}

void reset_column(int** matr, int dim, int col) {
	for (int row = 0; row < dim; row++) {
		 matr[col][row] = 0;
	}
}

bool is_equal(int** matr, int dim, int col1, int col2) {
	for (int row = 0; row < dim; row++) {
		if (matr[col1][row] != matr[col2][row]) {
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
	int* col_pos_cnt;
	col_pos_cnt = new int[n]();
	int** a, row, col;
	a = new int* [n];
	for (col = 0; col < n; col++) {
		a[col] = new int[n];
		printf("Введите %d  целых чисел столбца %d \n", n, col);
		for (row = 0; row < n; row++) {
			scanf_s("%d", &a[col][row]);
			if (a[col][row] > 0) {
				col_pos_cnt[col] = col_pos_cnt[col] ++;
			};
		};
	};
	printf("Исходная матрица a[%d][%d]\n", n, n);
	out_matr(a, n);
	for (col = 0; col < n; col++) {
		printf("Столбец 0 и столбец %d %s эквивалентны\n", col, (is_equal(a, n, 0, col)? "": "НЕ"));
		reset_column(a, n, col);
	}

	printf("Матрица a[%d][%d] после изменения\n", n, n);
	out_matr(a, n);
	delete[]a;
	return 0;
}
