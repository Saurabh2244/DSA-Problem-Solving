// Brute force==> Apply 2 loops and check for each element

bool findPair(int arr[], int size, int n){
    //code
    for(int i=0;i<size;i++){
        int elm1=arr[i];
        
        for(int j=0;j<size;j++){

            if(i==j){
                continue;
            }

            int elm2=arr[j];
            
            if(elm2-elm1==n){
                return true;
            }
        }
    }
    
    return false;
    
}

===================================================================================================================

// Better Solution==>

bool findPair(int arr[], int n, int target){
    //code
    unordered_map<int,int>mpp;
    
    for(int i=0;i<n;i++){
        int curr=arr[i];
        int desi1=curr+target;
        int desi2=curr-target;
        
        if(mpp.find(desi1)!=mpp.end() || mpp.find(desi2)!=mpp.end()){
            return true;
        }
        
        mpp[curr]=i;
    }
    
    return false;
    
}
========================================================================================================================

// Optimal Solution==> Sort array and use 2 pointer approach.
                       Pointer 1==>index 0
                       Pointer 2==>index 1

bool findPair(int arr[], int n, int target){
    //code
    
    sort(arr,arr+n);
    
    int i=0;
    int j=1;
    
    while(i<n && j<n){
        if(arr[j]-arr[i]==target && i!=j){
            return true;
        }
        
        else if(arr[j]-arr[i]<target){
            j++;
        }
        
        else{
            i++;
        }
    }
    
    return false;
    
}
