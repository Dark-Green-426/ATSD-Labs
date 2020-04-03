#include "Descr.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Descr One;
	string temp;
	for(int j = 0; j<10;j++)
	{
		
		cin >> temp;
		system("cls");
		cout << "L:" << One.Levels << " " << "S:" << One.Size << endl;
		One.AddLeaf(temp, One.Root);
		
		for (int i = 0; i <= One.Levels+1; i++)
		{
			cout << "L" << i << ":";
			One.WidePrint(One.Root, i);
			cout << endl;
		}
	}
	cout << "Del" << endl;
	cin >> temp;
	One.Delete(One.Root, temp);
	cout << "L:" << One.Levels << " " << "S:" << One.Size << endl;
	for (int i = 0; i <= One.Levels + 1; i++)
	{
		cout << "L" << i << ":";
		One.WidePrint(One.Root, i);
		cout << endl;
	}
	return EXIT_SUCCESS;
}