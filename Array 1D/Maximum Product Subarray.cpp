// Brute Force==>Use 2 loops and check for each subarray

class Solution{
public:
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long maxi=INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        long long product=1;
	        
	        for(int j=i;j<n;j++){
	            product=product*arr[j];
	            maxi=max(maxi,product);
	        }
	    }
	    
	    return maxi;
	}
};

====================================================================================================

//Optimal Approch==>Extension of Kadane's Algorithm

class Solution{
public:
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long maxi=INT_MIN;
	    long long prefix=1;
	    long long suffix=1;
	    
	    for(int i=0;i<n;i++){
	        if(prefix==0){
	            prefix=1;
	        }
	        
	        if(suffix==0){
	            suffix=1;
	        }
	        
	        prefix=prefix*arr[i];
	        suffix=suffix*arr[n-i-1];
	        
	        maxi=max(maxi,max(prefix,suffix));
	    }
	    
	    return maxi;
	    
	}
};
