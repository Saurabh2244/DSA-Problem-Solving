// Floor==> The floor of x is the largest element in the array which is smaller than or equal to x( i.e. largest element in the array <= x)

// Ceil==> The ceiling of x is the smallest element in the array greater than or equal to x( i.e. smallest element in the array >= x).
           In short, Ceil is Lower Bound

=================================================================================================================================================================

int floor(vector<int>&a,int n,int x){
	int start=0;
	int end=n-1;

	int ans=-1;

	int mid=start+(end-start)/2;

	while(start<=end){
		if(a[mid]<=x){
			ans=a[mid];
			start=mid+1;
		}

		else{
			end=mid-1;
		}

		mid=start+(end-start)/2;
	}

	return ans;
}

int ceil(vector<int>&a,int n,int x){
	int lb=lower_bound(a.begin(),a.end(),x)-a.begin();
    
	if(lb==n){
		return -1;
	}
	return a[lb];
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.

	pair<int,int>ans;
	ans.first=floor(a, n, x);
	ans.second=ceil(a,n,x);

	return ans;
}
