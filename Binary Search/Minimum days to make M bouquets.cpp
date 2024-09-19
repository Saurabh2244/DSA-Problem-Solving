// Why Binary Search==> We are not given any sorted array on which we can apply binary search.
                       But, if we observe closely, we can notice that our answer space i.e. [mini(arr[]), max(arr[])] 
                       is sorted. So, we will apply binary search on the answer space.

=======================================================================================================================

// Approach==>

1) If m*k > arr.size: This means we have insufficient flowers. So, it is impossible to make m bouquets and we will return -1.

2) Next, we will find the maximum element i.e. max(arr[]), and the minimum element i.e. min(arr[]) in the array.

3) Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point 
   to min(arr[]) and the high will point to max(arr[]).

4) Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
      mid = low+(high-low)/2  ......(To avoid overflow)

5) Eliminate the halves based on the value returned by possible():
   We will pass the potential answer, represented by the variable ‘mid’ (which corresponds to a specific day), 
   to the ‘possible()’ function.
        I) If possible() returns true: On satisfying this condition, we can conclude that 
           the number ‘mid’ is one of our possible answers. But we want the minimum number. 
           So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
        
        II) Otherwise, the value mid is smaller than the number we want. 
            This means the numbers greater than ‘mid’ should be considered and the right half of ‘mid’ 
            consists of such numbers. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).

6) Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.

The steps from 3-5 will be inside a loop and the loop will continue until low crosses high.

===============================================================================================================

class Solution {

private:
    bool isPossible(vector<int>&bloomDay,int n,int m,int k,int mid){
        int cnt=0;
        int number_of_boquets=0;

        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }

            else{
                number_of_boquets+=cnt/k;
                cnt=0;
            }
        }

        number_of_boquets+=cnt/k;

        if(number_of_boquets<m){
            return false;
        }

        else{
            return true;
        }
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        // m==> Number of boquets to be formed
        // k==> Number of adjacent flowers to be used

        int start=*min_element(bloomDay.begin(),bloomDay.end());
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        
        int ans=-1;
        int mid=start+(end-start)/2;

        while(start<=end){
            if(isPossible(bloomDay,n,m,k,mid)){
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
                    
