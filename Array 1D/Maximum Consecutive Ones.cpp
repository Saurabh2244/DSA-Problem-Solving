//Use Counter variable to Count

//LeetCode Solution

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();

        int maxi=INT_MIN;
        int cnt=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
                maxi=max(maxi,cnt);
            }

            else{
                cnt=0;
            }
        }

        if(maxi==INT_MIN){
            return 0;
        }

        return maxi;
    }
};
