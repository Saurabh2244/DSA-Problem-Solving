//Approach==> Find Maximum of Minimum

We know our search space and we can reduced it by some logic. This leads to Binary Search on Answer(Search Space)
Minimum distance between 2 cows is 1 (if we take 0 then cows will fight so 0 is not possible)
Maximum possible distance between 2 cows is Maximum element - Minimum Element

So, We reduced our search space as [1,maxi-mini]


=====================================================================================================================

//Brute Force==> Use Linear Search

bool isPossible(vector<int>&stalls,int n,int k,int mid){
    int cowCnt=1;
    int position=stalls[0];

    for(int i=0;i<n;i++){
        if(stalls[i]-position>=mid){
            cowCnt++;

            if(cowCnt==k){
                return true;
            }

            position=stalls[i];
        }
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());

    int start=1;
    int end=stalls[n-1]-stalls[0];

    int ans=-1;

    for(int i=end;i>=start;i--){
        if(isPossible(stalls,n,k,i)){
            return i;
        }

        else{
            continue;
        }
    }

    return ans;
}

=====================================================================================================================

//Optimal Solution==> Use Binary Search

class Solution {

private:
    bool isPossible(int n,int k,vector<int>&stalls,int mid){
        int cowPos=stalls[0];
        int cowCnt=1;
        
        for(int i=0;i<n;i++){
            if(stalls[i]-cowPos>=mid){
                cowCnt++;
                if(cowCnt==k){
                    return true;
                }
                
                cowPos=stalls[i];
            }
        }
        
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int maxi=*max_element(stalls.begin(),stalls.end());
        int mini=*min_element(stalls.begin(),stalls.end());
        
        int start=1;
        int end=maxi-mini;
        
        int mid=start+(end-start)/2;
        int ans=-1;
        
        while(start<=end){
            if(isPossible(n,k,stalls,mid)){
                ans=mid;
                start=mid+1;
            }
            
            else{
                end=mid-1;
            }
            
            mid=start+(end-start)/2;
        }
        
        return ans;
    }
};
