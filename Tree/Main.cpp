
#include "descriptor.h"
#include "node.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Ведіть ключ та рядок для кореня древа" << endl;
	string temp;
	int t;
	cout << "Ведіть рядок:";
	cin >> temp;
	cout << "Ведіть ключ:";
	cin >> t;
		
	system("cls");

	Descriptor tree(temp,t,NULL);

	while (1)
	{
		system("cls");
		tree.printTree(tree.getRoot());

		cout << "____________________________________________________________________________" << endl;
		cout << "| 1-Додати 2-Видалити 3-Прямий обхід 4-Центрований обхід 5-Зворотний обхід  |" << endl;
		cout << "|___________________________________________________________________________| " << endl;
		int c;
		cin >> c;
		if (c == 1)
		{
			cout << "Ведіть рядок:";
			cin >> temp;
			cout << "Ведіть ключ:";
			cin >> t;
			tree.addNode(temp,t);
		}
		else if (c == 2)
		{
			cout << "Ведіть ключ:";
			cin >> t;
			tree.deleteFromTree(t);
		}
		else if (c == 3)
		{
			
			tree.printNLR(tree.getRoot());
			system("pause");
		}
		else if (c == 4)
		{
			
			tree.printLNR(tree.getRoot());
			system("pause");
		}
		else if (c == 5)
		{
			  
			tree.printLRN(tree.getRoot());
			system("pause");
		}
		else
		{
			break;
		}
	}
	return EXIT_SUCCESS;
}