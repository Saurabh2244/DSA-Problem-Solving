// Brute Force==> Use 2 loops and check for each subarray

#include<bits/stdc++.h>>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	int n=arr.size();
	int maxLen=0;

	for(int i=0;i<n;i++){
		int sum=0;
		int cnt=0;
		for(int j=i;j<n;j++){
			sum=sum+arr[j];
			cnt++;
			if(sum==0){
				maxLen=max(maxLen,cnt);
			}
		}
	}

	return maxLen;	
}

==================================================================================================

// Optimal Solution==> Use Prefix Sum concept and use map with [sum,index]

#include<vector>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	int n=arr.size();
	int sum=0;
	int maxLen=0;

	unordered_map<int,int>mpp; //sum-index

	for(int i=0;i<n;i++){
		sum=sum+arr[i];
		if(sum==0){
			maxLen=i+1;
		}

		int remain=sum-0;
		if(mpp.find(remain)!=mpp.end()){
			maxLen=max(maxLen,i-mpp[remain]);
		}

		if(mpp.find(sum)==mpp.end()){
			mpp[sum]=i;
		}
	}

	return maxLen;
	
}
