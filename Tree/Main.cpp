
#include "descriptor.h"
#include "node.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "����� ���� �� ����� ��� ������ �����" << endl;
	string temp;
	int t;
	cout << "����� �����:";
	cin >> temp;
	cout << "����� ����:";
	cin >> t;
		
	system("cls");

	Descriptor tree(temp,t,NULL);

	while (1)
	{
		system("cls");
		tree.printTree(tree.getRoot());

		cout << "____________________________________________________________________________" << endl;
		cout << "| 1-������ 2-�������� 3-������ ����� 4-����������� ����� 5-��������� �����  |" << endl;
		cout << "|___________________________________________________________________________| " << endl;
		int c;
		cin >> c;
		if (c == 1)
		{
			cout << "����� �����:";
			cin >> temp;
			cout << "����� ����:";
			cin >> t;
			tree.addNode(temp,t);
		}
		else if (c == 2)
		{
			cout << "����� ����:";
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