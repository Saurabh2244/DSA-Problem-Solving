// Approach==> We have to check minimum number of pages should we allocate

EX: [25, 46, 28, 49, 24]

start from 1==> If we allocate 1 page then its not possible because minimum page is 24.

Thus minimum should be 24. But if we allocate 24 then no one handle book with page 25, 46,28,49

Thus, minimum ans or the number from which we start is maximum of array i.e. 49

from 49 to sum of all elements.
check one by one ====>[Linear Search]

//Brute Force==>

bool isPossible(vector<int>&arr,int n,int m,int limit){
    int stuCnt=1;
    int pageSum=0;

    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=limit){
            pageSum+=arr[i];
        }

        else{
            stuCnt++;
            if(stuCnt>m){
                return false;
            }

            else{
                pageSum=arr[i];
            }
        }
    }

    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n){
        return -1;
    }

    int start=*max_element(arr.begin(),arr.end());
    int end=accumulate(arr.begin(),arr.end(),0);

    for(int i=start;i<=end;i++){
        if(isPossible(arr,n,m,i)){
            return i;
        }

        else{
            continue;
        }
    }

    return -1;
}

====================================================================================================================================

//Approach==> We have to find Minimum of All Possible Maximums.

We are able to decide our answer range

If we allocate the maximum number of pages to each student, it would be more suitable.

If we allocate the minimum, for instance, in the given example [12, 34, 67, 70],
if we allocate the minimum, we would start with 12 for the first student, then for the second student, we have a minimum of 34, 
and we would have to allocate the entire book to that student. Therefore, the minimum possibility is the maximum element in array.

On the other hand, the maximum possibility is to allocate all pages to a single student, which represents the worst-case scenario.

====================================================================================================================================
// Optimal Solution==>
class Solution 
{
    private:
    //Function for to check possibility
    bool isPossible(int A[],int N,int M,int mid){
        int pageSum=0;
        int studentCnt=1;
        
        for(int i=0;i<N;i++){
            if(pageSum+A[i]<=mid){
                pageSum=pageSum+A[i];
            }
            
            else{
                studentCnt++;
                if(studentCnt>M || A[i]>mid){
                    return false;
                }
                
                pageSum=A[i];
            }
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //if number of students is greater than that of books
        if(M>N){
            return -1;
        }
        
        int start=*max_element(A,A+N);
        int end=0;
        for(int i=0;i<N;i++){
            end=end+A[i];
        }
        
        int mid=start+(end-start)/2;
        int ans=-1;
        
        while(start<=end){
            if(isPossible(A,N,M,mid)){
                ans=mid;
                end=mid-1;
            }
            
            else{
                start=mid+1;
            }
            
            mid=start+(end-start)/2;
        }
        
        return ans;
    }
};
