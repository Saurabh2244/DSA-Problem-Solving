// Brute Force==> Apply 2 loops and check linearly with variable bool flag

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            bool flag=true;
            
            for(int j=i+1;j<n;j++){
                if(a[j]>a[i]){
                    flag=false;
                }
            }
            
            if(flag==true){
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};

=============================================================================================================

// Optimal Approach==> Use only 1 loop and start from back side (reverse side)

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int>ans;
        
        int maxi=a[n-1];
        ans.push_back(a[n-1]);
        
        for(int i=n-1;i>0;i--){
            if(a[i-1]>=maxi){
                ans.push_back(a[i-1]);
                maxi=max(maxi,a[i-1]);
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
