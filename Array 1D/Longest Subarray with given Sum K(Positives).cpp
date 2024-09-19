// Brute Force==> Use 2 loops and check for each subarray

#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int maxLen=INT_MIN;

    for(int i=0;i<n;i++){
        long long sum=0;
        int cnt=0;

        for(int j=i;j<n;j++){
            sum=sum+a[j];
            cnt++;

            if(sum==k){
                maxLen=max(maxLen,cnt);
            }
        }
    }

    return maxLen;
}

=====================================================================================================

//Better Solution==> Use prefix sum concept and create map of [sum,index]

#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    unordered_map<long long,int>mpp;
    
    int maxLen=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum=sum+a[i];
        if(sum==k){
            maxLen=i+1;
        }

        long long remain=sum-k;
        if(mpp.find(remain)!=mpp.end()){
            maxLen=max(maxLen,i-mpp[remain]);
        }

        if(mpp.find(sum)==mpp.end()){
            mpp[sum]=i;
        }
    }

    return maxLen;
}

=======================================================================================================

// Optimal Solution==>Since all elements are 0 or positive thus sum is strictly increasing. Thus we can use 2 pointer
                      approach i.e. left and right pointer.
                      There are 3 possibilitie==> 1)Sum>k ==>take left pointer forward and set sum as sum-a[left]
                                                  2)Sum==k ==>maxLen=max(maxLen,right-left+1)
                                                  3)Sum<k ==>sum=sum+a[right];
                                                             right++;


#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int left=0;
    int right=0;
    
    long long sum=a[0];
    int maxLen=0;
    while(right<n){
        while(left<=right && sum>k){
            sum=sum-a[left];
            left++;
        }

        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }

        right++;
        if(right<n){
            sum=sum+a[right];
        }
    }
    return maxLen;
}
