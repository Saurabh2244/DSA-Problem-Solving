// Implementation of Binary Search Algorithm

// Binary Search Algorithm is applicable only if array is sorted

class Solution {
  public:
    int binarysearch(int arr[], int n, int key) {
        // code here
        
        int start=0;
        int end=n-1;
        
        int mid=start+(end-start)/2;
        
        while(start<=end){
            if(arr[mid]==key){
                return mid;
            }
            
            else if(arr[mid]<key){
                start=mid+1;
            }
            
            else if(arr[mid]>key){
                end=mid-1;
            }
            
            mid=start+(end-start)/2;
        }
        
        return -1;
    }
};
