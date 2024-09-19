// Brute Force==> Merge 2 sorted arrays into third array and sort it. Then find Kth element

#include<bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here

	vector<int>arr3;
	for(int i=0;i<n;i++){
		arr3.push_back(arr1[i]);
	}

	for(int i=0;i<m;i++){
		arr3.push_back(arr2[i]);
	}

	sort(arr3.begin(),arr3.end());

	return arr3[k-1];
}

=======================================================================================================

// Optimal Solution==> It is extension of median of 2 Sorted Arrays.
                       In this problem we patition array as "K" elements on left side and "n-k" on right side

                       start=max(0,k-n2); end=min(k,n1)

                       we set k elements on left part and we find kth element. So ans is max(l1,l2)

#include<bits/stdc++.h>
int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    // Write your code here
	if(n2<n1){
		return kthElement(b,a,n2,n1,k);
	}

	int total=(n1+n2);
	int left=k;

	int start=max(0,k-n2);
	int end=min(k,n1);

	while(start<=end){
		int mid1=start+(end-start)/2;
		int mid2=left-mid1;

		int l1=INT_MIN;
		int l2=INT_MIN;
		int r1=INT_MAX;
		int r2=INT_MAX;

		if(mid1<n1){
			r1=a[mid1];
		}

		if(mid2<n2){
			r2=b[mid2];
		}

		if(mid1-1>=0){
			l1=a[mid1-1];
		}

		if(mid2-1>=0){
			l2=b[mid2-1];
		}

		if(l1<=r2 && l2<=r1){
			return max(l1,l2);
		}

		else if(l1>r2){
			end=mid1-1;
		}

		else{
			start=mid1+1;
		}
	}

	return 0;
}
