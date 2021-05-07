/**
* @author Ermakov M.
* @date 14.04.2021
* @brief EXERCISE №6
*/

#include <iostream>
#include <vector>

using namespace std;

typedef char Data;

typedef struct Node Node;
struct Node
{
	Data data;
	Node* next;
};

void addObject(Node** plist, Data d);
Data delObject(Node** plist);
void show(Node * list);
void vectorReg(int F);
void blockOutput(int F);

int main() {

	setlocale(LC_ALL, "rus");
	
	char choose;

	cout << "Enter if vector - 'v', if block - 'b': ";
	cin >> choose;

	if (choose == 'v')
	{
		//регулируем длину вектора
		int F;

		cout << "Vector length: " << endl;
		cin >> F;

		//вывод вектора с регулированной длиной
		vectorReg(F);

	}
	else if (choose == 'b')
	{
		//регулируем длину списка
		int F;

		cout << "Block length: " << endl;
		cin >> F;

		//вывод списка
		blockOutput(F);
	}
	else
	{
		cout << "Invalid entered value. Enter if vector - 'v', if block - 'b'";
	}

	return 0;
}

void vectorReg(int F) {

	char* arrayInt = new char[F];
	vector <char> s;	//вектор размером на F элементов

	for (int i = 0; i < F; ++i)	//заполнение массива из F элементов числом 1
	{
		cin >> arrayInt[i];
	}

	for (int i = 0; i < F; i++)
	{
		s.push_back(arrayInt[i]);
	}

	cout << "Vector contains: " << ends;
	for (int i = 0; i < F; ++i)
		cout << s[i] << ends; //вывод на экран
	cout << endl;

	vector <char> str;

	//с какого по какой символ вектора выводим
	int m;
	int n;

	cout << "Begin: " << ends;
	cin >> m;

	cout << "How many: " << ends;
	cin >> n;

	if ((m + n) < F) {
		for (int i = m; i < n + m; i++)
		{
			str.push_back(arrayInt[i]);
		}
		cout << "Finish vector contains: ";
		for (int i = 0; i < n; ++i)
			cout << str[i] << ends;//вывод на экран
		cout << endl;
	}
	else
	{
		cout << "Segmentation fault! The summ of begin and quantity had to be not less and not equal to summ of begging vector" << endl;
	}

}

void blockOutput(int F) {
	char* arrayInt = new char[F];

	for (int i = 0; i < F; i++)	//заполнение массива из F элементов числом 1
	{
		cin >> arrayInt[i];
	}

	Node* list = NULL;

	for (int i = F-1; i >= 0; --i)	//заполнение массива из F элементов числом 1
	{
		addObject(&list, arrayInt[i]);
	}

	show(list);


	delObject(&list);

	//с какого по какой символ вектора выводим
	int m;
	int n;

	cout << "Begin: " << ends;
	cin >> m;

	cout << "How many: " << ends;
	cin >> n;

	if ((m + n) < F) {

		for (int i = n + m-1; i >= m; i--)
		{
			addObject(&list, arrayInt[i]);
		}

		show(list);
	}
	else
	{
		cout << "Segmentation fault! The summ of begin and quantity had to be not less and not equal to summ of begging vector" << endl;
	}
}

void addObject(Node** plist, Data d) {

	Node* p = new Node[sizeof(Node)];

	p->data = d;
	p->next = *plist;
	*plist = p;

}

void show(Node* list) {

	printf("List: ");

	for (Node * p = list; p != NULL; p = p->next)
	{
		printf("%c", p->data);
	}

	printf("\n");
}

Data delObject(Node** plist) {

	if (*plist == NULL) {
		return 0;
	}
	else {
		Node* p = *plist;
		Data res = p->data;
		*plist = p->next;
		free(p);

		return res;
	}
}
