// Brute Force==> Create seprate matrix and make observation i.e ans [i] [j] = matrix [col-1-j] [i]

class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        vector<vector<int>>ans(col,vector<int>(row,0));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans[i][j]=matrix[col-1-j][i];
            }
        }

        return ans;
    }
};

======================================================================================================================

// Optimal Approach==> Take Transpose of matrix (i.e. by swap (a[i][j],a[j][i]) ) and reverse each row

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};


