#include <iostream>
#include <stack>
using namespace :: std;
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node *newnode(int val)
{
    struct node *t=new(struct node);
    t->data=val;
    t->left=NULL;
    t->right=NULL;
    return t;
}
struct node *insert(struct node *t,int val)
{
    struct node *temp=newnode(val);
    if(t==NULL)
        return temp;
    else
    {
        if(t->data < val)
            t->right=insert(t->right,val);
        else
            t->left=insert(t->left,val);
    }
    return t;
}


void morris(struct node *root)
{
   struct node *current=root;
   while(current!=NULL)
   {
       if(current->left==NULL)
       {
           cout<<current->data<<" ";
           current=current->right;
       }
       else
       {
           struct node *predessor=current->left;
           while(predessor->right!=NULL && predessor->right!=current)predessor=predessor->right;
           if(predessor->right==NULL)
           {
               predessor->right=current;
               cout<<current->data<<" ";     
               current=current->left;
           }
           else
           {
               predessor->right=NULL;
              // cout<<current->data<<" ";
               current=current->right;
           }
       }
   }
}

int main()
{
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,12);
    root=insert(root,5);   
    root=insert(root,1); 
    root=insert(root,7); 
    morris(root);
    cout<<endl;
return 0;
}
