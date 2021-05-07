/**
* @author Ermakov M.
* @date 30.03.2021
* @brief Physical performing of specifical arrays
* EXERCISE №5
*/

#include <iostream>
#define N 10

void RandArray(int a[N][N]);
void PrintArray(int a[N][N]);

void main() {
	int vec[N * N];

	int array[N][N];

	RandArray(array);
	PrintArray(array);

	/* ARRAY COMPRESSING */

	int index = 0;

	for (int y = 0; y < N; y++) {
		if (y % 2 == 1) {
			for (int i = 0; i < N; i++) {
				vec[index] = array[y][i];
				index++;
			}
		}
	}

	int size = 0; 

	if (N % 2 == 1) size = N * N / 2 + 1;
	else size = (N * N) / 2;
	for (int i = 0; i < size; i++) { //видача результату стиснення
		printf("%3i", vec[i]);
	}

	printf("\n\n");
	index = 0;
	for (int y = 0; y < N; y++) {
		if (y % 2 == 1) {
			for (int i = 0; i < N; i++) {
				printf("%3i", vec[index]);
				index++;
			}
		}
		else
		{
			for (int i = 0; i < N; i++) {
				printf("%3i", 0);
			}
		}
		printf("\n");
	}
}

/* FORMING THE BEGINNING ARRAY */

void RandArray(int a[N][N]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i % 2 == 0)
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = rand() % 50;
			}
		}
	}
}

/* ARRAY OUTPUT */

void PrintArray(int a[N][N]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%3i", a[i][j]);
		}

		printf("\n");
	}
}

