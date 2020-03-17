#include "Descriptor.h"
#include "Header.h"
#include "Windows.h"

int main()
{
	Descriptor One;
	int Count = 1;
	char Choice = '0';
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Програма створення списків" << endl;
	cout << "Вводьте рядки, вони будуть додаватись поки не введете STOP" << endl;
	cout << "Або ведіть RAND для створення рандомного списку(лише на початку)" << endl;
	while (1) {
		string Temp;
		cout << setw(3)<<Count << ":";
		cin >> Temp;
		if (Count == 1&&Temp == "RAND") {
			system("cls");
			cout << "Ведіть кількість елементів (до 300)" << endl;
			cin >> Count;
			while(Count>300||Count<1)
			{
				cout << "Повторіть введення " << endl;
				cin >> Count;
			}
			One.RandCreate(Count);
			system("cls");
			One.PrintUnits();
			break;
		}
		if (Temp == "STOP") {
			system("cls");
			One.PrintUnits();
			break;
		}
		One.AddUnit(Count, Temp);
		Count++;
	}

	do {
		cout << "_______________________________________________________________________________________________________" << endl;
		cout << "1 - Додати, 2 - Сортувати(Збільшення), 3 - Сортувати(Зменшення), 4 - Видалити елемент, 5 - Видалити все" << endl;
		cout << "Інше - Вихід" << endl;
		cin >> Choice;
		if (Choice == '1') {
			cout << "Введіть номер після якого потрібно додати" << endl;
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
			cout << "Введіть рядок" << endl;
			cin >> Temp;
			One.AddUnit(i+1, Temp);
			system("cls");
			One.PrintUnits();
		}
		else if (Choice == '2') {
			system("cls");
			One.SortIncrease();
			One.PrintUnits();
		}
		else if (Choice == '4') {
			cout << "Введіть номер який потрібно видалити" << endl;
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
		else if (Choice == '3') {
			system("cls");
			One.SortDecrease();
			One.PrintUnits();
		}
		else if (Choice == '5') {
			system("cls");
			One.DeleteAll();
			cout << "Натисніть 1 для створення рандомного списку, інше для продовження" << endl;
			char Chr = ' ';
			cin >> Chr;
			if (Chr == '1') 
			{
				cout << "Ведіть кількість елементів (до 300)" << endl;
				cin >> Count;
				while (Count > 300 || Count < 1)
				{
					cout << "Повторіть введення " << endl;
					cin >> Count;
				}
				One.RandCreate(Count);
			}
			system("cls");
			One.PrintUnits();
		}
	} while (Choice == '1'|| Choice == '2'||Choice == '3' || Choice == '4'|| Choice == '5');

	return EXIT_SUCCESS;
}