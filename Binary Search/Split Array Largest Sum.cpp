// Approach==> This problem is same as Book Allocation Problem. No change

================================================================================================================

class Solution {

private:
    bool isPossible(vector<int>&nums,int n,int k,int mid){
        int cnt=1;
        int sum=0;

        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum=sum+nums[i];
            }

            else{
                cnt++;
                if(cnt>k || nums[i]>mid){
                    return false;
                }

                else{
                    sum=nums[i];
                }
            }
        }
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        
        if(k>n){
            return -1;
        }

        int start=*max_element(nums.begin(),nums.end());
        
        int end=0;
        for(int i=0;i<n;i++){
            end=end+nums[i];
        }

        int mid=start+(end-start)/2;
        int ans=-1;

        while(start<=end){
            if(isPossible(nums,n,k,mid)){
                ans=mid;
                end=mid-1;
            }

            else{
                start=mid+1;
            }

            mid=start+(end-start)/2;
        }

        return ans;
    }
};
