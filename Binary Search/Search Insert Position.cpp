//Problem Statement==>Given a sorted array of distinct integers and a target value, return 
  the index if the target is found. If not, return the index where it would be if it were inserted in order.

// Approach==> Array is sorted so we can think about Binary Search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;

        while(start<=end){
            if(nums[mid]==target){
                return mid;
            }

            else if(nums[mid]<target){
                start=mid+1;
            }

            else{
                end=mid-1;
            }

            mid=start+(end-start)/2;
        }   

        return start;
    }
};
