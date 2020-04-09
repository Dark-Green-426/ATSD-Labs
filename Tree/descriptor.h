#pragma once
#include "node.h"

class Descriptor
{
private:
	Node* root;
	int size;
public:
	Descriptor(string,int,int);
	Node* createNewNode(string, int,int);
	void addNode(string, int);
	void deleteNode(Node*);
	void deleteFromTree(int);
	void printNLR(Node*);
	void printLNR(Node*);
	void printLRN(Node*);
	Node* getRoot();
	void deleteTree(Node*);
	void printTree(Node*);
};

