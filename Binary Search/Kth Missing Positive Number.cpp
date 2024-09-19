// Brute Force==> The main idea is to shift k by 1 step if the current element is smaller or equal to k. 
                   And whenever we get a number > k, we can conclude that k is the missing number.

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                k=k+1;
            }
        }

        return k;
    }
};

===========================================================================================================

// Optimal Solution==> 

We cannot apply binary search on the answer space here as we cannot assure which missing number has 
the possibility of being the kth missing number. That is why, we will do something different here. 
We will try to find the closest neighbors (i.e. Present in the array) for the kth missing number by counting 
the number of missing numbers for each element in the given array.

Let’s understand it using an example. Assume the given array is {2, 3, 4, 7, 11}. Now, if no numbers were missing the given array would look like {1, 2, 3, 4, 5}. Comparing these 2 arrays, we can conclude the following:

* Up to index 0: Only 1 number i.e. 1 is missing in the given array.
* Up to index 1: Only 1 number i.e. 1 is missing in the given array.
* Up to index 2: Only 1 number i.e. 1 is missing in the given array.
* Up to index 3: 3 numbers i.e. 1, 5, and 6 are missing.
* Up to index 4: 6 numbers i.e. 1, 5, 6, 8, 9, and 10 are missing.

For a given value of k as 5, we can determine that the answer falls within the range of 7 to 11. Since there are 
only 3 missing numbers up to index 3, the 5th missing number cannot be before vec[3], which is 7. Therefore, 
it must be located somewhere to the right of 7. Our actual answer i.e. 9 also supports this theory. 
So, by following this process we can find the closest neighbors (i.e. Present in the array) for the kth missing number. 
In our example, the closest neighbors of the 5th missing number are 7 and 11.

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        
        int start=0;
        int end=n-1;

        int mid=start+(end-start)/2;

        while(start<=end){
            int miss=arr[mid]-(mid+1);

            if(miss<k){
                start=mid+1;
            }

            else{
                end=mid-1;
            }

            mid=start+(end-start)/2;
        }

        return k+start;
    }
};
