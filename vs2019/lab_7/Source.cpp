#include<stdio.h>
#include <locale.h>
#define N 5
#define IN_FILE_NAME "D:\\github\\vs2019\\lab_7\\test_4.txt"
#define OUT_FILE_NAME "D:\\github\\vs2019\\lab_7\\result.txt"
void input_from_any(int a[N][N], bool is_stdin)
{
	FILE* in_file;
	int err_fopen = 0;
	if (is_stdin) {
		in_file = stdin;
		printf("Введите значения элементов матрицы a[%d][%d], всего %d\n", N,
			N, N * N);
	}
	else {
		err_fopen = fopen_s(&in_file, IN_FILE_NAME, "r");
	};
	if (err_fopen == 0) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				fscanf_s(in_file, "%d", &a[row][col]);
			}
		};
		if (!is_stdin) {
			fclose(in_file);
		}
	}
	else {
		printf("Код ошибки fopen_s = %d\n", err_fopen);
	}
}
void input_from_keyboard(int a[N][N])
{
	input_from_any(a, true);
}
void input_from_file(int a[N][N])
{
	input_from_any(a, false);
}

int main()
{
	return 0;
}