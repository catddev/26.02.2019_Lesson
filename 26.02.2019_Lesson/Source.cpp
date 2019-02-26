#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

void createArray(int *&a, int n) { 
	a = new int[n];
}
void fillArray(int *a, int n) { 
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10 - 5;
}
void printArray(const int *a, int n) {
	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i] << " ";
	cout << endl;
}
void deleteArray(int *&a) { 
	delete[] a;
}

// 48.	**Написать функцию, которая принимает указатель на массив, количество элементов массива и новый элемент
// и выполняет вставку нового элемента после первого отрицательного элемента в массиве.
// Если такого элемента в массиве нет, то вставляет в начало массива.

void addElement(int *&a, int &n, int el) {
	int *tmp;
	tmp = new int[n + 1];
	int k = 0, index = 0;
	int pos = -1; // т.е элемент стаким номером в массиве пока отсутсвует
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			k++;
			pos = i;
			if (k == 1) break;
		}
	}
	
	for (int i = 0; i <= pos; i++) // если остался pos=-1 мы в этот цикл вообще не войдем, пропускаем, а если >0, то вставится в нужный индекс
		tmp[index++] = a[i];

	tmp[index++] = el; // если pos=-1, то tmp[0]=el, следующий tmp[index] станет tmp[1]

	for (int i = pos + 1; i < n; i++) 
		tmp[index++] = a[i];

	delete[] a; // открепляем от указателя старую выделенную область в памяти
	a = tmp; // прикрепляем к указателю новый массив
	n++; // новый массив на 1 больше
}


int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1: //48
		{
			int *a;
			int n = 10;

			createArray(a, n);
			fillArray(a, n);
			printArray(a, n);

			addElement(a, n, 50);
			printArray(a, n);
		}
		break;
		case 2:
		{

		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}