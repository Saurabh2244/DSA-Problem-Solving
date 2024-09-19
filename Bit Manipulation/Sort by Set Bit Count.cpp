// Brute Force==> First find set bit then store it in map and proceed

class Solution{
    public:
    int cntSetBit(int n){
        int cnt=0;
        while(n){
            if(n%2){
                cnt++;
            }
            
            n=n/2;
        }
        return cnt;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        map<int,vector<int>>mpp;
        
        for(int i=0;i<n;i++){
            mpp[cntSetBit(arr[i])].push_back(arr[i]);
        }
        
        int index=0;
        
        for(auto it=mpp.rbegin();it!=mpp.rend();it++){
            for(auto x:it->second){
                arr[index]=x;
                index++;
            }
        }
    }
};

============================================================================================================

// Optimal Solution==> Use in built Function

class Solution{
    public:
    
    static bool custom(int a,int b){
        return __builtin_popcount(a) > __builtin_popcount(b);
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        stable_sort(arr,arr+n,custom);
    }
};
