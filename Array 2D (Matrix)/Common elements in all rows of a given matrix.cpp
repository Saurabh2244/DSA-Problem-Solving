#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>solve(vector<vector<int>>&matrix){
    int row=matrix.size();
    int col=matrix[0].size();
    
    unordered_map<int,int>mpp;
    vector<int>ans;
    for(int i=0;i<col;i++){
        mpp[matrix[0][i]]=1;
    }
    
    for(int i=1;i<row;i++){
        for(int j=0;j<col;j++){
            int elm=matrix[i][j];
            
            if(mpp.find(elm)!=mpp.end()){
                if(mpp[elm]==i){
                    mpp[elm]++;
                }
            }
        }
    }
    
    for(auto x:mpp){
        if(x.second==row){
            ans.push_back(x.first);
        }
    }
    
    return ans;
}

int main()
{ 
    int n,m;
    
    cout<<"Enter Row:";
    cin>>n;
    
    cout<<"Enter Col:";
    cin>>m;
    
    vector<vector<int>>matrix(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Matrix ["<<i<<"]["<<j<<"]:";
            cin>>matrix[i][j];
        }
    }
    
    cout<<endl<<endl;
    
   vector<int>ans=solve(matrix);
   
   cout<<"Common Elements: ";
   
   for(int i=0;i<ans.size();i++){
       cout<<ans[i]<<" ";
   }
    
    return 0;

}
