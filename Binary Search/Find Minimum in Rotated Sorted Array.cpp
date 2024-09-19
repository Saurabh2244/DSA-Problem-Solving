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

=================================================================================================================================================

// Better Solution==> Use in built function "*min_element"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        int ans= *min_element(nums.begin(),nums.end());

        return ans;
    }
};

==================================================================================================================================================

// Optimal Solution==> Since array is rotated and sorted, So we can think about binary search
                       minimum element means We have to find Pivot
                       if( arr[0]<arr[n-1]) ==> means our array is not rotated. So minimum element is first element

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        
        //array is not rotated
        if(nums[0]<nums[n-1]){
            return nums[0];
        }

        int start=0;
        int end=n-1;

        int ans=-1;
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

        return nums[start];
    }
};

===================================================================================================================

// Best Optimal Solution==>

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        int start=0;
        int end=n-1;

        while(start<end){
            int mid=start+(end-start)/2;
            
            //we definately says that our minimum element will lie after mid 
            if(nums[mid]>nums[end]){
                start=mid+1;
            }

            //our minimum element will lie before mid
            else{
                end=mid;
            }
        }

        return nums[start];
    }
};
