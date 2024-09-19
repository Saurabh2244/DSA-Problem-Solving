#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int Sum(int n){
    //base case
    if(n==0){
        return 0;
    }
    
    //function call
    return n+Sum(n-1);
}

int main()
{
    int n;
    cout<<"Enter N:";
    cin>>n;
    
    int ans=Sum(n);
    cout<<"Sum of first "<<n<<" Natural Numbers: "<<ans;
    
    return 0;
}
