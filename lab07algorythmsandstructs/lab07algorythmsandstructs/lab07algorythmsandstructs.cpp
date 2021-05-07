/**
* @author Ermakov M.
* @date 26.04.2021
* @brief EXERCISE №7
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

//структура списка с указателями на следующий и предыдущий элемент списка и с самим значением из структуры выше
typedef struct _Node {
	int k;
	struct _Node* next;
	struct _Node* prev;
} Node;

//хвост, голову и размер списка обьявляем в структуре DblLinkedList
typedef struct _DblLinkedList {
	size_t size;
	Node* head;
	Node* tail;
} DblLinkedList;

void pushBack(DblLinkedList* list, int value);
DblLinkedList* createDblLinkedList();
void printDblLinkedList(DblLinkedList* list);
int popBack(DblLinkedList* list);
void stackOutput(int F);
bool iDel(int* array, int& lenAr, int nom);

int main() {

	setlocale(LC_ALL, "rus");

	//регулируем длину списка
	int F;

	cout << "Stack length: " << endl;
	cin >> F;

	//вывод очереди
	stackOutput(F);

	return 0;
}

void stackOutput(int F) {
	int* arrayInt = new int[F];

	for (int i = 0; i < F; ++i)	//заполнение массива из F элементов числом 1
	{
		cin >> arrayInt[i];
	}

	int length_array;
	cout << "Укажите количество элементов массива: ";
	cin >> length_array;

	int* arrayPtr = new int[length_array]; 

	for (int counter = 0; counter < length_array; counter++)
	{
		arrayPtr[counter] = rand() % 100; 
		cout << arrayPtr[counter] << "  "; 
	}
	cout << endl;

	for (int counter = length_array; counter>= 0; counter--)
	{
		if (iDel(arrayPtr, length_array, counter))
		{
			cout << "Удален объект: " << arrayPtr[counter - 1] << endl;
		}

	}

	cout << endl;

	delete[] arrayPtr;

	//инициализируем список
	DblLinkedList* list = createDblLinkedList();

	//заполняем стек элементами из массива
	for (int i = 0; i < F; i++)
	{
		pushBack(list, arrayInt[i]);
	}

	//выводим список на экран
	cout << "Stack output: ";
	printDblLinkedList(list);
	
	//выводим результат очистки стека
	while(list != NULL)
		cout << "Удален объект: " << popBack(list) << endl;

}

void printDblLinkedList(DblLinkedList* list) {
	Node* tmp = list->head;
	while (tmp) {
		printf("%d ", tmp->k);
		tmp = tmp->next;
	}
	printf("\n");
}

bool iDel(int* array, int& lenAr, int nom)
{
	if (nom > lenAr || nom < 1)
	{
		cout << " " << endl;
		return false;
	}

	for (int ix = nom - 1; ix < lenAr - 1; ix++)
	{
		array[ix] = array[ix + 1];
	}
	lenAr--;
	return true;
}

void pushBack(DblLinkedList* list, int value) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL) {
		exit(3);
	}
	tmp->k = value;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail) {
		list->tail->next = tmp;
	}
	list->tail = tmp;

	if (list->head == NULL) {
		list->head = tmp;
	}
	list->size++;
}

int popBack(DblLinkedList* list) {
	Node* next;
	int tmp;
	if (list->tail == NULL) {
		exit(4);
	}

	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail) {
		list->tail->next = NULL;
	}
	if (next == list->head) {
		list->head = NULL;
	}
	tmp = next->k;
	free(next);

	list->size--;
	return tmp;
}


DblLinkedList* createDblLinkedList() {
	DblLinkedList* tmp = (DblLinkedList*)malloc(sizeof(DblLinkedList));
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;

	return tmp;
}
