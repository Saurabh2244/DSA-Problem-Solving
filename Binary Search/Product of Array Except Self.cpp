// Brute Force==> Use 2 loops and check for each but if i==j then it not consider (continue) because product of array except itself

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        vector<long long int> ans;
        
        for(int i=0;i<n;i++){
            long long int product=1;
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                else{
                    product=product*nums[j];
                }
            }
            ans.push_back(product);
        }
        
        return ans;
    }
};

====================================================================================================

// Optimal Solution==> Create 2 more arrays i.e. left and right and initilised with first and last element of left
                       and right respectively as 1.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;

        vector<int>left(n);
        left[0]=1;

        vector<int>right(n);
        right[n-1]=1;

        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i-1];
        }

        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            int product=left[i]*right[i];
            ans.push_back(product);
        }

        return ans;
    }
};
