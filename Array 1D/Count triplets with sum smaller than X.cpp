// Note==> This Problem is same as 3 Sum only diff is sum<target not sum==target

=========================================================================================================================

// Brute Force==> Use 3 loops and check for each

class Solution{
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long cnt=0;
	    
	    for(int i=0;i<n;i++){
	        long long elm1=arr[i];
	        
	        for(int j=i+1;j<n;j++){
	            long long elm2=arr[j];
	            
	            for(int k=j+1;k<n;k++){
	                long long elm3=arr[k];
	                
	                if(elm1+elm2+elm3<sum){
	                    cnt++;
	                }
	            }
	        }
	    }
	    return cnt;
	}
		 

};

=========================================================================================================================

// Better Solution==> Use Hashset

class Solution{
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long cnt=0;
	    
	    for(int i=0;i<n;i++){
	        long long elm1=arr[i];
	        set<long long>hashSet;
	        for(int j=i+1;j<n;j++){
	            long long elm2=arr[j];
	            
	            long long remain=(sum)-(elm1+elm2);
	            
	            for(auto &x:hashSet){
	                if(x<remain){
	                    cnt++;
	                }
	            }
	            
	            hashSet.insert(arr[j]);
	        }
	    }
	    return cnt;
	}
		 

};

===================================================================================================================

// Optimal Solution==> Sort array and Use 2 Pointer approach

class Solution{
	
	public:
	long long countTriplets(long long arr[], int n, long long target)
	{
	    // Your code goes here
	    long long cnt=0;
	    sort(arr,arr+n);
	    
	    for(int i=0;i<n;i++){
	        int j=i+1;
	        int k=n-1;
	        
	        long long elm1=arr[i];
	        while(j<k){
	            long long elm2=arr[j];
	            long long elm3=arr[k];
	            
	            long long sum=elm1+elm2+elm3;
	            
	            if(sum<target){
	                cnt+=k-j;
	                j++;
	            }
	            
	            else{
	                k--;
	            }
	        }
	    }
	    return cnt;
	}
		 

};
