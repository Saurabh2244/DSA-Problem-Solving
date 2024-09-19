//GFG Solution

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi=max(maxi,arr[i]);
            }
        }
        
        return maxi;
    }
};
