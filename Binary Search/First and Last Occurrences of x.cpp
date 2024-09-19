// Brute Force==> Use 2 pointers i.e. first and last and apply Linear Search

class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>ans;
        int first=-1;
        int last=-1;
        
        for(int i=0;i<n;i++){
            if(arr[i]==x && first==-1){
                first=i;
                last=i;
            }
            
            else if(arr[i]==x && first!=-1){
                last=i;
            }
        }
        
        return {first,last};
    }
};

================================================================================================

// Optimal Solution==> Since array is Sorted thus we can thing about Binary Search

class Solution
{
    public:
    int firstOccur(int arr[],int n,int x){
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        
        int ans=-1;
        while(start<=end){
            if(arr[mid]==x){
                ans=mid;
                end=mid-1;
            }
            
            else if(arr[mid]>x){
                end=mid-1;
            }
            
            else if(arr[mid]<x){
                start=mid+1;
            }
            
            mid=start+(end-start)/2;
        }
        
        return ans;
    }
    
    int lastOccur(int arr[],int n,int x){
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        int ans=-1;
        
        while(start<=end){
            if(arr[mid]==x){
                ans=mid;
                start=mid+1;
            }
            
            else if(arr[mid]<x){
                start=mid+1;
            }
            
            else if(arr[mid]>x){
                end=mid-1;
            }
            
            mid=start+(end-start)/2;
        }
        
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first=firstOccur(arr,n,x);
        int last=lastOccur(arr,n,x);
        
        return {first,last};
    }
};
