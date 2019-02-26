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
		a[i] = rand() % 50 - 10;
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
	int index = 0;
	int pos = -1; // т.е элемент с таким номером в массиве пока отсутсвует, его позиция в массиве =-1
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			pos = i; // позиция первого отрицательного
			break;
		}
	}
	
	for (int i = 0; i <= pos; i++) // если остался pos=-1 мы в этот цикл вообще не войдем, пропускаем, а если >0, то вставится в нужный индекс
		tmp[index++] = a[i];

	tmp[index++] = el; // если pos=-1, то tmp[0]=el, следующий tmp[index] станет tmp[1]

	for (int i = pos + 1; i < n; i++) 
		tmp[index++] = a[i];

	// далее переназначение указателя
	delete[] a; // открепляем от указателя старую выделенную область в памяти
	a = tmp; // прикрепляем к указателю новый массив
	n++; // новый массив на 1 больше
}

// 35.	**Написать функцию, которая принимает указатель на массив и количество элементов.
// Функция сжимает массив, удаляя из него элементы большие 20.
// Возвращает указатель на новый массив, содержащий только элементы меньшие 20.

void compress(int *&a, int &n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= 20) count++;
	}
	int *tmp = new int[count];

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= 20)
			tmp[j++] = a[i];
	}

	delete[] a;
	a = tmp;
	n = count;
}

// 12.	**Реализовать 4 функции на простейшие арифметические операции(+, -, *, / ).
// Каждая функция должна принимать два вещественных числа и возвращать результат операции в виде вещественного числа.
// В главной функции создайте массив из 4 - х указателей на эти функции.
// Добавьте меню, в котором пользователь может выбрать желаемую операцию.
// Напишите программу без использования операторов if и switch.

double add(double a, double b) {
	return a + b;
}
double sub(double a, double b) {
	return a - b;
}
double mult(double a, double b) {
	return a * b;
}
double div(double a, double b) {
	if(b!=0)
		return a / b;
	else return a;
}

int determine_index(char str[] /*char*str*/, char c) { 
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == c)
			return i;

	return -1;
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

			addElement(a, n, 5000);
			printArray(a, n);

			deleteArray(a);
		}
		break;
		case 2: //35
		{
			int *a;
			int n = 10;

			createArray(a, n);
			fillArray(a, n);
			printArray(a, n);

			compress(a, n);
			printArray(a, n);

			deleteArray(a);
		}
		break;
		case 3: //12
		{
			double (*p[4])(double, double) = { add, sub, mult, div };

			double a, b;
			int choice=0;

			char action[4] = { '+', '-', '*', '/' };
			char act;

			while (true)
			{
				/*cout << "Enter 0 to sum" << endl;
				cout << "Enter 1 to subtract" << endl;
				cout << "Enter 2 to multiple" << endl;
				cout << "Enter 3 to divide" << endl;*/
				/*cout << "Enter -1 to EXIT" << endl;*/


				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to exit" << endl;
				
				cin >> choice;

				if (choice == 0) break;
				else
				{
					cin >> a >> act >> b;
					int index = determine_index(action, act);
					if (index == -1) cout << "try again!" << endl;
					cout << p[index](a, b) << endl;
				}
			}
		}
		break;
		case 4:
		{
			// theory

			double(*pointer)(double, double) = add;
			cout << pointer << endl; // на каждый запуск всегда выдает один и то же адрес, т.к. функция в конкретном месте файла записана, если ее перенести адрес изменится
			cout << pointer(2.5, 10) << endl; // можно исп указаетель как псевдоним функции add
			double(*pp[4])(double, double) = { add, sub, mult, div };
			cout << pp[0](2.5, 10) << endl; // the same as add(2.5, 10);

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