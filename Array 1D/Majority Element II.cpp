// Logic==>maximum 2 elements possible and minimum 0 elements possible

===============================================================================================================

// Brute Force Solution ==>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(ans.size()==0 || ans.back()!=nums[i]){
                int cnt=0;

                for(int j=i;j<n;j++){
                    if(nums[i]==nums[j]){
                        cnt++;
                    }
                }

                if(cnt>n/3){
                    ans.push_back(nums[i]);
                }
            }

            if(ans.size()==2){
                break;
            }
        }

        return ans;
    }
};
================================================================================================================

// Better Solution==> Use hashmap and store its cnt

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto &x:mpp){
            if(x.second>n/3){
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};

===============================================================================================================

// Optimal Solution ==> Use Moore's Voting Algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        
        int cnt1=0;
        int cnt2=0;
        int elm1;
        int elm2;

        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=elm2){
                elm1=nums[i];
                cnt1++;
            }

            else if(cnt2==0 && nums[i]!=elm1){
                elm2=nums[i];
                cnt2++;
            }

            else if(elm1==nums[i]){
                cnt1++;
            }

            else if(elm2==nums[i]){
                cnt2++;
            }

            else{
                cnt1--;
                cnt2--;
            }
        }

        int CNT1=0;
        int CNT2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==elm1){
                CNT1++;
            }

            if(nums[i]==elm2){
                CNT2++;
            }
        }

        if(CNT1>n/3){
            ans.push_back(elm1);
        }

        if(CNT2>n/3){
            ans.push_back(elm2);
        }

        return ans;
    }
};

