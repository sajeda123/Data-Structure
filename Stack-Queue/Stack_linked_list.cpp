#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *link;
};
Node *top=NULL;
bool Stack_Empty(){
    if(top==NULL){
        return true;
    }
    else{
        return false;
    }
}

void push_stack(int val){
    Node *temp=new Node();
    temp->data=val;
    temp->link=top;
    top=temp;

}
void pop_stack(){
    if(Stack_Empty()){
        cout<<"Stack is Empty."<<endl;
    }
    else{
        Node *temp=top;
        top=top->link;
        delete(temp);
    }

}
void display(){
    Node *p=top;
    while(p->link!=NULL){
        cout<<p->data<<endl;
        p=p->link;
    }
    cout<<p->data<<endl;
}
int main()
{
    push_stack(3);
    push_stack(6);
    push_stack(7);



    display();
    cout<<"---------------After pop-----------"<<endl;
    pop_stack();
    display();

}
