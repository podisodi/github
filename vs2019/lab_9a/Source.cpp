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
	printf("������� ����� n - ����������� ������� a[n][n] ");
	int n;
	scanf_s("%d", &n);
	int* col_pos_cnt;
	col_pos_cnt = new int[n]();
	int** a, row, col;
	a = new int* [n];
	for (col = 0; col < n; col++) {
		a[col] = new int[n];
		printf("������� %d  ����� ����� ������� %d \n", n, col);
		for (row = 0; row < n; row++) {
			scanf_s("%d", &a[col][row]);
			if (a[col][row] > 0) {
				col_pos_cnt[col] = col_pos_cnt[col] ++;
			};
		};
	};
	printf("�������� ������� a[%d][%d]\n", n, n);
	out_matr(a, n);
	for (col = 0; col < n; col++) {
		sort_column(a[col], n);
		printf("������� 0 � ������� %d %s ������������\n", col, (is_equal(a[0],a[col], n) ? "" : "��"));
		//reset_column(a[col], n);
	}

	printf("������� a[%d][%d] ����� ���������\n", n, n);
	out_matr(a, n);
	delete[]a;
	return 0;
}
