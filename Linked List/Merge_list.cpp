#include<bits/stdc++.h>
using namespace std;
struct linked_list
{
    int num;
    struct linked_list *next;
};
typedef struct linked_list node;
node *head=NULL,*last=NULL;

node *Sorted_list(node *h)
{
    node *p1=h;
    node *p2=h->next;
    while(p2!=NULL){
        if(p1->num >p2->num){
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

node *mergeShorted(node *head1, node *head2){
   node *result = NULL;
   if (head1 == NULL) {
      return head2;
   }
   if (head2 == NULL) {
      return head1;
   }
   if (head1->num < head2->num) {
      result = head1;
      result->next = mergeShorted(head1->next, head2);
   } else {
      result = head2;
      result->next = mergeShorted(head1, head2->next);
   }
   return result;
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
    int t,n,m,val1,val2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(n--)
        {
            cin>>val1;
            head1=Add_in_list(val1);
            Sorted_list(head1);
        }
        print(head1);

        cin>>m;
        head = NULL;
        while(m--)
        {
            cin>>val2;
            head2=Add_in_list(val2);

        }
        Sorted_list(head2);
        print(head2);
        head3=mergeShorted(head1,head2);
        print(head3);
    }
}
