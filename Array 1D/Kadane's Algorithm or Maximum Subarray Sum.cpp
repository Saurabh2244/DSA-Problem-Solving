// Brute Force==>Check sum of each sub array

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum=sum+arr[j];
                maxi=max(maxi,sum);
            }
        }
        
        return maxi;
    }
};

==========================================================================================================

//Approach 2==>Use Kadane's Algorithm

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxi=INT_MIN;
        long long sum=0;
        
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            maxi=max(sum,maxi);
            
            if(sum<0){
                sum=0;
            }
        }
        
        return maxi;
        
    }
};
