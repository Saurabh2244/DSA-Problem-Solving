// Conditions==>You are given an m x n integer matrix matrix with the following two properties:

                I) Each row is sorted in non-decreasing order.
                II) The first integer of each row is greater than the last integer of the previous row.
                III) Given an integer target, return true if target is in matrix or false otherwise.

So,if we make single array, then array is completely sorted

==========================================================================================================================

// Brute Force==> Use linear search in matrix

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

=========================================================================================================================

// Optimal Solution==> Apply Binary Search in 2D array

                      array[mid]==> array[mid/col][mid%col]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int start=0;
        int end=row*col-1;

        int mid=start+(end-start)/2;

        while(start<=end){
            int element=matrix[mid/col][mid%col];

            if(element==target){
                return true;
            }

            else if(element>target){
                end=mid-1;
            }

            else{
                start=mid+1;
            }

            mid=start+(end-start)/2;
        }

        return false;
    }
};
