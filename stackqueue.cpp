#include <iostream>
#include <stack>   // st.push st.pop st.top  stack <int> st
#include <queue>   // q.push q.pop q.front   queue <int> q
using namespace :: std;
int main ()
{
    queue <int> q;
    stack <int> st;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    while(q.size())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    while(st.size())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}
     
