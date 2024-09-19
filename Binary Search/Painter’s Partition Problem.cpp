// Hint==> Same as Book Alloction Problem. No change but

Only remove this part;)  because==> Here not mentioned that each painter get atleast one board

if(Number of Painters > Number of Board){
       return -1;
}

=======================================================================================================================

class Solution
{
  private:
    bool isPossible(int arr[],int n,int k,long long mid){
        int painterCnt=1;
        int time=0;
        
        for(int i=0;i<n;i++){
            if(time+arr[i]<=mid){
                time=time+arr[i];
            }
            
            else{
                painterCnt++;
                if(painterCnt>k || arr[i]>mid){
                    return false;
                }
                
                else{
                    time=arr[i];
                }
            }
        }
        return true;
    }
    
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long start=*max_element(arr,arr+n);
        long long end=0;
        for(int i=0;i<n;i++){
            end=end+arr[i];
        }
        
        long long mid=start+(end-start)/2;
        long long ans=-1;
        
        while(start<=end){
            if(isPossible(arr,n,k,mid)){
                ans=mid;
                end=mid-1;
            }
            
            else{
                start=mid+1;
            }
            
            mid=start+(end-start)/2;
        }
        
        return ans;
    }
};
