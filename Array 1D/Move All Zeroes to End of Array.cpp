// Brute Force ==>Create another array and store non zero elements in it and again push new array elements to old array

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    
	    vector<int>ans;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]!=0){
	            ans.push_back(arr[i]);
	        }
	    }
	    
	    for(int i=0;i<ans.size();i++){
	        arr[i]=ans[i];
	    }
	    
	    for(int i=ans.size();i<n;i++){
	        arr[i]=0;
	    }
	}
};

=========================================================================================================
//Optimal Solution==> Use Two Pointer Approach if number is non zero then place it at position k and after traversal
                     of array make remaining elements are 0

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
        int k=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                arr[k]=arr[i];
                k=k+1;
            }
        }
        
        for(;k<n;k++){
            arr[k]=0;
        }
	}
};
