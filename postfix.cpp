#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace ::std;
int precedence (char a,char b)
{
    if(a=='/')return 1;
    if(b=='/')return 0;
    if(a=='*')return 1;
    if(b=='*')return 0;
    else
        return 1;
}
int isoperator(char ch)
{
    if(ch=='*'|| ch=='/'|| ch=='+'|| ch=='-'|| ch=='('|| ch==')')
        return 1;
    else return 0;
}
int main ()
{
    int i;
    stack <int> st;
    string str;
    string post="";
    cin>>str;
    str = '(' + str + ')';
    for(i=0;i<str.length();i++)
        {
           char ch = str[i];
           if(isoperator(ch))
           {
                if(ch=='(' || st.empty() || st.top()=='(')
                 {
                     st.push(ch);
                 }
                else if (ch==')')
                {   
                    while(st.top()!='(')
                    {
                        char t = st.top();
                        post+=t;
                        st.pop();
                    }
                }
                else
                {
                    if(precedence(ch,st.top()))
                            {
                                st.push(ch);
                            }
                    else
                    {
                        char t = st.top();
                        post+=t;
                        st.pop();
                        st.push(ch);
                    }
                }
                
           }
           else
           {
               post+=ch;
           }

        }

    cout<<post;

    return 0;
}
