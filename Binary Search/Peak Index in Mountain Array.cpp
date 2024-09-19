// Approach==> It is strictly increasing then reach Maxima and then strictly decreasing
                So we can apply Binary Search Algorithm

class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        // Your code here
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
       
        while(start<end){
            if(arr[mid]<arr[mid+1]){
               start=mid+1;
            }
            
            else{
                end=mid;
            }
            
            mid=start+(end-start)/2;
        }
        
        return start;
    }
};

