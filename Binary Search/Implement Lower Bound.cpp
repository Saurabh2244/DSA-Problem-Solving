Lower Bound==> Smallest index such that arr[index]>=x

================================================================================================================================================================

// Brute Force==> Use loop (Linear Search)

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            // lower bound found:
            return i;
        }
    }
    return n;
}
==================================================================================================================================================================

// Optimal Solution==> Use binary search

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here

	//a[index]>=x

	int start=0;
	int end=n-1;

	int ans=n;

	int mid=start+(end-start)/2;

	while(start<=end){
		if(arr[mid]>=x){
			ans=mid;
			end=mid-1;
		}

		else{
			start=mid+1;
		}

		mid=start+(end-start)/2;
	}

	return ans;
}

=========================================================================================================================================================

// Approach 3==> Only for C++ user. Use STL

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here

	//a[index]>=x

	int lb=lower_bound(arr.begin(), arr.end(),  x)-arr.begin();

	return lb;
}
