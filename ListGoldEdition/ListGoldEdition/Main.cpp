#include "Descriptor.h"
#include "Header.h"
#include "Windows.h"

int main()
{
	Descriptor One;
	int Count=1;
	int Choice;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�������� ��������� ������" << endl;
	cout << "������� �����, ���� ������ ���������� ���� �� ������� STOP" << endl;
	OneMoreTime:
	while (1) {
		string Temp;
		cout << Count << ":";
		cin >> Temp;
		if (Temp == "STOP") {
			system("cls");
			One.PrintUnits();
			break;
		}
		One.AddUnit(Count, Temp);
		Count++;
	}

	Choice = 0;
	do {
		cout << "_______________________________________________________________________________________________________" << endl;
		cout << "1 - ������, 2 - ���������(���������), 3 - ���������(���������), 4 - �������� �������, 5 - �������� ���" << endl;
		cout << "���� - �����" << endl;
		cin >> Choice;
		if (Choice == 1) {
			cout << "������ ����� ���� ����� ������� ������" << endl;
			int i = 0;
			int Units = One.CountUnits()-1;
			string Temp;
			Temp = "";
			cin >> i;
			if(i>Units||i<0)
			{
				system("cls");
				One.PrintUnits();
				continue;
			}
			cout << "������ �����" << endl;
			cin >> Temp;
			One.AddUnit(i+1, Temp);
			system("cls");
			One.PrintUnits();
		}
		else if (Choice == 2) {
			system("cls");
			One.SortIncrease();
			One.PrintUnits();
		}
		else if (Choice == 4) {
			cout << "������ ����� ���� ������� ��������" << endl;
			int i = 0;
			int Units = One.CountUnits() - 1;
			cin >> i;
			if (i > Units || i < 1)
			{
				system("cls");
				One.PrintUnits();
				continue;
			}
			One.DeleteUnit(i);
			system("cls");
			One.PrintUnits();
		}
		else if (Choice == 3) {
			system("cls");
			One.SortDecrease();
			One.PrintUnits();
		}
		else if (Choice == 5) {
			system("cls");
			One.DeleteAll();
			cout << "��������� ������� ���� 0�� ��������" << endl;
		}
	} while (Choice >= 1 && Choice <= 5);

	return EXIT_SUCCESS;
}