//Approach==> First Sort array then check difference between 2 Consecutives Elements

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        if(nums.size()==0){
            return 0;
        }

        int cnt=0;
        int maxi=0;

        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                continue;
            }

            if(nums[i+1]-nums[i]==1){
                cnt++;
                maxi=max(maxi,cnt);
            }

            else{
                cnt=0;
            }
        }
        return maxi+1;
    }
};
