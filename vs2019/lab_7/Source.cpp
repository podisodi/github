#include<stdio.h>
#include <locale.h>
#define N 5
#define IN_FILE_NAME "D:\\github\\vs2019\\lab_7\\test_0.txt"
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

int check_sort_row(const int a[N][N], int row)
{
	if (a[row][1] == a[row][0]) {
		return -1;
	}
	bool is_sort_asc = a[row][1] > a[row][0];
	bool is_sort_desc = a[row][1] < a[row][0];
	for (int col = 2; col < N; col++) {
		if (is_sort_asc && (a[row][col] <= a[row][col-1])) {
			return -1;
		}
		if (is_sort_desc && (a[row][col] >= a[row][col - 1])) {
			return -1;
		}
	}
	return 1;
}

int* check_sort_rows(int(*a)[N], int* x, void (*pfunc_input)(int[N][N]))
{
	pfunc_input(a);
	for (int row = 0; row < N; row++) {
		x[row] = check_sort_row(a, row);
	};
	return x;
}

void min_max_diag(const int a[N][N], int index, int& min, int& max)
{
	if (index == N) {
		return;
	}
	if (a[index][index] < min) {
		min = a[index][index];
	}
	if (a[index][index] > max) {
		max = a[index][index];
	}
	min_max_diag(a, index + 1, min, max);
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
		fprintf(outfile,
			"Массив x[%d] для попарного сравнения диагоналей матрицы a[% d][% d]:\n", N, N, N);
			for (int row = 0; row < N; row++) {
				fprintf(outfile, "%d\t", x[row]);
			};
		fprintf(outfile, "\n");
		fprintf(outfile, 
			"Значение y = %d числа нечетных элементов %dго столбца матрицы a[% d][% d]:\n", y, 1, N, N);
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
	setlocale(LC_CTYPE, "");
	int a[N][N];
	int x[N];
	int choice;
	void (*pfunc_input)(int[N][N]);
	printf("Выбор варианта ввода: 1 с кл-ры, 2 из файла\n", OUT_FILE_NAME);
	do {
		scanf_s("%d", &choice);
	} while ((choice != 1) && (choice != 2));
	pfunc_input = choice == 1 ? input_from_keyboard : input_from_file;
	check_sort_rows(a, x, pfunc_input);
	int min = a[0][0];
	int max = a[0][0];
	min_max_diag(a, 1, min, max);
	output(a, x, (min+max)/2);
	return 0;
}