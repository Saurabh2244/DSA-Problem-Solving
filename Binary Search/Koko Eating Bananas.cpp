// Approach==> We have to find minimum speed. By using some lopgic we can reduce our Search Space.
               start=1              // because==> we have to finish all bananas so 0 is not possible. Thus take 1
               end=maximum element  // because==> if we take end as greater than maximum then also result is same but we 
                                                  want to reduce search space
=================================================================================================================================

class Solution {

private:
    bool isPossible(vector<int>&piles,int n,int h,int mid){
        int cntHr=0;
        for(int i=0;i<n;i++){
            cntHr+=piles[i]/mid;

            if(piles[i]%mid!=0){
                cntHr+=1;
            }

            if(cntHr>h){
                return false;
            }
        }
        
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int start=1;
        int end=*max_element(piles.begin(),piles.end());

        int ans=-1;
        int mid=start+(end-start)/2;

        while(start<=end){
            if(isPossible(piles,n,h,mid)){
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
