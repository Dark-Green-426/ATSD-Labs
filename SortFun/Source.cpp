#include "Algoritms.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	int ch;
	Algoritms One;

	cout << "�� ������ ������� ����� ������ �� ����������� ��������?" << endl << "(������ - ������i�� 1; ����������� �������� - ������i�� 0):" << endl;
	cin >> ch;
	if (ch == 0) {
		cout << "����i�� �i���i��� �����(���� ������ �������i �������� �� �������i � ���� 1.txt):" << endl;
		cin >> One.Range;
		if (One.Range < 0) {
			cout << "�������! �� ��������� ������� �����!" << endl;
			system("pause");
			system("cls");
			main();
			return 0;
		}
		cout << "����i�� ����� �����(� ����� ������ �������i �i���������i �����):" << endl;
		cin >> One.Name;
		cout << "����i�� ����i� ����������(����i�� 1, 2 ��� 3 �i����i���):" << endl << "1. ShakerSort 2.ShellSort 3.BucketSort" << endl;
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
			cout << "�������! �� ��������� ������� �����!" << endl;
			system("pause");
			cout << "�������� ENTER" << endl;
			system("cls");
			main();
		}
	}
	else if (ch == 1) {
		cout << "����i�� �i���i��� �����(���� ������ �������i �������� �� �������i � ���� 1.txt):" << endl;
		cin >> One.Range;
		if (One.Range < 0) {
			cout << "�������! �� ��������� ������� �����!" << endl;
			system("pause");
			system("cls");
			main();
			return 0;
		}
		cout << "����i�� ����� �����(� ����� ������ �������i �i���������i �����):" << endl;
		cin >> One.Name;
		cout << "����i�� ����i� ����������(����i�� 1, 2 ��� 3 �i����i���):" << endl << "1. ShakerSort 2.ShellSort 3.BucketSort" << endl;
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
			cout << "�������! �� ��������� ������� �����!" << endl;
			system("pause");
			cout << "�������� ENTER" << endl;
			system("cls");
			main();
		}
	}
	else {
		cout << "�������! �� ��������� ������� �����!" << endl;
		system("pause");
		cout << "�������� ENTER" << endl;
		system("cls");
		main();
	}
	return EXIT_SUCCESS;
}
