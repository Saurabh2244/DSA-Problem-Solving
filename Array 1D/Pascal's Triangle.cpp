// Approach==> It is extension of Pascal's Triangle II. In this problem we have to build whole Pascal's Triangle

class Solution {
public:

    vector<int> getRow(int rowIndex) {
        vector<int>Ans;
        Ans.push_back(1);
        
        long long ans=1;
        for(int i=1;i<=rowIndex;i++){
            ans=ans*(rowIndex-i+1)/i;
            Ans.push_back(ans);
        }

        return Ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i=0;i<numRows;i++){
            ans.push_back(getRow(i));
        }

        return ans;
    }
};
