// Brute Force Approach ==>Create another array and store value in it in correct order
class Solution{
    public:
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        d=d%n;
        int ans[n];
      
      
        for(int i=n-d;i<n;i++){
           ans[i-d-1]=arr[i];
            
        }
        
        for(int i=0;i<n-d;i++){
             ans[n-d-1+i]=arr[i];
        }
        
        for(int i=0;i<n;i++){
            arr[i]=ans[i];
        }
    }
};

============================================================================================================
//Optimal Approach==> Reverse n-D elements first then reverse remaining elements and in last reverse whole array

class Solution{
    public:
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        d=d%n;
        
        reverse(arr,arr+n-d);
        reverse(arr+n-d,arr+n);
        
        reverse(arr,arr+n);
    }
};

