// We have given n (i.e. trailing zeroes) and find smallest number that contain n trailing zeroes

============================================================================================================================

// Binary Search Approach==> We know that our answer is surely lie in [0 to 5*n] which is our search spcae
                             search space is sorted. Thus, we can apply binary search on search space

class Solution
{
    public:
        //check our mid contain more or less trailing zeroes 
        bool isPossible(int n,int mid){
            int cnt=0;
            
            while(mid>0){
                cnt=cnt+mid/5;
                
                mid=mid/5;
            }
            
            // if more or equal trailing zero then our ans=mid and eliminate right half
            if(cnt>=n){
                return true;
            }
            
            //eliminate left half
            else{
                return false;
            }
        }
        
        int findNum(int n)
        {
            //complete the function here
            int start=0;
            int end=5*n;
            int ans=-1;
            
            while(start<=end){
                int mid=start+(end-start)/2;
                
                // if more or equal trailing zero then our ans=mid and eliminate right half
                if(isPossible(n,mid)){
                    ans=mid;
                    end=mid-1;
                }
                
                //eliminate left half
                else{
                    start=mid+1;
                }
            }
            
            return ans;
        }
};
