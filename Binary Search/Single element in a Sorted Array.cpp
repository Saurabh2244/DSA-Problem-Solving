// Approach 1==> Use map to store count

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for( auto &x:mpp){
            if(x.second==1){
                return x.first;
            }
        }

        return -1;
    }
};
=================================================================================================================================================================
// Approach 2==> Use XOR

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        int XOR=0;

        for(int i=0;i<n;i++){
            XOR=XOR^nums[i];
        }

        return XOR;
    }
};

====================================================================================================================================================================
// Approach 3==> Use Linear Search ==> if element left side element or right side element any one is equal then element occurs twice else element occurs single

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return nums[0];
        }

        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]!=nums[i+1]){
                    return nums[i];
                }
            }

            else if(i==n-1){
                if(nums[i]!=nums[i-1]){
                    return nums[i];
                }
            }

            else{
                if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]){
                    return nums[i];
                }
            }
        }

        return -1;
    }
};

===================================================================================================================================================================

// Approach 4==> Use Binary Search (It's very important. Please revise it regularly)

class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //handle edge cases seprately
        if(n==1){
            return arr[0];
        }
        
        else if(arr[0]!=arr[1]){
            return arr[0];
        }
        
        else if(arr[n-1]!=arr[n-2]){
            return arr[n-1];
        }
     
        //Apply binary search on 1 to n-2
        int start=1;
        int end=n-2;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            //check mid element is answer or not
            if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]){
                return arr[mid];
            }
            
            //eliminating left half
            else if( (mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1]) ){
                start=mid+1;
            }
            
            //eliminating right half
            else{
                end=mid-1;
            }
        }
        
        return -1;
    }
};
