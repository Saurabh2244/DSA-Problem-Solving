// Approach==> We are not given any sorted array on which we can apply Binary Search.
               But we know that our answer will definitely lie between 1 and maximum element.
               Thus, we can reduced our search space i.e.[1,max Element]

               Our Search space is sorted and thus we can apply binary search on our Search Space.
============================================================================================================

class Solution {
private:
    bool isPossible(vector<int>&nums,int n,int threshold,int mid){
        int sum=0;

        for(int i=0;i<n;i++){
            sum=sum+nums[i]/mid;
            if(nums[i]%mid!=0){
                sum+=1;
            }

            if(sum>threshold){
                return false;
            }
        }

        return true;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int start=1;
        int end=*max_element(nums.begin(),nums.end());

        int ans=-1;
        int mid=start+(end-start)/2;

        while(start<=end){
            if(isPossible(nums,n,threshold,mid)){
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
