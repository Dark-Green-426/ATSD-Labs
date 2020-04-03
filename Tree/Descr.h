#pragma once

#include "Header.h"

class Leaf
{	
public:
	int Level;
	Leaf* Right;
	string Data;
	Leaf* Left;
	Leaf(string,int);
};

class Descr
{
public:
	int Size;
	Leaf* Root;
	int Levels;
	Descr();
	void AddLeaf(string,Leaf*);
	void DirectPrint(Leaf*);
	void SymPrint(Leaf*);
	void BackPrint(Leaf*);
	void WidePrint(Leaf*, int);
	void RandCreate(int);
	void Delete(Leaf* ,string);
	void WideGet(Leaf*);
	void GetLevel(Leaf*);
};

