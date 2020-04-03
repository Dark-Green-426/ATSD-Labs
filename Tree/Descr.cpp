#include "Descr.h"

Leaf::Leaf(string Unit,int Level)
{
    this->Level = Level;
    this->Left = NULL;
    this->Data = Unit;
    this->Right = NULL;
}

Descr::Descr()
{
	this->Root = new Leaf("Ціле число int",NULL);
    this->Size = 1;
    this->Levels = 0;
}

void Descr::AddLeaf(string Unit, Leaf* Node)
{
    static int Level = 0;
    
    if(!Node||Node->Data==Unit)
    {
        return;
    }
    else  if (Unit.size() < Node->Data.size())
    {
        if (!Node->Left)
        { 
            Node->Left = new Leaf(Unit, Level + 1);
            if (!Node->Left)
            {
                cout << "Елемент не створено (3)" << endl;
                system("pause");
                exit(1);
            }
            else
            {
                if (Level > this->Levels)
                {
                    this->Levels = Level + 1;
                }
                Level = 0;
                this->Size++;
            }
            return;
        }
        else
        {
            Level++;
            AddLeaf(Unit, Node->Left); 
        }
    }
    else 
    {
        if (!Node->Right)
        {
            Node->Right = new Leaf(Unit,Level+1);
            if (!Node->Right)
            {
                cout << "Елемент не створено (4)" << endl;
                system("pause");
                exit(1);
            }
            else
            {
                if(Level>this->Levels)
                {
                    this->Levels=Level;
                }
                Level = 0;
                this->Size++;
            }
           
            return;
        }
        else
        {
            Level++;
            AddLeaf(Unit, Node->Right);
        }
    }
    return;
}

void Descr::DirectPrint(Leaf* Node)
{
    if (!Node) 
    {
        return;
    }
    else
    {
        cout << Node->Data << endl;
        if (Node->Left)
        {
            DirectPrint(Node->Left);
        }
        if (Node->Right)
        {
            DirectPrint(Node->Right);
        }
        return;
    }       
    return;
}

void Descr::SymPrint(Leaf* Node)
{
    if (!Node)
    {
        return;
    }
    else
    {
        if (Node->Left)
        {
            SymPrint(Node->Left);
        }
        cout << Node->Data << endl;
        if (Node->Right)
        {
            SymPrint(Node->Right);
        }
        return;
    }
    return;
}

void Descr::BackPrint(Leaf* Node)
{
    if (!Node)
    {
        return;
    }
    else
    {
        if (Node->Left)
        {
            BackPrint(Node->Left);
        }
        if (Node->Right)
        {
            BackPrint(Node->Right);
        }
        cout << Node->Data << endl;
        return;
    }
    return;
}

void Descr::WidePrint(Leaf* Root,int Level)
{
    if (Root->Level == Level)
    {
        if (Root->Left)
        {
            cout << "/";
        }
       
        cout << Root->Data;

        if (Root->Right)
        {
            cout << "\\";
        }

        cout << " ";

        return;
    }

    if (Root->Level > Level)
    {
        return;
    }

    if (Root->Left)
    {
        WidePrint(Root->Left,Level);
    }
   
    if (Root->Right)
    {
        WidePrint(Root->Right, Level);
    }

    return;
}

void Descr::RandCreate(int Number)
{
    int Len;
    int IndexASCII;
    srand(time(NULL));
    for (int i = 1; i <= Number; i++)
    {
        string Temp;
        Len = rand() %15  + 8;
        for (int j = 0; j < Len; j++)
        {
            IndexASCII = rand() % 26 + 65;
            Temp.insert(j, 1, (char)IndexASCII);
        }
        this->AddLeaf(Temp,this->Root);
    }
}



void Descr::Delete(Leaf* Root,string Del)
{
    if (Root->Left)
    {
        Leaf* L = Root->Left;
        if (L->Data == Del) 
        {
            Root->Left = NULL;
            if (L->Left) {
                WideGet(L->Left);
            }
            if (L->Right) {
                WideGet(L->Right);
            }
            this->Size--;
            delete(L);
        }
        else
        {
            Delete(Root->Left, Del);
        }
    }

    if (Root->Right)
    {
        Leaf* L = Root->Right;
        if (L->Data == Del)
        {
            Root->Right = NULL;
            if (L->Left) {
                WideGet(L->Left);
            }
            if (L->Right) {
                WideGet(L->Right);
            }
            this->Size--;
            delete(L);
        }
        else
        {
            Delete(Root->Right, Del);
        }
    }
    this->GetLevel(this->Root);
    return;
}

void Descr::WideGet(Leaf* Root)
{
    if (!Root)
    {
        return;
    }
    else
    {
        if (Root->Left)
        {
            WideGet(Root->Left);
        }
        
        this->AddLeaf(Root->Data, this->Root);
        
        if (Root->Right)
        {
            WideGet(Root->Right);
        }
        return;
    }
    return;
}

//void Descr::GetLevel(Leaf* Node)
//{
//    static int Level = 1;
//    static int Size = 1;
//
//    if (!Node)
//    {
//        return;
//    }
//
//    if (Node->Left)
//    {
//        if (Level < Node->Level) {
//            Level = Node->Level;
//        }
//        Size++;
//        GetLevel(Node->Left);
//    }
//
//    if (Node->Right)
//    {
//        if (Level < Node->Level) {
//            Level = Node->Level;
//        }
//        Size++;
//        GetLevel(Node->Right);
//    }
//
//    this->Size = Size;
//    this->Levels = Level;
//   
//    return;
//}