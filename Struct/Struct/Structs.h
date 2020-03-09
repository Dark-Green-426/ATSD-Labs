#include <string>
#include <iostream>

using namespace std;

class Structs
{
private:
	string Data;
	Structs* Next;
public:
	Structs();
	Structs(string);
	Structs* AddUnit(Structs*, string);
	Structs* SeekPtr(int, Structs*);
	void DeleteUnit(Structs*,Structs*);
	void PrintUnits(Structs*);
	int CountUnits();
	void Sort(Structs*);
};

