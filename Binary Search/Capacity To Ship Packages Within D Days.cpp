// Approach==> Same as Allocate Book Pages Problem

===============================================================================================================

class Solution {
public:
    bool isPossible(vector<int>&weights,int days,int n,int mid){
        int cnt=0;
        int dayCnt=1;
        for(int i=0;i<n;i++){
            if(cnt+weights[i]<=mid){
                cnt+=weights[i];
            }

            else{
                dayCnt++;
                if(dayCnt>days || weights[i]>mid){
                    return false;
                }

                else{
                    cnt=weights[i];
                }
            }
        }

        return true;

    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int start=*max_element(weights.begin(),weights.end());
        int end=0;
        for(int i=0;i<n;i++){
            end=end+weights[i];
        }

        int ans=-1;
        int mid=start+(end-start)/2;

        while(start<=end){
            if(isPossible(weights,days,n,mid)){
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
