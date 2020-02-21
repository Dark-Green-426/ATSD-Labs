#include "Algoritms.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	int ch;
	Algoritms One;

	cout << "Ви бажаєте вводити числа вручну чи сгенерувати рандомно?" << endl << "(Вручну - натиснiть 1; Сгенерувати рандомно - натиснiть 0):" << endl;
	cin >> ch;
	if (ch == 0) {
		cout << "Введiть кiлькiсть чисел(Вони будуть створенi рандомно та записанi у файл 1.txt):" << endl;
		cin >> One.Range;
		if (One.Range < 0) {
			cout << "Помилка! Не корректно введене число!" << endl;
			system("pause");
			system("cls");
			main();
			return 0;
		}
		cout << "Введiть назву файлу(В нього будуть записанi вiдсортованi числа):" << endl;
		cin >> One.Name;
		cout << "Оберiть спосiб сортування(Введiть 1, 2 або 3 вiдповiдно):" << endl << "1. ShakerSort 2.ShellSort 3.BucketSort" << endl;
		cin >> choice;
		if (choice == 1) {
			One.GetRandomNumbers(One.Range);
			One.WriteIntoFile("1.txt", One.Range);
			One.OpenReadFile("1.txt", One.Range);
			One.ShakerSort(One.Range, One.Arr);
			One.WriteIntoFile(One.Name, One.Range);
		}
		else if (choice == 2) {
			One.GetRandomNumbers(One.Range);
			One.WriteIntoFile("1.txt", One.Range);
			One.OpenReadFile("1.txt", One.Range);
			One.ShellSort(One.Range, One.Arr);
			One.WriteIntoFile(One.Name, One.Range);
		}
		else if (choice == 3) {
			One.GetRandomNumbers(One.Range);
			One.WriteIntoFile("1.txt", One.Range);
			One.OpenReadFile("1.txt", One.Range);
			One.BucketSort(One.Range, One.Arr);
			One.WriteIntoFile(One.Name, One.Range);
		}
		else {
			cout << "Помилка! Не корректно введене число!" << endl;
			system("pause");
			cout << "Натисніть ENTER" << endl;
			system("cls");
			main();
		}
	}
	else if (ch == 1) {
		cout << "Введiть кiлькiсть чисел(Вони будуть створенi рандомно та записанi у файл 1.txt):" << endl;
		cin >> One.Range;
		if (One.Range < 0) {
			cout << "Помилка! Не корректно введене число!" << endl;
			system("pause");
			system("cls");
			main();
			return 0;
		}
		cout << "Введiть назву файлу(В нього будуть записанi вiдсортованi числа):" << endl;
		cin >> One.Name;
		cout << "Оберiть спосiб сортування(Введiть 1, 2 або 3 вiдповiдно):" << endl << "1. ShakerSort 2.ShellSort 3.BucketSort" << endl;
		cin >> choice;
		if (choice == 1) {
			One.InputMassive(One.Range);
			One.WriteIntoFile("1.txt", One.Range);
			One.OpenReadFile("1.txt", One.Range);
			One.ShakerSort(One.Range, One.Arr);
			One.WriteIntoFile(One.Name, One.Range);
		}
		else if (choice == 2) {
			One.InputMassive(One.Range);
			One.WriteIntoFile("1.txt", One.Range);
			One.OpenReadFile("1.txt", One.Range);
			One.ShellSort(One.Range, One.Arr);
			One.WriteIntoFile(One.Name, One.Range);
		}
		else if (choice == 3) {
			One.InputMassive(One.Range);
			One.WriteIntoFile("1.txt", One.Range);
			One.OpenReadFile("1.txt", One.Range);
			One.BucketSort(One.Range, One.Arr);
			One.WriteIntoFile(One.Name, One.Range);
		}
		else {
			cout << "Помилка! Не корректно введене число!" << endl;
			system("pause");
			cout << "Натисніть ENTER" << endl;
			system("cls");
			main();
		}
	}
	else {
		cout << "Помилка! Не корректно введене число!" << endl;
		system("pause");
		cout << "Натисніть ENTER" << endl;
		system("cls");
		main();
	}
	return EXIT_SUCCESS;
}
