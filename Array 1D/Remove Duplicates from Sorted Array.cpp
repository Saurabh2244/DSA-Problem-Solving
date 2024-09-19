class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();

        int i=0;

        for(int j=1;j<n;j++){
            if(nums[j]==nums[i]){
                continue;
            }

            else{
                nums[i+1]=nums[j];
                i=i+1;
            }
        }

        return i+1;
    }
};
