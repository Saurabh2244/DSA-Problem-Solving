// Brute Force==>Create third array merge two arrays in third array and sort and then make correct arrangement

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            vector<long long>arr3;
            
            for(int i=0;i<n;i++){
                arr3.push_back(arr1[i]);
            }
            
            for(int j=0;j<m;j++){
                arr3.push_back(arr2[j]);
            }
            
            sort(arr3.begin(),arr3.end());
            
            for(int i=0;i<n;i++){
                arr1[i]=arr3[i];
            }
            
            for(int i=n;i<n+m;i++){
                arr2[i-n]=arr3[i];
            }
        } 
};

===========================================================================================================

//Optimal Solution==> 2 Pointer Approach

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i=n-1;
            int j=0;
            
            while(i>=0 && j<m){
                if(arr1[i]>arr2[j]){
                    swap(arr1[i],arr2[j]);
                    i--;
                    j++;
                }
                
                else{
                    break;
                }
            }
            
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};
