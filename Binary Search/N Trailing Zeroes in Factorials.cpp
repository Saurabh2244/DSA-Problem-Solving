// We have to find how many numbers having trailing zeroes n.

int start=0;
int end=INT_MAX;

first we check trailing zeroes of mid. If trail 0 of mid==n then return 5;
                                       If trail 0 of mid > n then end=mid-1; else start=mid+1;

============================================================================================================================

class Solution {
public:
    
    int trailZero(int n){
        int cnt=0;
        while(n>0){
            cnt+=n/5;
            n=n/5;
        }
        return cnt;
    }
    
    int countZeroes(int n){
        // Code here
        int start=0;
        int end=INT_MAX;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            int x=trailZero(mid);
            
            if(x==n){
                return 5;
            }
            
            else if(x>n){
                end=mid-1;
            }
            
            else{
                start=mid+1;
            }
        }
        
        return 0;
    }
};
