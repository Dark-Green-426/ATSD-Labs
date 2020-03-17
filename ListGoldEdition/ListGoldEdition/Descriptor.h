#include "Header.h"
class List
{
public:
	string Data;
	List* Link;
};

class Descriptor
{
private:
	List* Root;
public:
	Descriptor();
	void AddUnit(int, string);
	void DeleteUnit(int);
	void DeleteAll();
	void SortDecrease();
	void SortIncrease();
	void PrintUnits();
	void RandCreate(int);
	int CountUnits();
	List* GetPtr(int);
};

