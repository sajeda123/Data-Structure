#include<bits/stdc++.h>
using namespace std;
struct linked_list
{
    int num;
    struct linked_list *next;
};
typedef struct linked_list node;
node *head=NULL,*last=NULL,*previous=NULL;

void Delete_duplicate_node(node *head)
{
    node *current=head,*temp;
    if(head == NULL)
        return;
    if(head->next == NULL)
        return;
    else
    {
        while(current->next != NULL)
        {

            if(current->num == current->next->num)
            {
                temp = current->next->next;
                current->next = temp;
            }
            else
                current=current->next;
        }
    }
}

node *Sorted_list(node *h)
{
    node *p1=h;
    node *p2=h->next;
    while(p2!=NULL)
    {
        if(p1->num >p2->num)
        {
            swap(p1->num,p2->num);
        }
        p1=p1->next;
        p2=p2->next;
    }
    return h;

}
node *Add_in_list(int val)
{
    node *temp_node=(node*)malloc(sizeof(node));
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

    return head;

}

void print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->num<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    node *head1,*head2,*head3;
    int t,n,m,val,val2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(n--)
        {
            cin>>val;
            head1=Add_in_list(val);
        }
        Sorted_list(head1);
        Delete_duplicate_node(head1);
        print(head);

    }
}
