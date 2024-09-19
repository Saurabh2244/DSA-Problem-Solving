// Conditions==> I) Integers in each row are sorted in ascending from left to right.
                 II) Integers in each column are sorted in ascending from top to bottom.

                // Matrix is row and col wise sorted

=========================================================================================================================

// Brute Force==> Apply Linear Search on 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }

        return false;
    }
};

==========================================================================================================================

// Optimal Solution==> Use Binary Search.
                       Here matrix is row and col wise sorted. So we can't direct apply Binary Search but
                       we can find position before which all elements are smaller and below which all elements are greater
                       i.e. Position is right top corner
                       if target<position==> then we definately says that our target is not lie below position. So eliminate it
                       Similarly, eliminate right part


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int i=0;
        int j=col-1;

        while(i<row && j>=0){
            
            int curr=matrix[i][j];
            
            if(curr==target){
                return true;
            }

            else if(curr>target){
                j--;
            }

            else{
                i++;
            }
        }

        return false;
    }
};
