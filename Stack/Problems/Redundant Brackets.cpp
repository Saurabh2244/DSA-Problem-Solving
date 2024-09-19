// Approach==> If opening i.e.'(' and closing i.e.')' ke bich me koi operator nhi hai to redundant hai
               agar koi operator hai to redundant nhi hai


#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char>st;

    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            char top=st.top();
            st.pop();
            
            bool flag=true;
            while(!st.empty() && top!='('){
                if(top=='+'||top=='-'||top=='*'||top=='/'){
                    flag=false;
                }

                top=st.top();
                st.pop();
            }

            if(flag==true){
                return true;
            }

        }

        else{
            st.push(s[i]);
        }
    }

    return false;
}
