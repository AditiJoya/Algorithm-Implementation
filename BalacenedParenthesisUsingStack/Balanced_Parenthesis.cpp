#include<bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    int n = s.size();

    stack<char> st;
    bool ans = true;

    for(int i=0;i<n;i++)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                st.push(s[i]);
            }
        else if(!st.empty() && s[i] == ')')
        {
            if(st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if(s[i] == '}')
        {
            if(!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if(s[i] == ']')
        {
            if(!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }

    if(!st.empty())
        return false;
    return ans;
}



int main()
{
    //"{([])}";
    string s;
    cout<<"enter input:"<<endl;
    cin>> s;
    int count=0;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[' ||s[i]==']' ||s[i]=='}' || s[i]==')')
            {
                count=0;
            }
            else
            {
                count++;
                break;
            }

    }

    if(count==0)
    {

    if(isValid(s))
    {
        cout<<"balanced"<<endl;
    }
    else
    {
        cout<<"Not Balanced"<<endl;
    }

    }
    if(count>0)
    {
        cout<<"not valid "<<endl;
    }

}
