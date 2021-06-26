#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const string TASK1_DESCRIPT = "Задача 1.\nНапишите функцию, которая возвращает наибольший из трех целочисленных аргументов.\n\n";
const string TASK2_DESCRIPT = "Задача 2.\nНапишите функцию, которая имеет два аргумента int: нижний предел и верхний предел. Функция должна читать целое число из входных данных. Если это число выходит за указанные пределы, функция должна снова вывести меню (используя функцию из части а)), чтобы повторно предложить пользователю ввести новое значение. Если введенное целое значение попадает в рамки пределов, функция должна возвратить его в вызывающую функцию. Ввод нецелочисленного значения должен приводить к возвращению функцией значения, соответствующего выходу из программы.\n(Часть а. Напишите функцию, которая выводит на экран меню из четырех пронумерованных вариантов и предлагает выбрать один из них. Ввод верхнего и нижнего предела, возможность изменить входящее целое число повторным вводом с клавиатуры и выход из меню и программы).\n\n";
const string TASK3_DESCRIPT = "Задача 3.\nРеализуйте сортировку массива вставками (массив из целых чисел).\n\n";

// Задача 1.
int FindMaxAmong(int a1, int a2, int a3) {
	return max(a1, max(a2, a3));
	// return ((a2 > a3 && a1 > a2) || (a3 > a2 && a1 > a3)) ? a1 : ((a1 > a3 && a2 > a1) || (a3 > a1 && a2 > a3)) ? a2 : ((a1 > a2 && a3 > a1) || (a2 > a1 && a3 > a2)) ? a3 : -1;
}

// Меню для задачи 2.
// Параметры передаем по ссылке, чтобы можно было их изменять.
void CallMenuForTask2(double& number, int& lowBound, int& upBound) {
	int userChoice;
	cout << "\n----- Меню (задача 2) -----\n";
	cout << "Введенное вами ранее число выходит за указанные пределы.\nЧто вы хотите сделать?\nНа выбор есть 4 варианта:\n";
	cout << "1 - Ввести новый нижний предел\n2 - Ввести новый верхний предел\n3 - Изменить входящее целое число\n0 - Выход из программы\n\nВведите номер вашего выбора: ";
	cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		cout << "Введите новый нижний предел: ";
		cin >> lowBound;
		break;
	case 2:
		cout << "Введите новый верхний предел: ";
		cin >> upBound;
		break;
	case 3:
		cout << "Введите новое входящее число: ";
		cin >> number;
		break;
	case 0:
		cout << "\nВыбран вариант выхода из программы. Программа завершается...\n";
		exit(0);
	default:
		cout << "Введен некорректный номер. Пожалуйста, повторите попытку: ";
		break;
	}
}

// Задача 2.
double RunTask2(int& lowBound, int& upBound) {
	double number;
	cout << "Введите ваше число (число может выходить за указанные пределы): ";
	cin >> number;
	// Если число не целое - выход их программы.
	if (int(number) != number)
	{
		cout << "\nВведено нецелочисленное значение. Программа завершается...\n";
		exit(1);
	}

	// Крутим до тех пор, пока number по результатам работы CallMenuForTask2
	// не попадет в указанные пределы.
	do
	{
		if (number < lowBound || number > upBound)
		{
			CallMenuForTask2(number, lowBound, upBound);
		}
	} while (number < lowBound || number > upBound);

	if (number >= lowBound && number <= upBound)
	{
		cout << "\nЧисло входит в указанные пределы!";
		return number;
	}
}

// Метод, реализующий сортировку вставками (для задачи 3).
void InsertSort(int* arr, int count) {
	int root, temp;
	for (int i = 0; i < count - 1; i++)
	{
		// Для каждого i запоминаем следующий элемент.
		root = i + 1;
		temp = arr[root];
		// Пробегаем все элементы с от i + 1 до 0.
		for (int j = i + 1; j > 0; j--)
		{
			// Если j-й элемент меньше предыдущего.
			if (temp < arr[j - 1])
			{
				// Кладем в него большее значение.
				arr[j] = arr[j - 1];
				// Запоминаем индекс, на который встанет меньший элемент.
				root = j - 1;
			}
		}
		// Вставляем меньшее значение на запомненное место.
		arr[root] = temp;
	}
}

// Задача 3.
void RunTask3() {
	int count;
	cout << "Введите кол-во элементов в вашем массиве: ";
	cin >> count;

	// Выделяем память под массив.
	int* arr = new int[count];
	cout << "\nВвод массива...\n";
	for (int i = 0; i < count; i++)
	{
		cout << "Введите " << i << "-й элемент: ";
		cin >> arr[i];
	}

	// Сортируем массив.
	InsertSort(arr, count);

	cout << "\nВаш массив, отсортированный по возрастанию:\n";
	for (int i = 0; i < count; i++)
	{
		cout << setw(10) << arr[i];
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	cout << "----- ЛР-6 начала выполнение! -----\n\n";
	int userChoice, lowBound, upBound;
	// Главное меню для перехода между задачами.
	do
	{
		cout << "----- Главное меню -----\n";
		cout << "Что вы хотите сделать?\nНа выбор есть 4 варианта:\n";
		cout << "1 - Задача 1\n2 - Задача 2\n3 - Задача 3\n0 - Выход\n\nВведите номер вашего выбора: ";
		cin >> userChoice;
		cout << "\n";

		// Объявляем необходимые переменные.
		int number1, number2, number3;
		double number;
		switch (userChoice)
		{
		case 1:
			cout << TASK1_DESCRIPT;
			cout << "Введите 3 числа, и программа найдет из них максимальное.\n";
			cout << "Первое число: ";
			cin >> number1;
			cout << "Второе число: ";
			cin >> number2;
			cout << "Третье число: ";
			cin >> number3;
			cout << "\nСреди чисел " << number1 << ", " << number2 << " и " << number3 << " максимальное - " << FindMaxAmong(number1, number2, number3);
			break;
		case 2:
			cout << TASK2_DESCRIPT;
			cout << "Введите нижний предел: ";
			cin >> lowBound;
			cout << "Введите верхний предел: ";
			do
			{
				cin >> upBound;
				if (upBound < lowBound)
				{
					cout << "Верхний предел не может быть меньше нижнего предела! Повторите попытку: ";
				}
			} while (upBound < lowBound);

			number = RunTask2(lowBound, upBound);
			cout << "\n" << lowBound << " <= " << number << " <= " << upBound;
			break;
		case 3:
			cout << TASK3_DESCRIPT;
			RunTask3();
			break;
		case 0:
			cout << "Выбран вариант выхода из программы. Программа завершается...\n\n";
			break;
		default:
			cout << "Введен некорректный номер. Пожалуйста, повторите попытку";
			break;
		}

		if (userChoice != 0)
		{
			cout << "\n\n----------------------------------------------------------------------------------------------------\n\n";
		}
	} while (userChoice != 0);

	system("pause");
	return 0;
}
