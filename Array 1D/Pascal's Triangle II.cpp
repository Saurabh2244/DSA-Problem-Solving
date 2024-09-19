//Approach==>ans*(row-col+1)/col  =====>(Formula)

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
};
