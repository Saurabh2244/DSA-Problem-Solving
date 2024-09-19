#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool isPali(int i,string str,int n){
    //base case
    if(i>=n/2){
        return true;
    }
    
    //Process
    if(str[i]!=str[n-i-1]){
        return false;
    }
    
    //Function Call
    return isPali(i+1,str,n);
    
}

int main()
{
    string str;
    cout<<"Enter String:";
    cin>>str;
    
    int n=str.length();
    
    bool ans=isPali(0,str,n);
    if(ans==true){
        cout<<"String "<<str<<" is Palindrome";
    }
    
    else{
        cout<<"String "<<str<<" is not Palindrome";
    }
    
    return 0;
}
