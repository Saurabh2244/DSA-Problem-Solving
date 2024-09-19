// Brute Force==> Use 2 loops and check for each day seprately

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int maxi_Profit=0;

        for(int i=0;i<n;i++){
            int cp=prices[i];

            for(int j=i+1;j<n;j++){
                int profit=prices[j]-cp;
                maxi_Profit=max(profit,maxi_Profit);
            }
        }
        
        return maxi_Profit;
    }
};

==================================================================================================

// Optimal Solution==> Use only 1 loop

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=prices[0];
        int maxi_Profit=0;

        int i=1;
        while(i<n){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }

            maxi_Profit=max(maxi_Profit,prices[i]-minPrice);
            i=i+1;
        }

        return maxi_Profit;
    }
};
