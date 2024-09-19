// Process is first then function call thus it is recursion or Tail Recursion

==========================================================================================================================
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void Print(int n){
    //base case
    if(n==0){
        return;
    }
    
    cout<<n<<endl;
    
    //function call
    Print(n-1);

}

int main()
{
    int n;
    cout<<"Enter N:";
    cin>>n;
    
    Print(n);
    
    return 0;
}
