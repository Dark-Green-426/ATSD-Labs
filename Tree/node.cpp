#include "node.h"

Node::Node(string data, int key,int lvl)
{
	this->left = NULL;
	this->right = NULL;
	this->key = key;
	this->lvl = lvl;
	this->data = data;
}

