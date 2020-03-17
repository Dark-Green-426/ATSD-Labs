#include "Structs.h"
 
Structs* Structs::AddUnit(Structs* Prev, string Data)
{
    if (Prev == NULL)
    {
        cout << "Error" << endl;
        return NULL;
    }
    Structs* Temp;
    Structs* Ptr = Prev->Next;
    Temp = new Structs;
    if (Temp == NULL)
    {
        cout << "Error" << endl;
        return NULL;
    }
    Prev->Next = Temp;
    Temp->Next = Ptr;
    Temp->Data = Data;
    return (Temp);
}

Structs* Structs::SeekPtr(int N, Structs* Root)
{
    int Un = 0;
    Un = this->CountUnits();
    if (N > Un) {
        return NULL;
    }
    if (Root == NULL|| N < 0)
    {
        return NULL;
    }
    if(N==0)
    {
        return Root;
    }
    Structs* P;
    P = Root;
    int Count = 0;
    do {
        P = P->Next;
        Count++;
        if (Count > N)
        {
            return NULL;
        }
    } while (Count != N);
    return P;
}

void Structs::DeleteUnit(Structs* Kill, Structs* Root)
{
    if (Root == NULL) 
    {
        cout << "Error" << endl;
        return;
    }
    if (Kill == NULL) 
    {
        cout << "Error" << endl;
        return;
    }
    if (Kill == Root) 
    {
        cout << "Error" << endl;
        return;
    }
    Structs* Temp = Root;
    while(Temp->Next != Kill)
    {
        Temp = Temp->Next;
    }
    Temp->Next = Kill->Next;
    delete(Kill);
}

void Structs::PrintUnits(Structs* Root) 
{
    if (Root == NULL)
    {
        cout << "Error" << endl;
        return;
    }
    int Count = 1;
    Structs* P;
    P = Root->Next;
    do {
        cout << Count <<":"<< P->Data << endl;
        P = P->Next; 
        Count++;
    } while (P != NULL);
}

int Structs::CountUnits()
{
    if (this->Next == NULL)
    {
        return 0;
    }
    Structs* P;
    P = this->Next;
    int Count = 0;
    do {
        P = P->Next;
        Count++;
    } while (P != NULL);
    return Count;
}

void Structs::Sort(Structs* Root)
{
    int N = this->CountUnits();
    for (int j = 0; j < N - 1; j++) {
        Structs* P1 = Root->Next;
        Structs* P2 = P1->Next;
        for (int i = 0; i < N - 1; i++)
        {
            string Temp;
            if (P1->Data.size() > P2->Data.size())
            {
                Temp = P2->Data;
                P2->Data = P1->Data;
                P1->Data = Temp;
            }
            P1 = P1->Next;
            P2 = P1->Next;
        }
    }
}

void Structs::DeleteAll(Structs*)
{

}

Structs::Structs() 
{
    this->Data = "";
    this->Next = NULL;
}

Structs::Structs(string Data)
{
    this->Data = Data;
    this->Next = NULL;
}