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
int Get_node_value(int p)
{
    node *s_node=head;
    int ind=0;
    while(s_node!=NULL)
    {
        if(p==ind)
        {
            return s_node->num;
        }
        else
        {
            ind++;
            s_node=s_node->next;
        }
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
    int val,n,t;
    cin>>t;
    while(t--)
    {

        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            Add_in_last(val);
        }

        print();
        int p;
        cin>>p;
        p++;
        int val=Get_node_value(n-p);
        cout<<val<<endl;
        head=NULL;
    }


}
