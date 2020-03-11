#include<bits/stdc++.h>
using namespace std;
struct linked_list
{
    int num;
    struct linked_list *next;
};
typedef struct linked_list node;
node *head=NULL,*last=NULL;

node *Add_in_last(int val)
{
    node *temp_node;
    temp_node=(node *)malloc(sizeof(node));
    temp_node->num=val;
    temp_node->next=NULL;
    //temp_node->next=head->next;
    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {

        last->next=temp_node;
        last=temp_node;

    }
    return head;

}
void print(node *head)
{
    while(!head==NULL)
    {
        cout<<head->num<<" ";
        head=head->next;
    }
    cout<<endl;
}
void Add_specific_position(int value,int position)
{
    node *m_node=head;
    int flag=0,p=0;
    while(m_node!=NULL)
    {
        p++;

        if(p==position)
        {
            node *new_node=(node*)malloc(sizeof(node));
            new_node->num=value;
            new_node->next=m_node->next;
            m_node->next=new_node;
            flag=1;
            break;
        }
        else
        {
            m_node=m_node->next;
        }
    }
    if(flag==0)
    {
        cout<<"Element not found"<<endl;
    }
}
int main()
{
    int val;
   node *head1;
    while(1)
    {
        cin>>val;
        if(val==-1)
        {
            break;
        }
        else
        {
        head1=Add_in_last(val);
        }
    }
    print(head1);
    int position,value;
    cin>>value>>position;
    Add_specific_position(value,position);
    print(head);

}
