// Approach 1==> Use "sqrt" in-built function

class Solution {
public:
    int mySqrt(int x) {
       long long int ans=sqrt(x);
       return ans;
    }
};

=======================================================================================================

// Optimal Solution==> Our square root is always lie between 0 and given number. So we can apply Binary Search on Answer range

class Solution {
public:
    int mySqrt(int x) {
        long long int start=0;
        long long int end=x;

        long long int mid=start+(end-start)/2;

        long long int ans=-1;

        while(start<=end){
            long long int square=mid*mid;
            if(square>x){
                end=mid-1;
            }

            else if(square<x){
                ans=mid;
                start=mid+1;
            }

            else if(square==x){
                return mid;
            }

            mid=start+(end-start)/2;
        }

        return ans;
    }
};
