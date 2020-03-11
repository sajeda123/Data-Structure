#include<bits/stdc++.h>
using namespace std;
struct linked_list
{
    int num;
    struct linked_list *next;
};
typedef  struct linked_list node;
node *head=NULL,*last=NULL,*previous=NULL;
void delete_node(int key)
{
    int flag=0,p=0;
    node *my_node=head;
    while(my_node!=NULL)
    {
        p++;
        if(p==key)
        {
            if(previous==NULL)
            {
                head=my_node->next;
            }
            else
            {
                previous->next=my_node->next;

            }
            flag=1;
            free(my_node);
            break;
        }
        else{
            previous=my_node;
            my_node=my_node->next;
        }

    }
    if(flag==0){
        cout<<"Key not found"<<endl;
    }

}

/*void Add_in_first(int val)
{
    node *temp_node=(node*)malloc(sizeof(node));
    temp_node->num=val;
    temp_node->next=head;
    head=temp_node;

}
*/
void Add_in_last(int val)
{
    node *temp_node;
    temp_node=(node *)malloc(sizeof(node));
    temp_node->num=val;
    temp_node->next=NULL;

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
    int key;
    cin>>key;
    delete_node(key+1);
    print();
}
