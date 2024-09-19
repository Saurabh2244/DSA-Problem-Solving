//Logic==> maximum 1 element is possible or minimum 0 element is possible

===================================================================================================

// Brute Force==> use HashMap and store cnt

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto &x:mpp){
            if(x.second>n/2){
                return x.first;
            }
        }

        return -1;
    }
};

===================================================================================================

//Optimal Solution==> Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        
        int cnt=0;
        int elm;

        for(int i=0;i<n;i++){
            if(cnt==0){
                elm=nums[i];
                cnt++;
            }

            else if(nums[i]==elm){
                cnt++;
            }

            else if(nums[i]!=elm){
                cnt--;
            }
        }

        //check our find element is really exist n/2 times or not
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==elm){
                cnt1++;
            }
        }

        if(cnt1>n/2){
            return elm;
        }

        else{
            return -1;
        }
    }
};
