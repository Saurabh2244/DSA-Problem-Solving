#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int NthFabonacciNum(int n){
    //base case
    if(n<=1){
        return n;;
    }
    
    int ek_Kadam_pichewala=NthFabonacciNum(n-1);
    
    int do_Kadam_pichewala=NthFabonacciNum(n-2);
    
    //Function Call
    return ek_Kadam_pichewala+do_Kadam_pichewala;
    
}

int main()
{
    int n;
    cout<<"Enter N:";
    cin>>n;
    
    int ans=NthFabonacciNum(n);
    
    cout<<n<<"th Fibonacci Number is "<<ans;
    
    return 0;
}
