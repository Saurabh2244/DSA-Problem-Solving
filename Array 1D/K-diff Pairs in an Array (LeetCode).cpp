// Brute Force==> Use 2 loops and check for each

class Solution {
public:
    int findPairs(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>st;
        
        for(int i=0;i<n;i++){
            int elm1=nums[i];

            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }

                int elm2=nums[j];
                if(elm2-elm1==target){
                    st.insert({elm1,elm2});
                }
            }
        }

        return st.size();
    }
};

=========================================================================================================================

// Better Approach==> use map to reduce time complexity to O(n)

class Solution {
public:
    int findPairs(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>st;
        
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int desi1=curr+target;
            int desi2=curr-target;

            if(mpp.find(desi1)!=mpp.end()){
                vector<int>temp={desi1,curr};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }

            if(mpp.find(desi2)!=mpp.end()){
                vector<int>temp={desi2,curr};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }

            mpp[curr]=i;
        }

        return st.size();
    }
};

=====================================================================================================================

// Optimal Solution==> Sort array and use 2 pointer approach
                       Avoid duplicates by if we get correct then check for next and prev elm are same or not
                       if yes then i++ type.

class Solution {
public:
    int findPairs(vector<int>& nums, int target) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        
        int i=0;
        int j=1;

        int cnt=0;

        while(i<n && j<n){
            if(nums[j]-nums[i]==target && i!=j){
                cnt++;
                i++;
                j++;

                while(i<n && nums[i]==nums[i-1]){
                    i++;
                }

                while(j<n && nums[j]==nums[j-1]){
                    j++;
                }
            }

            else if(nums[j]-nums[i]<target){
                j++;
            }

            else{
                i++;
            }
        }

        return cnt;
        
    }
};
