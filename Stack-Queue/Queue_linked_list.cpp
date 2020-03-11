#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *link;
};
Node *Front=NULL,*Rear=NULL;
void Inqueue(int val)
{
    Node *temp=new Node();
    temp->data=val;
    temp->link=NULL;
    if(Front==NULL)
    {
        Front=temp;
        Rear=temp;
    }
    else
    {
        Rear->link=temp;
        Rear=temp;
    }

}
bool isEmpty()
{
    if(Front==NULL && Rear==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        Node *temp=Front;
        Front=Front->link;
        delete(Front);
    }
}
void Display()
{
    Node *temp=Front;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->link;
    }
}
int main()
{
    Inqueue(5);
    Inqueue(6);
    Inqueue(7);
    Inqueue(8);

    Display();
     cout<<"---------------After pop-----------"<<endl;
    Dequeue();
    Display();
}
