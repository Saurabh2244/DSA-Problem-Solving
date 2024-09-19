class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<int>temp=nums;
	    sort(temp.begin(),temp.end());
	    
	    unordered_map<int,int>mpp;
	    for(int i=0;i<n;i++){
	        mpp[nums[i]]=i;
	    }
	    
	    int cnt=0;
	    
	    for(int i=0;i<n;i++){
	        if(nums[i]!=temp[i]){
	            cnt++;
	            int x=nums[i];
	            swap(nums[i],nums[mpp[temp[i]]]);
	            
	            mpp[x]=mpp[temp[i]];
	            mpp[temp[i]]=i;
	        }
	    }
	    
	    return cnt;
	}
};
