//Approach==> Array is sorted and Rotated
              Pivot means smallest or minimum

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
            if(arr[0]<=arr[mid]){
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

=====================================================================================================================================================================

// Other Binary Search Approach (Best Approach)

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
          
            if(arr[mid]>arr[end]){  // we definately says that our answer is not lie in left half so eliminate left part
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
