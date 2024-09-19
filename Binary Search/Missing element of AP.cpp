// Brute Force==> Find difference and apply loop ad check for each element

class Solution{   
public:
    int findMissing(int arr[], int n) {
        // code here
        int first=arr[0];
        int last=arr[n-1];
        
        int diff=(last-first)/n;
        
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]!=diff){
                return arr[i]-diff;
            }
        }
        
        return -1;
    }
};

==========================================================================================================================

// Optimal Solution==> Binary search

class Solution{   
public:
    int findMissing(int arr[], int n) {
        // code here
        
        //find common diff
        int d=(arr[n-1]-arr[0])/n;
        
        //handling edge cases
        if(arr[1]-arr[0]!=d){
            return arr[0]+d;
        }
        
        if(arr[n-1]-arr[n-2]!=d){
            return arr[n-1]-d;
        }
        
        int start=1;
        int end=n-2;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(arr[mid]-arr[mid-1]!=d){
                return arr[mid]-d;
            }
            
            else if(arr[mid+1]-arr[mid]!=d){
                return arr[mid]+d;
            }
            
           else if((arr[mid]-arr[0])!=mid*d){
               end=mid-1;
           }
           
           else{
               start=mid+1;
           }
        }
        
        return -1;
    }
};
