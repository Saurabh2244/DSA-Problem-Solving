//   Approach==> Create two extra arrays i.e. left and right and 
     min(left,right)-height[i] is capacity of store water by ith piller

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        
        vector<int>left(n);
        left[0]=height[0];

        vector<int>right(n);
        right[n-1]=height[n-1];
        
        //left maximum
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }

        //right maximum
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int a=min(left[i],right[i]); //minimum of left and right
            ans=ans+(a-height[i]);
        }

        return ans;
    }
};
