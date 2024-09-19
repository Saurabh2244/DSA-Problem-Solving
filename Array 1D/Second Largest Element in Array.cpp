//GFG Solution

//Use Two Pointer Approach

class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int first=arr[0];
	    int second=INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]>first){
	            second=first;
	            first=arr[i];
	        }
	        
	        else if(arr[i]>second && arr[i]<first){
	            second=arr[i];
	        }
	    }
	    
	    if(second==INT_MIN){
	        return -1;
	    }
	    
	    return second;
	}
};
