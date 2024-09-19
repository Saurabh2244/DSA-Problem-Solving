// Brute Force==> Use linear Search (loop)

#include<bits/stdc++.h>
using namespace std;
int count(vector<int>& arr, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {

        // counting the occurrences:
        if (arr[i] == x) cnt++;
    }
    return cnt;
}

==============================================================================================================================================================

// Better Approch==> Use map

#include<bits/stdc++.h>
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	unordered_map<int,int>mpp;
	for(int i=0;i<n;i++){
		mpp[arr[i]]++;
	}

	for(auto &elm:mpp){
		if(elm.first==x){
			return elm.second;
		}
	}

	return 0;
}

=================================================================================================================================================================

// Optimal Solution==> Use binary search. 
                       no. of occurence=lastOccur-firstOccur+1;

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int firstOccur(int arr[],int n,int x){
	    int start=0;
	    int end=n-1;
	    int ans=-1;
	    int mid=start+(end-start)/2;

	    while(start<=end){
		   if(arr[mid]==x){
			    ans=mid;
			    end=mid-1;
		   }

		   else if(arr[mid]>x){
			    end=mid-1;
		   }

		   else{
			   start=mid+1;
		   }

		   mid=start+(end-start)/2;
	    }

	    return ans;
	}
	
	int lastOccur(int arr[],int n,int x){
	    int start=0;
	    int end=n-1;
	    int ans=-1;
	    int mid=start+(end-start)/2;

	    while(start<=end){
		   if(arr[mid]==x){
			    ans=mid;
			    start=mid+1;
		   }

		   else if(arr[mid]>x){
			    end=mid-1;
		   }

		   else{
			   start=mid+1;
		   }

		   mid=start+(end-start)/2;
	    }

	    return ans;
	}
	
	int count(int arr[], int n, int x) {
	    // code here
	    int first=firstOccur(arr,n,x);
	    int last=lastOccur(arr,n,x);
	    
	    if(first==-1){
	        return 0;
	    }
	    
	    int ans=last-first+1;
	    return ans;
	}
};
