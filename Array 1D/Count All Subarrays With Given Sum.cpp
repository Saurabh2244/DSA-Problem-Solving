// Brute Force==> Use 2 loops and check for each subarray

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            int sum=0;
        
            for(int j=i;j<n;j++){
                sum=sum+nums[j];
                if(sum==k){
                   cnt++;
                }
            }
        }

        return cnt;
    }
};

=======================================================================================================

// Optimal Solution==> Use prefix Sum approach and create map of [sum,cnt] but initilized map with [0,1]
                       cnt=cnt+mpp[remain]

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        int sum=0;

        unordered_map<int,int>mpp;
        mpp[0]=1;
        
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            int remain=sum-k;
        
            if(mpp.find(remain)!=mpp.end()){
                cnt=cnt+mpp[remain];
            }
        
            mpp[sum]++;
        }

        return cnt;
    }
};
