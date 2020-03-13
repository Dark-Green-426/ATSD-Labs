#include "Structs.h"

int main()
{
	Structs One("Root");
	Structs* TempStrc = &One;
	int Choice;
	int Count = 1;
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	cout << "Програма створення списків" << endl;
	cout << "Вводьте рядки, вони будуть додаватись поки не введете STOP" << endl;

	while (1) {
		string Temp;
		cout << Count << ":";
		cin >> Temp;
		if (Temp == "STOP") {
			system("cls");
			One.PrintUnits(&One);
			break;
		}
		TempStrc = One.AddUnit(TempStrc, Temp);
		Count++;
	}
	
	Choice = 0;
	do{
		cout << "1 - Додати, 2 - Сортувати, 3 - Видалити елемент, Інше - Вихід" << endl;
		cin >> Choice;
		if (Choice == 1) {
			cout << "Введіть номер після якого потрібно додати" << endl;
			int i = 0;
			string Temp;
			Temp = "";
			cin >> i;
			cout << "Введіть рядок" << endl;
			cin >> Temp;
			One.AddUnit(One.SeekPtr(i, &One), Temp);
			system("cls");
			One.PrintUnits(&One);
		}
		else if (Choice == 2) {
			system("cls");
			One.Sort(&One);
			One.PrintUnits(&One);
		}
		else if (Choice == 3) {
			cout << "Введіть номер який потрібно видалити" << endl;
			int i = 0;
			cin >> i;
			One.DeleteUnit(One.SeekPtr(i, &One), &One);
			system("cls");
			One.PrintUnits(&One);
		}
	} while (Choice >= 1 && Choice <= 3);
	
	return EXIT_SUCCESS;
}

