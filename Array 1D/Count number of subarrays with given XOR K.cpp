// Brute Force==> Use 2 loops and check for each subarray

#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n=a.size();
    int cnt=0;

    for(int i=0;i<n;i++){
        int XOR=0;

        for(int j=i;j<n;j++){
            XOR=XOR^a[j];
            if(XOR==b){
                cnt++;
            }
        }
    }

    return cnt;
}

================================================================================================

// Optimal Solution==> Use Prefix Sum Concept and create map of [XOR,cnt] and initilised with [0,1]

#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n=a.size();

    unordered_map<int,int>mpp;
    mpp[0]=1;
    
    int XOR=0;
    int cnt=0;
    
    for(int i=0;i<n;i++){
        XOR=XOR^a[i];
        int remain=XOR^b;

        if(mpp.find(remain)!=mpp.end()){
            cnt=cnt+mpp[remain];
        }

        mpp[XOR]++;
    }

    return cnt;
}
