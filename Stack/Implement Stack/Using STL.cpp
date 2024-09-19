#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>st;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    //size of stack
    cout<<"Size: "<<st.size()<<endl;
    
    //pop elements from stack
    st.pop();
    
    //print top
    cout<<"Top: "<<st.top()<<endl;
    
    cout<<"Stack Elements: ";
    //print stack
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
    cout<<endl;
    
    //check empty or not
    cout<<"Stack is empty: "<<st.empty();
    return 0;
}

