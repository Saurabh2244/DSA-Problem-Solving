// For each element we have 2 options either take or not take

solve by using take not take approach
==========================================================================================================================

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool solve(int index,int sum,vector<int>&ds,vector<int>&arr,int n,int target){
    
    // base case
    if(index==n){
        if(sum==target){
            return true;
        }
        else{
            return false;
        }
        
    }
    
    ds.push_back(arr[index]);
    sum=sum+arr[index];
   
    bool left=solve(index+1,sum,ds,arr,n,target); //take
    
    if(left==true){
        return true;
    }
    
    sum=sum-arr[index];
    ds.pop_back();
    
    bool right=solve(index+1,sum,ds,arr,n,target); // not take
    
    if(right==true){
        return true;
    }
    
    return false;
}

bool subSequence(vector<int>&arr,int n,int sum){
    vector<int>ds;
    
    int index=0;
    
    bool ans=solve(index,0,ds,arr,n,sum);
    
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
    
    bool ans=subSequence(arr,n,sum);
    
    if(ans==true){
        cout<<"Subsequences whose sum equals to "<<sum<<" is Present";
    }
    
    else{
        cout<<"Subsequences whose sum equals to "<<sum<<" is Absent";
    }
    
    return 0;
}
