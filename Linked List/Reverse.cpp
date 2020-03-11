#include<bits/stdc++.h>
using namespace std;
struct linked_list
{
    int num;
    struct linked_list *next;
};
typedef  struct linked_list node;
node *head=NULL,*last=NULL;

/*void Add_in_first(int val)
{
    node *temp_node=(node*)malloc(sizeof(node));
    temp_node->num=val;
    temp_node->next=head;
    head=temp_node;

}
*/
void Add_in_last(int val){
    node *temp_node;
    temp_node=(node *)malloc(sizeof(node));
    temp_node->num=val;
    temp_node->next=NULL;

    if(head==NULL){
        head=temp_node;
        last=temp_node;
    }
    else{
        last->next=temp_node;
        last=temp_node;
    }

}
void Reverse_node(){
    node *current=head;
    node *prev=NULL,*next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
void print()
{
    node *m_node;
    m_node=head;
    while(m_node!=NULL)
    {
        cout<<m_node->num<<" ";
        m_node=m_node->next;
    }
    cout<<endl;
}
int main()
{
    int val;

    while(1)
    {
         cin>>val;
        if(val==-1)
        {
            break;
        }
        else
        {
            //cout<<"all="<<val<<endl;
            //Add_in_first(val);
            Add_in_last(val);
        }

    }

    print();

    Reverse_node();
    print();
}
