// Brute Force Approach ==> Create another array and store values on it in correct order
class Solution{
    public:
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        d=d%n;
        int ans[n];
      
        for(int i=d;i<n;i++){
            ans[i-d]=arr[i];
        }
        
        for(int i=0;i<d;i++){
            ans[n-d+i]=arr[i];
        }
        
        for(int i=0;i<n;i++){
            arr[i]=ans[i];
        }
    }
};

=====================================================================================================================

//Optimal Approach ==> Reverse first D elements then reverse all elemnts but start from D+1 and in last reverse whole array
class Solution{
    public:
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        d=d%n;
        
        reverse(arr,arr+d);
        reverse(arr+d,arr+n);
        
        reverse(arr,arr+n);
    }
};
