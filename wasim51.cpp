#include<iostream>
using namespace std;
struct Node
{
    Node* prev;
    int item;
    Node* next;
};
class DLL
{
    private:
        Node* start;
    public:
        DLL();
        void Insert_At_Beginning(int);
        void ShowData();
        void Insert_At_End(int);
        Node* Search(int);
        void Insert_After(Node*,int);
        void Delete_First();
        void Delete_Last();
        void Delete_Specific(Node*);
        ~DLL();
};
DLL::DLL()
{
    start=nullptr;
}
void DLL::Insert_At_Beginning(int data)
{
    Node* n=new Node;
    n->item=data;
    n->prev=nullptr;
    if(start==nullptr)
    {
        n->next=start;
        start=n;
    }
    else
    {
        n->next=start;
        start->prev=n;
        start=n;
    }
}
void DLL::ShowData()
{
    Node* temp=start;
    while(temp!=nullptr)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
}
void DLL::Insert_At_End(int data)
{
    Node* n=new Node;
    n->item=data;
    n->next=nullptr;
    if(start==nullptr)
    {
        n->prev=start;
        start=n;
    }
    else
    {
        Node* temp=start;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }
}
Node* DLL::Search(int data)
{
    if(start)
    {
        Node *temp=start;
        while(temp->item!=data)
        {
            if(temp->next==nullptr)
            {
                return nullptr;
            }
            temp=temp->next;
        }
        if(temp->item==data)
        {
            return temp;
        }
    }
    else
    {
        return nullptr;
    }
}
void DLL::Insert_After(Node* s,int data)
{
    Node* n=new Node;
    n->item=data;
    if(s->next==nullptr)
    {
        n->next=s->next;
        n->prev=s;
        s->next=n;
    }
    else
    {
        n->next=s->next;
        s->next->prev=n;
        n->prev=s;
        s->next=n;
    }
}
void DLL::Delete_First()
{
    if(start)
    {
        if(start->next==nullptr)
        {
            Node* temp=start;
            start=start->next;
            delete temp;
        }
        else
        {
            Node* temp=start;
            temp->next->prev=nullptr;
            start=temp->next;
            delete temp;
        }
    }
}
void DLL::Delete_Last()
{
    if(start)
    {
        if(start->next==nullptr)
        {
            Node* temp=start;
            start=start->next;
            delete temp;
        }
        else
        {
            Node* temp=start;
            while(temp->next->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=nullptr;
        }
    }
}
void DLL::Delete_Specific(Node* s)
{
    if(s->next->next==nullptr)
    {
        Node* temp=s->next;
        s->next=nullptr;
        temp->prev=nullptr;
        delete temp;
    }
    else
    {
        Node* temp=s->next;
        s->next=temp->next;
        temp->next->prev=s;
        delete temp;
    }
}
DLL::~DLL()
{
    while(start)
    {
        Delete_Last();
    }
}
int main()
{
    DLL d1;
    d1.Insert_At_Beginning(3);
    d1.Insert_At_Beginning(77);
    d1.Insert_At_Beginning(88);
    d1.Insert_At_End(76);
    d1.Insert_At_End(34);
    Node* temp=d1.Search(3);
    if(temp!=nullptr)
    {
        d1.Insert_After(temp,83);
    }
    Node* temp1=d1.Search(88);
    if(temp1!=nullptr)
    {
        d1.Delete_Specific(temp1);
    }
    //d1.Delete_Last();
    d1.ShowData();
    cout<<endl;
    return 0;
}