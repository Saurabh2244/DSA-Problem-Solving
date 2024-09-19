// Tips==> This problem is same as Find Minimum in Rotated Sorted Array I. Only difference is array contain duplicates.

           So,handle else condition of "Find Minimum in Rotated Sorted Array I seprately."

===========================================================================================================

// Brute Force ==> Apply linear search for finding minimum

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<=mini){
                mini=nums[i];
            }
        }

        return mini;
    }
};

=================================================================================================================

// Optimal Solution==> Use binary search

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        int start=0;
        int end=n-1;

        while(start<end){
            int mid=start+(end-start)/2;

            if(nums[mid]>nums[end]){
                start=mid+1;
            }

            else if(nums[mid]<nums[end]){
                end=mid;
            }

            else if(nums[mid]==nums[end]){
                end=end-1;
            }
        }

        return nums[start];
    }
};
