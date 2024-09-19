// Brute Force==> Apply 2 loops and iterate over matrix and increase cnt. If cnt>maxi then maxi=cnt and ans=i

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int row, int col) {
	    // code here
	    int ans=-1;
	    int maxi=0;
	    for(int i=0;i<row;i++){
	        int cnt=0;
	        for(int j=0;j<col;j++){
	            if(arr[i][j]==1){
	                cnt++;
	            }
	        }
	        if(cnt>maxi){
	            maxi=cnt;
	            ans=i;
	        }
	    }
	    
	    return ans;
	    
	}

};

=======================================================================================================================

// Optimal Solution==> Since each row is sorted. So we can apply binary search on each row. Find cnt by using upper bound-lower bound

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int row, int col) {
	    // code here
	   int maxi=0;
	   int ans=-1;
	   for(int i=0;i<row;i++){
	       int cnt=0;
	       
	       int ub=upper_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
	       int lb=lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
	       
	       cnt=ub-lb;
	       if(cnt>maxi){
	           maxi=cnt;
	           ans=i;
	       }
	   }
	   
	   return ans;
	}

};
