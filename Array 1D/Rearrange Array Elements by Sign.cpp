// Approach==> Create Positive and negative array and then place alternatively

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    
        vector<int> positive;
        vector<int> negative;
 
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<0){
               negative.push_back(nums[i]);
            }   

            else if(nums[i]>0){
                positive.push_back(nums[i]);
            }
        }

        int n1=positive.size();
        int n2=negative.size();
        int i=0;
        int j=0;
        int k=0;
        vector<int>ans(n);
   
        while(k<n){
            if(i<n1){
               ans[k++]=positive[i++];
            }

            if(j<n2){
                ans[k++]=negative[j++];
            }
        }

        return ans;
    
    }
};
