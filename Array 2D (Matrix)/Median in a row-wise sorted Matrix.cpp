// Note==> This problem is same as find kth minimum in row and column wise sorted matrix 
            Here we have to find kth means (row*col)/2+1 element (i.e. median)

           use same brute force and better solution approch that used in find kth minimum in row and column wise 
           sorted matrix problem.

===============================================================================================================================

// Optimal Solution==> Here matrix is only row wise sorted not col wise.

                      So, traverse through matrix and set start as minimum and end as maximum and then apply binary search

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int row, int col){
        // code here          
        int start=INT_MAX;
        int end=INT_MIN;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                start=min(start,matrix[i][j]);
                end=max(end,matrix[i][j]);
            }
        }
        
        int k=(row*col)/2+1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            int cnt=0;

            for(int i=0;i<row;i++){
                cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }

            if(cnt<k){
                start=mid+1;
            }

            else{
                end=mid-1;
            }
        }

        return start;
    }
};
