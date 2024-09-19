// Brute Force==> Use 2 loops and check for each subarray

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minLen=INT_MAX;

        for(int i=0;i<n;i++){
            int sum=0;
            int cnt=0;

            for(int j=i;j<n;j++){
                sum=sum+nums[j];
                cnt++;
                if(sum>=target){
                    minLen=min(minLen,cnt);
                }
                
            }
        }

        if(minLen==INT_MAX){
            return 0;
        }

        else{
            return minLen;
        }
    }
};

=================================================================================================================

//Better Solution==> Use Prefix Sum approach and create map [sum,index]

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp; //sum and index pair

        int sum=0;
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=target){
                mini=min(mini,i+1);
            }

            int remain=sum-target;

            for(auto x:mpp){
                if(x.first <= remain){
                    mini=min(mini,i-x.second);
                }
            }

            mpp[sum]=i;
        }

        if(mini==INT_MAX){
            return 0;
        }

        return mini;
    }
};
==================================================================================================================

// Optimal Solution==> All elements are positive. So sum is strictly increasing and we should use 2 Pointer 
                      i.e.left and right approach and shrinking Technique;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        
        int left=0;
        int right=0;
        int sum=nums[0];

        int minLen=INT_MAX;

        while(right<n){
            
            while(left<=right && sum>=target){
                sum=sum-nums[left];
                minLen=min(minLen,right-left+1);
                left++;
            }

            right++;
            if(right<n){
                sum=sum+nums[right];
            }
        }

        if(minLen==INT_MAX){
            return 0;
        }

        else{
            return minLen;
        }
    }
};
