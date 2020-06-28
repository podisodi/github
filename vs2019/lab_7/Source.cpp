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
void output_to_any(const int a[N][N], const int x[N], int y, bool is_stdout)
{
	FILE* outfile;
	int err_fopen = 0;
	if (is_stdout) {
		outfile = stdout;
	}
	else {
		err_fopen = fopen_s(&outfile, OUT_FILE_NAME, "w");
	};
	if (err_fopen == 0) {
		fprintf(outfile, "Матрица a[%d][%d]:\n", N, N);
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				fprintf(outfile, "%d\t", a[row][col]);
			};
			fprintf(outfile, "\n");
		};
		fprintf(outfile, "Массив x[%d] для попарного сравнения диагоналей
			матрицы a[% d][% d]:\n", N, N, N);
			for (int row = 0; row < N; row++) {
				fprintf(outfile, "%d\t", x[row]);
			};
		fprintf(outfile, "\n");
		fprintf(outfile,
			"Значение y = %d числа нечетных элементов %dго столбца матрицы
			a[% d][% d]:\n", y, 1, N, N);
			if (!is_stdout) {
				fclose(outfile);
			}
	}
	else {
		printf("err_fopen = %d", err_fopen);
	};
}
void output(const int a[N][N], const int x[N], int y)
{
	output_to_any(a, x, y, false);
	output_to_any(a, x, y, true);
}
int main()
{
	return 0;
}