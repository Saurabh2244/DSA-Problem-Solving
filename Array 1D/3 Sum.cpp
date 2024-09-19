//Solution set must not Contain Duplicate Triplets thus use "SET"

// Brute Force ==> Apply 3 loops and check their individual element sum equals to target or not

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int elm1=nums[i];
            
            for(int j=i+1;j<n;j++){
                int elm2=nums[j];

                for(int k=j+1;k<n;k++){
                    int  elm3=nums[k];

                    if(elm1+elm2+elm3==0){
                        vector<int>temp={elm1,elm2,elm3};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }

                }
            }
        }

        vector<vector<int>>ans;
        for(auto &x:st){
            ans.push_back(x);
        }

        return ans;
    }
};

==============================================================================================================

//Better Approach==> use Hashset and apply "Prfeix Sum" Logic

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        
        set<vector<int>>st;

        for(int i=0;i<n;i++){
            int elm1=nums[i];
            set<int>hashSet;

            for(int j=i+1;j<n;j++){
                int elm2=nums[j];

                int remain=target-(elm1+elm2);
                if(hashSet.find(remain)!=hashSet.end()){
                    vector<int>temp={elm1,elm2,remain};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }

                hashSet.insert(elm2);
            }
        }

        vector<vector<int>>ans;
        for(auto &x:st){
            ans.push_back(x);
        }

        return ans;
    }
};

================================================================================================================

//Optimal Solution==> Sort array and apply one loop and 2 Pointer approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];

                if(sum<0){
                    j++;
                }

                else if(sum>0){
                    k--;
                }

                else if(sum==0){
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }

                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }

        return ans;

    }
};
