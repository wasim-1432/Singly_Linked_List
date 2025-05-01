#include<iostream>
using namespace std;
struct Node
{
    int item;
    Node *next;
};
class SLL
{
    private:
        Node *start;
    public:
        SLL();
        void Insert_At_Beginning(int);
        void ShowData();
        void Insert_At_End(int);
        Node* Search(int);
        void Insert_After(Node*,int);
        void Delete_First();
        void Delete_At_LAst();
        void Delete_Specific(Node*);
        ~SLL();
};
SLL::SLL()
{
    start=nullptr;
}
void SLL::Insert_At_Beginning(int data)
{
    Node* n=new Node;
    n->item=data;
    n->next=start;
    start=n;
}
void SLL::ShowData()
{
    Node* temp=start;
    while(temp!=nullptr)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
}
void SLL::Insert_At_End(int data)
{
    Node* n=new Node;
    n->item=data;
    n->next=nullptr;
    Node *temp=start;
    if(start==nullptr)
    {
        start=n;
    }
    else
    {
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
Node* SLL::Search(int data)
{
    Node* temp;
    temp=start;
    while(temp->item!=data)
    {
        temp=temp->next;
    }
    if(temp->item==data)
    {
        return temp;
    }
    return nullptr;
}
void SLL::Insert_After(Node* s,int data)
{
    Node* n=new Node;
    n->item=data;
    if(start)
    {
        n->next=s->next;
        s->next=n;
    }
}
void SLL::Delete_First()
{
    if(start)
    {
        if(start->next==nullptr)
        {
            Node *temp=start;
            start=nullptr;
            delete temp;
        }
        else
        {
            Node *temp=start;
            start=temp->next;
            delete temp;
        }
    }
}
void SLL::Delete_At_LAst()
{
    if(start)
    {
        if(start->next==nullptr)
        {
            Node *temp=start;
            start=nullptr;
            delete temp;
        }
        else
        {
            Node *temp=start;
            while(temp->next->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=nullptr;
        }
    }
}
void SLL::Delete_Specific(Node* s)
{
    if(start)
    {
        if(start->next==nullptr)
        {
            delete start;
            start=nullptr;
        }
        else 
        {
            Node *temp=s->next;
            s->next=s->next->next;
            delete temp;
        }
    }
}
SLL::~SLL()
{
    while(start)
    {
        Delete_First();
    }
}
int main()
{
    SLL s1;
    s1.Insert_At_Beginning(3);
    s1.Insert_At_Beginning(4);
    s1.Insert_At_End(77);
    s1.Insert_At_End(76);
    s1.Insert_At_End(79);
    /*Node *temp=s1.Search(4);
    if(temp!=nullptr)
    {
        s1.Insert_After(temp,55);
    }*/
    //s1.Delete_First();
    //s1.Delete_At_LAst();
    Node *temp1=s1.Search(4);
    if(temp1!=nullptr)
    {
        s1.Delete_Specific(temp1);
    }
    s1.ShowData();
    cout<<endl;
    return 0;
}