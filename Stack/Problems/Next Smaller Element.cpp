// Brute Force==> Use 2 loops

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
	vector<int>ans;

	for(int i=0;i<n;i++){
		int elm=arr[i];

		for(int j=i+1;j<n;j++){
			if(arr[j]<elm){
				elm=arr[j];
				ans.push_back(elm);
				break;
			}
		}

		if(elm==arr[i]){
			ans.push_back(-1);
		}
	}

	return ans;
}

=============================================================================================================================
=============================================================================================================================

// Optimal Solution==> Use stack. Iterate from end

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
	vector<int>ans(n);
	stack<int>st;
	st.push(-1);

	for(int i=n-1;i>=0;i--){
		int elm=arr[i];

		if(elm>st.top()){
			ans[i]=st.top();
			st.push(elm);
		}

		else{
			while(!st.empty() && st.top()>=elm){
				st.pop();
			}

			ans[i]=st.top();
			st.push(elm);
		}
	}

	return ans;
}
