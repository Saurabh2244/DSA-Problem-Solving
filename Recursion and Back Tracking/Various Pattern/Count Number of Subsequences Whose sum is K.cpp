// For each element we have 2 options either take or not take

solve by using take not take approach
=======================================================================================================================

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(int index,int sum,vector<int>&ds,vector<int>&arr,int n,int target){
    
    // base case
    if(index==n){
        if(sum==target){
            return 1;
        }
        else{
            return 0;
        }
        
    }
    
    ds.push_back(arr[index]);
    sum=sum+arr[index];
    int left=solve(index+1,sum,ds,arr,n,target); //take
    
    sum=sum-arr[index];
    ds.pop_back();
    
    int right=solve(index+1,sum,ds,arr,n,target); // not take
    
    return left+right;
}

int subSequence(vector<int>&arr,int n,int sum){
    vector<int>ds;
    
    int index=0;
    
    int ans=solve(index,0,ds,arr,n,sum);
    
    return ans;
}

int main()
{
    int n;
    int sum;
    cout<<"Enter Size of Array:";
    cin>>n;
    
    cout<<"Enter Array Elements:";
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"Enter Sum:";
    cin>>sum;
    
    int ans=subSequence(arr,n,sum);
    
    cout<<"Number of Subsequences whose sum equals to "<<sum<<" is: "<<ans;
    
    return 0;
}
