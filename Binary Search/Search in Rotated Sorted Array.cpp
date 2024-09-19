// Brute Force==> Apply Linear Search

class Solution{
    public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        
        for(int i=0;i<h+1;i++){
            if(A[i]==key){
                return i;
            }
        }
        
        return -1;
    }
};

=====================================================================================================================================================================

// Optimal Approach==> Apply Binary Search
                       First find Pivot then check where our key is lie forward pivot or backward pivot and
                       then apply Binary Search in that specific region

class Solution {
public:
    
    int findPivot(vector<int>&nums,int n){
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;

        while(start<end){
            if(nums[0]<=nums[mid]){
                start=mid+1;
            }

            else{
                end=mid;
            }

            mid=start+(end-start)/2;
        }
        return start;
    }

    int binarySearch(vector<int>&nums,int n,int s,int e,int key){
        int start=s;
        int end=e;
        int mid=start+(end-start)/2;

        while(start<=end){
            if(nums[mid]==key){
                return mid;
            }

            else if(nums[mid]<key){
                start=mid+1;
            }

            else{
                end=mid-1;
            }

            mid=start+(end-start)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int pivot=findPivot(nums,n);

        if(nums[pivot]<=target && target<=nums[n-1]){
            return binarySearch(nums,n,pivot,n-1,target);
        }

        else{
            return binarySearch(nums,n,0,pivot-1,target);
        }
    }
};

=============================================================================================================================================================================

// Optimal Solution==> Apply Binary Search
                       There are 2 half. If one is not sorted then definately other is sorted.
                       So, First check first half (i.e start to mid) is sorted or not. If sorted then check element is present in that half or not. If present then eliminate
                            second half. If element not present then eliminate first half

                       similar operation done on second half.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int start=0;
        int end=n-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(nums[mid]==target){
                return mid;
            }
            
            //first half from start to mid is sorted
            else if( nums[start]<=nums[mid] ){
                
                //element found in first half so eliminate second half
                if(nums[start]<=target && target<=nums[mid]){
                    end=mid-1;
                }

                //element not found in first half
                else{
                    start=mid+1;
                }
            }
             
            // second half is sorted
            else{
                
                //element found in second half
                if(nums[mid+1]<=target && target<=nums[end]){
                   start=mid+1;
                }

                // element not found
                else{
                    end=mid-1;
                }
            }
        }

        return -1;
    }
};
