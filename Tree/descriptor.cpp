#include "descriptor.h"

class Node;

Descriptor::Descriptor(string data,int key,int lvl)
{
	this->size = NULL;
	this->root = this->createNewNode(data, key, lvl);
}

Node* Descriptor::createNewNode(string data,int key,int lvl)
{
	Node* temp = new Node(data,key,lvl);
	if (!temp) 
	{
		cout << "Помилка створення" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		this->size++;
	}
	return temp;
}

void Descriptor::deleteNode(Node* temp)
{
	if (!temp)
	{
		cout << "Помилка видалення" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		delete(temp);
		this->size--;
	}
	return;
}

void Descriptor::addNode(string data, int key)
{
    Node* temp = this->getRoot();
    int countLvl = 0;
    while (temp)
    {
        if (key == temp->key)
        {
            return;
        }
        else if (key < temp->key)
        {
            if (!temp->left)
            {
                temp->left = this->createNewNode(data, key ,countLvl + 1);
                break;
            }
            else
            {
                countLvl++;
                temp = temp->left;
            }
        }
        else
        {
            if (!temp->right)
            {
                temp->right = this->createNewNode(data,key,countLvl + 1);
                break;
            }
            else
            {
                countLvl++;
                temp = temp->right;
            }
        }
    }
    return;
}

void Descriptor::printNLR(Node* temp)
{
    if (!temp)
    {
        return;
    }
    else
    {
        cout << temp->data <<"("<<temp->key<<")"<< endl;
        if (temp->left)
        {
            printNLR(temp->left);
        }
        if (temp->right)
        {
            printNLR(temp->right);
        }
    }
    return;
}

void Descriptor::printLNR(Node* temp)
{
    if (!temp)
    {
        return;
    }
    else
    {
        if (temp->left)
        {
            printNLR(temp->left);
        }
        cout << temp->data << "(" << temp->key << ")" << endl;
        if (temp->right)
        {
            printNLR(temp->right);
        }
    }
    return;
}

void Descriptor::printLRN(Node* temp)
{
    if (!temp)
    {
        return;
    }
    else
    {
        if (temp->left)
        {
            printNLR(temp->left);
        }
        if (temp->right)
        {
            printNLR(temp->right);
        }
        cout << temp->data << "(" << temp->key << ")" << endl;
    }
    return;
}

Node* Descriptor::getRoot()
{
    return this->root;
}

void Descriptor::printTree(Node* temp)
{

    if (!temp)
    {
        return;
    }
    else
    {
        if (temp->left)
        {
            printTree(temp->left);
        }

        for (int i = 0; i < 10 * temp->lvl; i++)
        {
            cout << " ";
        }
        cout << temp->data << "(" << temp->key << ")" << endl;
        if (temp->right)
        {
            printTree(temp->right);
        }
    }
    return;
}

void Descriptor::deleteFromTree(int key)
{
    Node* temp = this->getRoot();
    Node* prev = this->getRoot();
    Node* out = NULL;

    while (temp)
    {
        if (key < temp->key)
        {

            prev = temp;
            temp = temp->left;

        }
        else if (key > temp->key)
        {

            prev = temp;
            temp = temp->right;

        }
        else
        {
            if (key == temp->key)
            {
                break;
            }
            else
            {
                    cout << "Помилка 1" << endl;
                    system("pause");
                    exit(1);
            
            }
        }
    }

    if (prev->left && key == prev->left->key)
    {
        Node* temp = prev->left;
        if (!temp->left && !temp->right)
        {
            prev->left = NULL;
            this->deleteNode(temp);
        }
        else if (temp->left && !temp->right)
        {
            
            prev->left = NULL;
            this->deleteTree(temp->left);

        }
        else if (!temp->left && temp->right)
        {
            prev->left = NULL;
            this->deleteTree(temp->right);
        }
        else if (temp->left && temp->right)
        {
            prev->left = NULL;
            this->deleteTree(temp->left);
            this->deleteTree(temp->right);
        }
        
    }

    if (prev->right && key == prev->right->key)
    {
        Node* temp = prev->right;
        if (!temp->left && !temp->right)
        {
            prev->right = NULL;
            this->deleteNode(temp);
        }
        else if (temp->left && !temp->right)
        {

            prev->right = NULL;
            this->deleteTree(temp->left);

        }
        else if (!temp->left && temp->right)
        {
            prev->right = NULL;
            this->deleteTree(temp->right);
        }
        else if (temp->left && temp->right)
        {
            prev->right = NULL;
            this->deleteTree(temp->left);
            this->deleteTree(temp->right);
        }

    }
    return;
}

void Descriptor::deleteTree(Node* temp)
{
    if (temp) {
        this->deleteTree(temp->left);
        this->deleteTree(temp->right);
        this->deleteNode(temp);
    }
    return;
}