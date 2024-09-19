#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
    vector<int>ans;
    int n=arr.size();
    
    for(int col=0;col<mCols;col++){
        if(col%2==0){
            for(int row=0;row<nRows;row++){
                ans.push_back(arr[row][col]);
            }
        }

        else{
            for(int row=n-1;row>=0;row--){
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}
