// Brute Force==> Use 2 loops and check for each

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int cnt=0;
        
        for(int i=0;i<n;i++){
            int elm1=arr[i];
            
            for(int j=i+1;j<n;j++){
                int elm2=arr[j];
                
                if(elm1+elm2==k){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};

==============================================================================================================================

// Better Solution==> Use Hashmap and Prefix Sum Concept

No Better Solution exists
===========================================================================================================================

// Optimal Solution==> Use Prefix Sum Approach and create map of [element,cnt]

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int cnt=0;
        
        unordered_map<int,int>mpp; //map of [elm,cnt]
        
        for(int i=0;i<n;i++){
            int remain=k-arr[i];
            if(mpp.find(remain)!=mpp.end()){
                cnt=cnt+mpp[remain];
            }
            
            mpp[arr[i]]++;
        }
        
        return cnt;
    }
};

============================================================================================================================

