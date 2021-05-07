#include <iostream>

using namespace std;

typedef int Data;

typedef struct snode {
	Data value;
	struct snode * next;
}tNode;

void addObject(tNode** plist, Data d);
void show(tNode* list);
Data delObject(tNode** plist);
void searchLinear(tNode* list);
int searchBinary(int arr[], int left, int right);

int main() {

	setlocale(LC_ALL, "rus");

	tNode* list = NULL;

	int quantity;

	cout << "Enter the quantity of list: ";
	cin >> quantity;

	cout << "Enter the elements of list: \n";
	
	int value;

	for (size_t i = 0; i < quantity; i++)
	{
		cin >> value;
		addObject(&list, value);
	}

	show(list);

	searchLinear(list);

	int* arr = new int[sizeof(int)];

	int quanelem;
	cout << "Enter the quantity of elements of array: ";
	cin >> quanelem;

	for (int i = 0; i < quanelem; i++)
	{
		arr[i] = rand() % 100;
	}

	for (int i = 0; i < quanelem; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	int elem = searchBinary(arr, 0, quanelem);

	cout << "Index of searching element is: " << elem << endl;

}

void addObject(tNode** plist, Data d) {

	tNode* p = new tNode[sizeof(tNode)];

	p->value = d;
	p->next = *plist;
	*plist = p;

}

void show(tNode* list) {

	printf("List: ");

	for (tNode* p = list; p != NULL; p = p->next)
	{
		printf("%d ", p->value);
	}

	printf("\n");
}

Data delObject(tNode** plist) {

	if (*plist == NULL) {
		return 0;
	}
	else {
		tNode* p = *plist;
		Data res = p->value;
		*plist = p->next;
		free(p);

		return res;
	}
}

void searchLinear(tNode*list) {

	int necessaryValue;

	cout << "Введите значение для поиска: ";
	cin >> necessaryValue;

	int i = 0;

	for (tNode* p = list; p != NULL; p = p->next)
	{
		if (necessaryValue == p->value)
		{
			printf("Индекс найденого значения: %d\n", i);
		}
		i++;
	}

}

int searchBinary(int arr[], int left, int right) {

	int necessaryValue;

	cout << "Введите значение для поиска: ";
	cin >> necessaryValue;

	int midd = 0;

	while (1) {
		midd = (left + right) / 2;

		if (necessaryValue < arr[midd])
			right = midd - 1;
		else if (necessaryValue > arr[midd])
			left = midd - 1;
		else
			return midd;

		if (left > right)
			return -1;
	}

}