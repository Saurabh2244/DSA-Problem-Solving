// Brute Force==>For each number between 1 to N, we will try to count the occurrence in the given array using 
inear search. And the element with occurrence as 2 will be the repeating number and the number with 0 
occurrences will be the missing number.

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repeating=-1;
        int missing=-1;
        
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(arr[j]==i){
                    cnt++;
                }
            }
            
            if(cnt==2){
                repeating=i;
            }
            
            else if(cnt==0){
                missing=i;
            }
            
            if(repeating!=-1 && missing!=-1){
                break;
            }
        }
        
        return {repeating,missing};
    }
};

=================================================================================================

//Optimal Solution==> Use Math's (x-y and x^2-y^2) equations and find x and y

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        long long SN=(n * 1LL * (n + 1)) / 2; 
        long long SN2=(n * 1LL * (n + 1) * 1LL * ((2 * n) + 1)) / 6;
        
        long long Selm=0;
        long long S2elm=0;
        
        for(int i=0;i<n;i++){
            Selm=Selm+arr[i];
            S2elm+=(long long)arr[i]*(long long)arr[i];
        }
        
        long long val1=Selm-SN;
        long long val2=S2elm-SN2;
        
        val2=val2/val1;
        
        long long x=(val1+val2)/2;
        long long y=(x-val1);
        
        return {(int)x,(int)y};
    }
};
