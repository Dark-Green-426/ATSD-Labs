#include "Descriptor.h"
#include "Header.h"

Descriptor::Descriptor()
{
	this->Root = new List;
    if (Root == NULL)
    {
        cout << "Error" << endl;
        system("pause");
        return;
    }
	Root->Data = "ROOT";
	Root->Link = NULL;
}

void Descriptor::AddUnit(int Number, string Data)
{
    List* Prev = this->GetPtr(Number);
    List* New = new List;
    if (New == NULL)
    {
        cout << "Error" << endl;
        system("pause");
        return;
    }
    List* Temp;
    Temp = Prev->Link;
    Prev->Link = New;
    New->Link = Temp;
    New->Data = Data;
}

void Descriptor::DeleteUnit(int Number)
{
    List* Kill = this->GetPtr(Number+1);
    List* Temp = this->Root;
    while (Temp->Link != Kill)
    {
        Temp = Temp->Link;
    }
    Temp->Link = Kill->Link;
    delete(Kill);
}

void Descriptor::DeleteAll()
{
    List* Temp = this->Root->Link;
    this->Root->Link = NULL;
    while (Temp)
    {
        List* TempLink = Temp->Link;
        delete (Temp);
        Temp = TempLink;
    }
}

List* Descriptor::GetPtr(int Number)
{
    List* Temp = this->Root;
    int Count = 1;
    while (Count != Number)
    {
        Temp=Temp->Link;
        Count++;
    }
    return Temp;
}

int Descriptor::CountUnits()
{
    List* Ptr = this->Root;
    int Count = 0;
    do {
        Ptr = Ptr->Link;
        Count++;
    } while (Ptr != NULL);
    return Count;
}

void Descriptor::PrintUnits()
{
    List* Ptr = this->Root->Link;
    int Count = 1;
    while (Ptr != NULL) {
        cout << setw(3) << Count << ":" << Ptr->Data << endl;
        Ptr = Ptr->Link;
        Count++;
    }
}

void Descriptor::SortIncrease()
{
    int N = this->CountUnits() - 1;
    for (int j = 0; j < N - 1; j++) {
        List* P1 = Root->Link;
        List* P2 = P1->Link;
        for (int i = 0; i < N - 1; i++)
        {
            string Temp;
            if (P1->Data.size() > P2->Data.size())
            {
                Temp = P2->Data;
                P2->Data = P1->Data;
                P1->Data = Temp;
            }
            P1 = P1->Link;
            P2 = P1->Link;
        }
    }
}

void Descriptor::SortDecrease()
{
    int N = this->CountUnits() - 1;
    for (int j = 0; j < N - 1; j++) {
        List* P1 = Root->Link;
        List* P2 = P1->Link;
        for (int i = 0; i < N - 1; i++)
        {
            string Temp;
            if (P1->Data.size() < P2->Data.size())
            {
                Temp = P2->Data;
                P2->Data = P1->Data;
                P1->Data = Temp;
            }
            P1 = P1->Link;
            P2 = P1->Link;
        }
    }
}

void Descriptor::RandCreate(int Number)
{
    int Len;
    int IndexASCII;
    srand(time(NULL));
    for (int i = 1; i <= Number;i++) 
    {
        string Temp;
        Len = rand() % 30 + 1;
        for (int j = 0; j < Len; j++) 
        {
            IndexASCII = rand() % 57 + 65 ;
            Temp.insert(j,1,(char)IndexASCII);
        }
        this->AddUnit(i, Temp);
    }
}