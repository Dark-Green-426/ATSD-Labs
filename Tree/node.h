#pragma once
#include "lib.h"

class Node
{
public:
	Node* left;
	string data;
	int key;
	int lvl;
	Node* right;
	Node(string,int,int);
};

