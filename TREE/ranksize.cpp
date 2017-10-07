#include <iostream>
using namespace :: std ;
struct node 
{
    int data;
    int count;
    struct node *left;
    struct node *right;
};

struct node *newnode(int val)
{
    struct node *t=new(struct node);
    t->data=val;
    t->count=1;
    t->left=NULL;
    t->right=NULL;
    return t;
} 

int size(struct node *t)
{
    if(t==NULL)return 0;
    else
    {
        return (1+size(t->left)+size(t->right));
    }
}

struct node *insert(struct node *t,int val)
{
    if(t==NULL)
        return newnode(val);
    else
    {
        if(t->data > val)
            t->left=insert(t->left,val);
        else if(t->data < val)
            t->right=insert(t->right,val);
        else
            t->data=val;
    } 
    t->count=size(t);
    return t;
}   
void inorder(struct node *t)
{
    if(t==NULL)return ;
    inorder(t->left);
    cout<<t->data<<"("<<t->count<<")"<<" ";
    inorder(t->right);
}
struct node *search(struct node *t,int k)
{
    int n=0;
    struct node *h=t->left;
    if(h!=NULL)n=h->count;
    if(k==n+1)
        return t;
    else
    {
        if(k<n+1)
            return search(t->left,k);
        else
            return search(t->right,k-n-1);
    }
}
int main()
{
    struct node *root=insert(root,10);
    root=insert(root,6);
    root=insert(root,15);
    root=insert(root,12); 
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,2);
    inorder(root);
    cout<<endl;
    cout<<search(root,6)->data<<endl;
    return 0;
}



