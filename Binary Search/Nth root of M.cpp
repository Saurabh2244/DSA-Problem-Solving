// Brute Force==> Apply loop from 1 to m and check pow(i,n)  
                  if pow(i,n)==m ==>return i;
                  if pow(i,n)>m==> return -1;

#include<bits/stdc++.h>

int NthRoot(int n, int m) {
  // Write your code here.
  for(int i=1;i<=m;i++){
    if(pow(i,n)==m){
      return i;
    }

    else if(pow(i,n)>m){
      return -1;
    }
  }

  return -1;
}

============================================================================================================================================================

// Optimal Solution ==> We are sure that our answer is lie between 1 and m. and answer range is sorte. So we can apply binary search on search space
                        if pow(mid,n)==m  ==> return mid;
                        if pow(mid,n) >m ==> end=mid-1;
                        else ==> start=mid+1

class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int start=1;
	    int end=m;
	    
	    int mid=start+(end-start)/2;
	    
	    while(start<=end){
	        
	        if(pow(mid,n)==m){
	            return mid;
	        }
	        
	        else if(pow(mid,n)>m){
	            end=mid-1;
	        }
	        
	        else{
	            start=mid+1;
	        }
	        
	        mid=start+(end-start)/2;
	    }
	    
	    return -1;
	}  
};
