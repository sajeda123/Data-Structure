#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
int Height(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=Height(root->left);
    int rheight=Height(root->right);

    if(lheight>rheight)
    {
        return lheight+1;
    }
    else
    {
        return rheight+1;
    }


}
void PrintGivenOrder(int level,node *root)
{
    if(root==NULL)
    {
        return;
    }
    if(level==1)
    {
        cout<<root->data<<" ";
    }
    else
    {
        PrintGivenOrder(level-1,root->left);
        PrintGivenOrder(level-1,root->right);
    }
}
void PrintLevelOrder(node *root)
{
    int h=Height(root);

    for(int i=1; i<=h; i++)
    {
        PrintGivenOrder(i,root);
    }

}
node *Newnode(int d)
{
    node *Node=new node();
    Node->data=d;
    Node->left=NULL;
    Node->right=NULL;
    return (Node);
}
int main()
{
    node *root=Newnode(1);
    root->left=Newnode(2);
    root->right=Newnode(3);
    root->left->left=Newnode(4);
    root->left->right=Newnode(5);
    root->right->left=Newnode(6);
    root->right->right=Newnode(7);


    PrintLevelOrder(root);

}
