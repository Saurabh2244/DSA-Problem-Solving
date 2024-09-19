// Approach 1==> Use inBuilt sort function

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        sort(a,a+n);
    }
    
};

=======================================================================================================

// Approach 2==> Use Counting Method

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int zeroCnt=0;
        int oneCnt=0;
        int twoCnt=0;
        
        for(int i=0;i<n;i++){
            if(a[i]==0){
                zeroCnt++;
            }
            
            else if(a[i]==1){
                oneCnt++;
            }
            
            else if(a[i]==2){
                twoCnt++;
            }
        }
        
        for(int i=0;i<zeroCnt;i++){
            a[i]=0;
        }
        
        for(int i=zeroCnt;i<zeroCnt+oneCnt;i++){
            a[i]=1;
        }
        
        for(int i=zeroCnt+oneCnt;i<n;i++){
            a[i]=2;
        }
    }
};
========================================================================================================

//Approach 3==> Dutch National Flag Algorithm

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int low=0;
        int mid=0;
        int high=n-1;
        
        while(mid<=high){
            if(a[mid]==0){
                swap(a[mid],a[low]);
                low++;
                mid++;
            }
            
            else if(a[mid]==1){
                mid++;
            }
            
            else if(a[mid]==2){
                swap(a[mid],a[high]);
                high--;
            }
        }
    }
};
