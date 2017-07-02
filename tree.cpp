#include <iostream>
using namespace ::std ; 
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};
struct queue
{
    struct node *p;
    struct queue *next;
};
struct queue *head=new(struct queue);
struct queue *last=new(struct queue); 
struct node *newnode(int val)
{
    struct node *t=new(struct node);
    t->data=val;
    return t;
}
void inorder(struct node *t)
{
    if(t==NULL)return ;
    inorder(t->left);
    cout<<t->data<<" -> ";
    inorder(t->right);
}

int findmax(struct node *t)
{
    if(t->right==NULL)return t->data;
    else return findmax(t->right);
}


struct node *Delete(struct node *t,int val)
{
    if(t==NULL)return t;
    else if(t->data > val) 
        t->left=Delete(t->left,val);
    else if(t->data < val)
        t->right=Delete(t->right,val);
    else
    {
        if(t->left==NULL && t->right==NULL)
            return NULL;
        else if(t->right==NULL)
        {
            t=t->left;
            return t;
        }
        else if(t->left==NULL)
        {
            t=t->right;
            return t;
        }
        else
        {
            int max = findmax(t->right);
            t->data=max;
            t->right=Delete(t->right,max);
            return t;
        }

    }
}
struct node *insert(struct node *t,int val)
{
    struct node *nd = newnode(val);
    if(t==NULL)return nd;
    else
    {
       if(t->data > val)
           t->left=insert(t->left,val);
       else
           t->right=insert(t->right,val);
    }
    return t;
}

struct node *floor(struct node *t,int val)
{
    if(t==NULL)return t;
    else if(t->data==val)return t;
    else if(t->data > val)return floor(t->left,val);
    else 
    {
        struct node *temp = floor(t->right,val);
        if(temp!=NULL)return temp;
        else
            return t;
    }
}
struct node *ceil(struct node *t,int val)
{
    if(t==NULL)return t;
    else if(t->data==val)return t;
    else if(t->data < val)return ceil(t->right,val);
    else
    {
       struct node *temp=ceil(t->left,val);
       if(temp!=NULL)return temp;
       else
           return t;
    }
}

struct queue *newelement(struct node *te)
{
    struct queue *t=new (struct queue);
    t->p=te;
    t->next=NULL;
    return t;
}
struct queue *enque(struct queue *last,struct node *te)
{
    struct queue *temp=newelement(te);
    if(last==NULL)return temp;
    else
    {
        last->next = temp;
        return temp;
    }
}
struct queue *deque(struct queue *head)
{
    head=head->next;
    return head;
}

void printing(struct queue *t)
{
    cout<<t->p->data<<" ";
}

 void bft(struct queue *head)
{   
    while(head!=NULL)
    {
        printing(head);
        if(head->p->left!=NULL)
            last=enque(last,head->p->left);
        if(head->p->right!=NULL)
            last=enque(last,head->p->right);
        head=deque(head);
    }
}
 
int main()
{
    struct node *root =insert(root,25);
    root=insert(root,3);
    root=insert(root,50);
    root=insert(root,8);
    root=insert(root,1);
    root=insert(root,35);
    root=insert(root,60);
    // now you have the tree
    inorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    cout<<floor(root,100)->data;  
    cout<<ceil(root,20)->data;    
    head=last=enque(head,root);
    printing(head);
    cout<<endl;    
    bft(head); 
    cout<<endl;
    return 0;
}
