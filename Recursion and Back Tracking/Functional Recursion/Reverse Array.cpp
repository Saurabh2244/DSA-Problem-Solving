#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void Reverse(int i,int arr[],int n){
    //base case
    if(i>=n/2){
        return;
    }
    
    //Process
    swap(arr[i],arr[n-i-1]);
    
    //Function Call
    Reverse(i+1,arr,n);
   
}

int main()
{
    int n;
    cout<<"Enter size of Array:";
    cin>>n;
    
    cout<<"Enter Elements in array:";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    Reverse(0,arr,n);
    
    cout<<"Reverse Array:"<<endl;
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
