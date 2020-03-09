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
    Prev->Next = Temp;
    Temp->Next = Ptr;
    Temp->Data = Data;
    return (Temp);
}

Structs* Structs::SeekPtr(int N, Structs* Root)
{
    if (Root == NULL)
    {
        cout << "Error" << endl;
        return NULL;
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
    if (Kill == NULL) {
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
    Structs* P;
    P = Root;
    do {
        cout << P->Data << endl;
        P = P->Next; 
    } while (P != NULL);
}

int Structs::CountUnits()
{
    if (this->Next == NULL)
    {
        cout << "Error" << endl;
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