Problem ==> Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));

        int num=1;
        int startRow=0;
        int startCol=0;

        int endRow=n-1;
        int endCol=n-1;

        int cnt=0;
        int total=n*n;

        while(cnt<total){
            //left to right
            for(int i=startCol;i<=endCol && cnt<total;i++){
                matrix[startRow][i]=num;
                num++;
                cnt++;
            }
            startRow++;

            //top to bottom
            for(int i=startRow;i<=endRow && cnt<total;i++){
                matrix[i][endCol]=num;
                num++;
                cnt++;
            }
            endCol--;

            //right to left
            for(int i=endCol;i>=startCol && cnt<total;i--){
                matrix[endRow][i]=num;
                num++;
                cnt++;
            }
            endRow--;

            //bottom to top
            for(int i=endRow;i>=startRow && cnt<total;i--){
                matrix[i][startCol]=num;
                num++;
                cnt++;
            }
            startCol++;
        }

        return matrix;
    }
};
