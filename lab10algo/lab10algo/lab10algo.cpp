/**
* @author Matthew Ermakov <mazdaraser.91@gmail.com>
* @brief Laboratory work №10
* @date 06.05.2021 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#define N 50000

using namespace std;

typedef struct sNode {
	int protocol;
	int operatingSystem;
	struct sNode* next;
} tNode;

typedef struct {
	int index;
	tNode* table;
} Table;

string mass[N * 3];
Table tab[N];

int shash(string num);
void addObject(tNode** plist, int os, int protocol);
void show(tNode* list);
int delObject(tNode** plist);
void colisionSolving(Table* tab);
void fullkey(Table* tab, string mass[N * 3]);
void writetofile(string mass[N * 3]);

int main() {

	for (size_t i = 0; i < N; i++)
	{
		tab[i].table = NULL;
	}

	writetofile(mass);

	fullkey(tab, mass);

	int k = 0;

	for (size_t i = 0; i < N; i += 3)
	{
		if (mass[i + 1] != "" && mass[i + 2] != "")
			addObject(&tab[k].table, stoi(mass[i + 1]), stoi(mass[i + 2]));

		k++;
	}

	for (size_t i = 0; i < N / 3; i++)
	{
		cout << "Key: " << tab[i].index << " ";
		show(tab[i].table);
	}

	clock_t begin=clock(), end;


	colisionSolving(tab);

	end = clock();

	cout << "Time executing: " << end - begin << "ms" << endl;

}

void writetofile(string mass[N * 3]) {

	ofstream fin;
	int num;
	string path = "data.txt";
	fin.open(path, ios::out);

	for (int y = 0; y < N; y++) {

		num = rand() % N * 2;

		fin << num << endl;

	}

	fin.close();

	ifstream fout;

	fout.open(path);

	int i = 0;

	while (!fout.eof()) {

		fout >> mass[i];

		i++;
	}

	fin.close();
}

int shash(string num) {
	int res = stoi(num) % N;
	return res;
}

void fullkey(Table* tab, string mass[N * 3]) {
	int k = 0;
	for (size_t i = 0; i < N; i += 3)
	{

		tab[k].index = shash(mass[i]);
		k++;

	}

}

void addObject(tNode** plist, int os, int protocol) {

	tNode* p = new tNode[sizeof(tNode)];

	p->operatingSystem = os;
	p->protocol = protocol;
	p->next = *plist;
	*plist = p;

}

void show(tNode* list) {

	for (tNode* p = list; p != NULL; p = p->next)
	{
		cout << "OS: " << p->operatingSystem << " ";
		cout << "Protocol: " << p->protocol;
		cout << " ";
	}

	printf("\n");
}

int delObject(tNode** plist) {

	if (*plist == NULL) {
		return 0;
	}
	else {
		tNode* p = *plist;
		int res = p->operatingSystem;
		*plist = p->next;
		free(p);
	}
}

void colisionSolving(Table* tab) {

	for (size_t i = 0; i < N / 3; i++)
	{
		for (size_t j = N / 3; j > 0; j--)
		{
			if (tab[i].index == tab[j - 1].index)
			{
				addObject(&tab[i].table, tab[j - 1].table->operatingSystem, tab[j - 1].table->protocol);
				tab[j - 1].table->operatingSystem = NULL;
				tab[j - 1].table->protocol = NULL;
			}
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		delObject(&tab[i].table);
	}

	int size = 0;

	for (size_t i = 0; i < N / 3; i++)
	{
		if ((tab[i].table->operatingSystem != NULL))
		{
			size++;
		}
	}

	Table* fin = new Table[size];

	int k = 0;

	for (size_t i = 0; i < N / 3; i++)
	{
		if ((tab[i].table->operatingSystem != NULL))
		{
			fin[k] = tab[i];
			k++;
		}
	}

	cout << endl << "Colision solving: " << endl << endl;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Key: " << fin[i].index << " ";
		show(fin[i].table);
	}

	int  index = 82;

	cout << endl << "Find by index: ";
	//cin >> index;

	for (size_t i = 0; i < size; i++)
	{
		if (index == fin[i].index)
		{
			show(fin[i].table);
		}
	}

}

