// Upper Bound==> Smallest index such that arr[index] > x

=============================================================================================================================================================

// Brute force==> Use loop (Linear Search)

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) {
            // upper bound found:
            return i;
        }
    }
    return n;
}

==============================================================================================================================================================

// Optimal Solution==> Use Binary Serach

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	

	int start=0;
	int end=n-1;

	int ans=n;
	int mid=start+(end-start)/2;

	while(start<=end){
		if(arr[mid]<=x){
			start=mid+1;
		}

		else if(arr[mid]>x){
			ans=mid;
			end=mid-1;
		}


		mid=start+(end-start)/2;
	}

	return ans;
}

===============================================================================================================================================================

// Approach 3==> This is only for C++ users. Use STL.

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
    
	int ub=upper_bound(arr.begin(),arr.end(),x)-arr.begin();

	return ub;
}
