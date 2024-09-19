//Solution set must not Contain Duplicate Triplets thus use "SET"

==============================================================================================================

// Brute Force ==> Apply 4 loops and check their individual element sum equals to target or not

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int e1=nums[i];

            for(int j=i+1;j<n;j++){
                int e2=nums[j];

                for(int k=j+1;k<n;k++){
                    int e3=nums[k];

                    for(int l=k+1;l<n;l++){
                        int e4=nums[l];

                        long long sum = static_cast<long long>(e1) + e2 + e3 + e4;


                        if(sum==target){
                            vector<int>temp={e1,e2,e3,e4};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>>ans;
        for(auto x:st){
            ans.push_back(x);
        }

        return ans;
    }
};
==============================================================================================================

//Better Approach==> use Hashset and apply "Prfeix Sum" Logic

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int e1=nums[i];

            for(int j=i+1;j<n;j++){
                int e2=nums[j];

                set<long long>mpp;

                for(int k=j+1;k<n;k++){
                    int e3=nums[k];

                    long long e4=target-(static_cast<long long>(e1)+e2+e3);

                    if(mpp.find(e4)!=mpp.end()){
                        vector<int>temp={e1,e2,e3,(int)(e4)};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }

                    else{
                        mpp.insert(e3);
                    }
                }
            }
        }

        vector<vector<int>>ans;
        for(auto x:st){
            ans.push_back(x);
        }

        return ans;
    }
};
================================================================================================================

//Optimal Solution==> Sort array and apply 2 loops and 2 Pointer approach

#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    int n=nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }

        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            int k=j+1;
            int l=n-1;

            while(k<l){
                int sum=nums[i]+nums[j]+nums[k]+nums[l];

                if(sum<target){
                    k++;
                }

                else if(sum>target){
                    l--;
                }

                else if(sum==target){
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);

                    k++;
                    l--;

                    while(k<l && nums[k]==nums[k-1]){
                        k++;
                    }

                    while(k<l && nums[l]==nums[l+1]){
                        l--;
                    }
                }
            }
        }
    }

    return ans;
}
