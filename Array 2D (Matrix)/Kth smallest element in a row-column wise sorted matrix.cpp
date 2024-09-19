// Brute Foce==> Traverse through matrix and store each element in 1d vector and then sort vector and return vector[k-1]

#include <bits/stdc++.h> 
int kMinFloor(vector<vector<int>> &squareCity, int n, int k) {
	// Write your code here.

	vector<int>ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans.push_back(squareCity[i][j]);
		}
	}

	sort(ans.begin(),ans.end());

	return ans[k-1];
}

==============================================================================================================================

// Better Solution==> Use Priority Queue. Traverse through matrix and add each element in priority queue. If priority queue 
                      size >k then pop from priority queue

#include <bits/stdc++.h> 
int kMinFloor(vector<vector<int>> &squareCity, int n, int k) {
	// Write your code here.

    priority_queue<int>pq;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			pq.push(squareCity[i][j]);
			if(pq.size()>k){
				pq.pop();
			}
		}
	}

	return pq.top();
}

=============================================================================================================================

// Optimal Solution==> Since, Matrix is row and col wise sorted thus we can think about binary search
                       Start=a[0][0], end=a[n-1][n-1]
                       find mid.

                       Find how many elements are less than or equal to mid in matrix
                       if(cnt<k) ==> then we definately says that our answer is more than mid
                       else ==> our ans is less than mid


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();

        int start=matrix[0][0];
        int end=matrix[n-1][n-1];

        while(start<=end){
            int mid=start+(end-start)/2;
            int cnt=0;

            for(int i=0;i<n;i++){
                cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }

            if(cnt<k){
                start=mid+1;
            }

            else{
                end=mid-1;
            }
        }

        return start;
    }
};
