// For each element we have 2 options either take or not take

solve by using take not take approach
====================================================================================================================

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(int index,vector<vector<int>>&ans,vector<int>&ds,vector<int>&arr,int n){
    
    // base case
    if(index==n){
        ans.push_back(ds);
        return;
    }
    
    ds.push_back(arr[index]);
    solve(index+1,ans,ds,arr,n); //take
    
    ds.pop_back();
    
    solve(index+1,ans,ds,arr,n); // not take
}

vector<vector<int>>subSequence(vector<int>&arr,int n){
    
    vector<vector<int>>ans;
    vector<int>ds;
    
    int index=0;
    
    solve(index,ans,ds,arr,n);
    return ans;
}

int main()
{
    int n;
    cout<<"Enter Size of Array:";
    cin>>n;
    
    cout<<"Enter Array Elements:";
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<vector<int>>ans=subSequence(arr,n);
    
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
