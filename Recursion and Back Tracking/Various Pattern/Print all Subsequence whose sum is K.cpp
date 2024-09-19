// For each element we have 2 options either take or not take

solve by using take not take approach
==========================================================================================================================


#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(int index,int sum,vector<vector<int>>&ans,vector<int>&ds,vector<int>&arr,int n,int target){
    
    // base case
    if(index==n){
        if(sum==target){
            ans.push_back(ds);
        }
        return;
    }
    
    ds.push_back(arr[index]);
    sum=sum+arr[index];
    solve(index+1,sum,ans,ds,arr,n,target); //take
    
    sum=sum-arr[index];
    ds.pop_back();
    
    solve(index+1,sum,ans,ds,arr,n,target); // not take
}

vector<vector<int>>subSequence(vector<int>&arr,int n,int sum){
    
    vector<vector<int>>ans;
    vector<int>ds;
    
    int index=0;
    
    solve(index,0,ans,ds,arr,n,sum);
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
    
    vector<vector<int>>ans=subSequence(arr,n,sum);
    
    // print subsequences
    for(auto&x:ans){
        if(x.size()==0){
            cout<<"{}";
        }
        
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}
