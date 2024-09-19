class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int row=matrix.size();
        int col=matrix[0].size();

        //Indexing
        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;

        int cnt=0;
        int total=row*col;

        while(cnt<total){
            //starting row
            for(int index=startingCol;cnt<total && index<=endingCol;index++){
                ans.push_back(matrix[startingRow][index]);
                cnt++;
            }
            startingRow++;

            //ending column
            for(int index=startingRow;cnt<total && index<=endingRow;index++){
                ans.push_back(matrix[index][endingCol]);
                cnt++;
            }
            endingCol--;

            //ending row
            for(int index=endingCol;cnt<total && index>=startingCol;index--){
                ans.push_back(matrix[endingRow][index]);
                cnt++;
            }
            endingRow--;

            //starting column
            for(int index=endingRow;cnt<total && index>=startingRow;index--){
                ans.push_back(matrix[index][startingCol]);
                cnt++;
            }
            startingCol++;
        }
        return ans;
    }
};
