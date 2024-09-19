// Brute Force==> Use Two loops and check 2 numbers are equal to target or not

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int elm1=nums[i];

            for(int j=i+1;j<n;j++){
                int elm2=nums[j];

                if(elm1+elm2==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

=========================================================================================

//Better Solution==> Use HashMap (Value,Index) and check target-nums[i] is present in map or not (Prefix Sum Approach)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();

        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
            }

            else{
                mpp[nums[i]]=i;
            }
        }

        return ans;
    }
};

==========================================================================================

//Optimal Approach==> Sort array and use 2 pointer approach i.e. kept one Pointer at start and other at End 

string read(int n, vector<int> book, int target)
{
    // Write your code here.
    sort(book.begin(),book.end());

    int i=0;
    int j=n-1;

    while(i<j){
        if(book[i]+book[j]<target){
            i++;
        }

        else if(book[i]+book[j]>target){
            j--;
        }

        else if(book[i]+book[j]==target){
            return "YES";
        }
    }

    return "NO";
}
