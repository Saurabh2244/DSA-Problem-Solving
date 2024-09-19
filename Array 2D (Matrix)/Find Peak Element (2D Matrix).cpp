class Solution {
public:

    //find row index of max element and col index is given by mid
    int getMaxElement(vector<vector<int>>&matrix,int mid){
        int index=-1;
        int maxi=INT_MIN;

        for(int row=0;row<matrix.size();row++){
            int elm=matrix[row][mid];

            if(elm>maxi){
                maxi=max(maxi,elm);
                index=row;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int start=0;
        int end=m-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            
            // we find maximum because we have to check top, bottom,left,right if we use maximum then our element is definately 
            // greater than top and bottom. so we need to check only left and right i.e. our problem is reduced to find peak in 1d

            int row=getMaxElement(matrix,mid);
            int left=-1;
            int right=-1;
            
            //handling edge cases
            if(mid-1>0){
                left=matrix[row][mid-1];
            }

            if(mid+1<m){
                right=matrix[row][mid+1];
            }
            
            // we find peak element
            if(matrix[row][mid]>left && matrix[row][mid]>right){
                return {row,mid};
            }
            
            //our peak is on left side of mid so eliminate right part
            else if(matrix[row][mid]>right){
                end=mid-1;
            }
            
            //our peak is on right side of mid so eliminate left part
            else{
                start=mid+1;
            }
        }

        return {-1,-1};
    }
};
