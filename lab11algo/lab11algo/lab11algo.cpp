#include <iostream>
#include <ctime>
#define N 15000

using namespace std;

void randFull(int mass[N]);
void outArr(int mass[N]);
void sortArr(int mass[N]);

int mass[N];

int main()
{
	randFull(mass);
	cout << "Beginning array: " << endl << endl;
	outArr(mass);
	clock_t start = clock(), end;
	sortArr(mass);
	end = clock();
	cout << endl << endl <<"Final array: " << endl << endl;
	outArr(mass);
	cout << end - start << endl;
}

void randFull(int mass[N]) {
	for (size_t i = 0; i < N; i++)
	{
		mass[i] = rand() % 10;
	}
}

void outArr(int mass[N]) {

	for (size_t i = 0; i < N; i++)
	{
		cout << mass[i] << " ";
	}
	
}

void sortArr(int mass[N]) {
	for (int i = 1; i < N; ++i)
	{
		int j = i - 1;
		int temp = mass[i];
		while (j >= 0 && temp < mass[j])
		{
			mass[j + 1] = mass[j];
			mass[j] = temp;
			j--;
		}
	}
}

