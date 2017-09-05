#include <iostream>
#include <vector>
#include <algorithm>
using namespace :: std ;
struct node
{
    int d,s,t;
    struct node *left;
    struct node *right;
};
struct info
{
    int d,t,s;
};
struct node *insert(struct node *t,int D,int T,int S)
{
    if(t==NULL)
    {
        struct node *nd=new (struct node);
        nd->d=D;
        nd->t=T;
        nd->s=S;
        cout<<D<<T<<S<<endl;
        return nd;
    }
    else
    {
        if(t->s<S)
        t->right=insert(t->right,D,T,S);
        else
        t->left=insert(t->left,D,T,S);
    }
    return t;
}
void inorder(struct node *nd)
{
    if(nd==NULL)return ;
    inorder(nd->left);
    cout<<nd->d<<" "<<nd->t<<" "<<nd->s<<endl;
    inorder(nd->right);
    cout<<endl;
}  
bool sort_by_d(const info &a,const info &b)
{
    return (a.s<b.s) ;
}


int cd=1;

void modify(struct node *nd,int days,struct node *root)
{    int calledl=0;
    int calledr=0;
    if(nd->s==20)cout<<"called A"<<endl;
    if(nd->s==70)cout<<"called B"<<endl;
    if(nd->s==100)cout<<"called D"<<endl;
    if(nd->s==50)cout<<"Called C"<<endl;
    if(nd->right!=NULL){
        calledr=1;
        modify(nd->right,days,root);
        //if(calledr)modify(nd,days,root);
        //return;
    }
    if(nd->t>0 && cd<=days && cd>=nd->d)
    {
        nd->t--;cd++;
        return ;
    }
    if (nd->left!=NULL){
        int calledl=1;
        modify(nd->left,days,root);
        if(calledl)modify(nd,days,root);}
    else
        return ;
}
        







int main()  {
    int n,days,i;
    cin>>n>>days;
    int d,t,s;
    struct node *root=NULL;
    vector  <info> vec;
    vec.resize(n);
    for(i=0;i<n;i++)
    {
        cin>>vec[i].d>>vec[i].t>>vec[i].s;
      
    }
    sort(vec.begin(),vec.end(),sort_by_d);

    for(i=0;i<n;i++)
    {
        root=insert(root,vec[i].d,vec[i].t,vec[i].s);
      
    }     
    inorder(root);
    // NOW I HAVE THE REQUIRED BINARY SEARCH TREE  whose root is root
    modify(root,days,root);

     inorder(root);
     cout<<endl<<root->right->s<<endl;
  

    return 0;
}

