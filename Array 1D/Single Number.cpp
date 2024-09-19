// Approach 1==>  Use Hashmap

class Solution{
public:	
	int search(int arr[], int n){
	    //code
	    
	    unordered_map<int,int>mpp;
	    for(int i=0;i<n;i++){
	        mpp[arr[i]]++;
	    }
	    
	    for(auto &x:mpp){
	        if(x.second==1){
	            return x.first;
	        }
	    }
	    
	    return -1;
	    
	}
};
================================================================================================================

// Approach 2==> Use Bit Manupulation (XOR Operator)

class Solution{
public:	
	int search(int arr[], int n){
	    //code
	    
	   int XOR=0;
	   for(int i=0;i<n;i++){
	       XOR=XOR^arr[i];
	   }
	   
	   return XOR;
	    
	}
};
