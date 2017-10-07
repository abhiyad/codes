#include <iostream>
#include <queue>
using namespace :: std ;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int color; // 0 means black by default 1 will mean red color of the link
};
int isred(struct node *h)
{
    if(h==NULL)return 0;
    else
        return h->color==1;
}
struct node *rotateleft(struct node *h)
{
    struct node *x=new(struct node);
    x=h->right;
    h->right=x->left;
    x->left=h;
    x->color=h->color;
    h->color=1;
    return x;
}
 
struct node *rotateright(struct node *h)
{
    struct node *x=new(struct node);
    x=h->left;
    h->left=x->right;
    x->right=h;
    x->color=h->color;
    h->color=1;
    return x;
}
void *flipcolors(struct node *h)
{
    h->color=1;
    h->left->color=0;
    h->right->color=0;
}

struct node *insert(struct node *t,int val)
{
   
    if(t==NULL)
    {
        struct node *x=new(struct node);
        x->data=val;
        x->color=1;  
        return x;
    }
    else
    {
        if(t->data > val)
            t->left=insert(t->left,val);
        else if (t->data < val)
            t->right=insert(t->right,val);
    }
    cout<<t->data<<"HERE"<<endl;
    // here is the magic of red black BST (left leaning)
    if(isred(t->right) && !isred(t->left))t=rotateleft(t);
    if(isred(t->left) && isred(t->left->left))t=rotateright(t);
    if(isred(t->left) && isred(t->right))flipcolors(t);

    return t;
}                       
void bft(struct node *root)
{
    if(root==NULL)return ;
    bft(root->left);
    cout<<root->data<<" ";
    bft(root->right);
}
int main() 
{
    struct node *root=insert(root,15);
    root->color=0;
    root=insert(root,20);
    root=insert(root,10);
    root=insert(root,5);     
    root=insert(root,12);   
    root=insert(root,25);
    root=insert(root,17); 
    bft(root);
    return 0;
}

