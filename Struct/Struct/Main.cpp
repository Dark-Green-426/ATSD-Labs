#include "Structs.h"

int main()
{
	int N;
	Structs One("Root");
	cin >> N;
	for (int i = 0; i < N;i++) {
		static Structs* Ptr = &One;
		string Data;
		cin >> Data;
		Ptr = One.AddUnit(Ptr, Data);
	}
	One.PrintUnits(&One);
	One.AddUnit(One.SeekPtr(3, &One),"Test");
	One.PrintUnits(&One);
	cout << One.CountUnits() << endl;;
	system("pause");
	return EXIT_SUCCESS;
}

