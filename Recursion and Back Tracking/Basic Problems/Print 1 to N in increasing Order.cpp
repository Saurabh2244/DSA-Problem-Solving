// Recursion call is first then Process thus it is BackTracking or Head Recursion

==========================================================================================================================

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void Print(int n){
    //base case
    if(n==0){
        return;
    }

    //function call
    Print(n-1);
    
    // process
    cout<<n<<endl;
}

int main()
{
    int n;
    cout<<"Enter N:";
    cin>>n;
    
    Print(n);
    
    return 0;
}
