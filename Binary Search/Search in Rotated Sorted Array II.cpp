// Brute Force==> Use linear search

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();

         for(int i=0;i<n;i++){
             if(nums[i]==target){
                  return true;
             }
         }
         return false;
    }
};

=====================================================================================================================================================================

// Optimal Solution==> Use Binary Search

This problem is advanced version of  Search in Rotated Sorted Array I. In this problem array have duplicates

so just add few lines in  Search in Rotated Sorted Array I code

if(nums[start]==nums[mid] && nums[end]==nums[mid]){
                start=start+1;
                end=end-1;
                continue;
}

// Code==>

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();

        int start=0;
        int end=n-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(nums[mid]==target){
                return true;
            }
            
            else if(nums[start]==nums[mid] && nums[end]==nums[mid]){
                start=start+1;
                end=end-1;
                continue;
            }

            else if(nums[start]<=nums[mid]){
                if(nums[start]<=target && target<=nums[mid]){
                    end=mid-1;
                }

                else{
                    start=mid+1;
                }
            }

            else{
                if(nums[mid+1]<=target && target<=nums[end]){
                    start=mid+1;
                }

                else{
                    end=mid-1;
                }
            }
        }

        return false;
    }
};
