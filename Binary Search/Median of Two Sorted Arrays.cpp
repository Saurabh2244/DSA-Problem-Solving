// Very Important and Conceptual Problem

=========================================================================================================

// Brute Force==> Given 2 sorted arrays. So make 3rd array and merge given 2 arrays and sort 3rd array
                  Then find median of 3rd array

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums2.size();

        vector<int>nums3;
        for(int i=0;i<n1;i++){
            nums3.push_back(nums1[i]);
        }

        for(int i=0;i<n2;i++){
            nums3.push_back(nums2[i]);
        }

        sort(nums3.begin(),nums3.end());

        int n3=nums3.size();

        if(n3%2!=0){
            return nums3[n3/2];
        }

        else{
            int first=nums3[n3/2];
            int second=nums3[(n3/2)-1];

            double ans=(first+second)/2.0;
            return ans;
        }
    }
};

======================================================================================================

// Optimal Solution==> We use Partition Concept. In left half of partition there are some elements which are comes from
                       array 1 and remaining are from array2. Similarly happens for right half.
                       So, basically we find that how many elements are in left from array1 and remaining are from array2.

                       You can get idea from comments of code...

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(); //size of nums1
        int n2=nums2.size(); //size of nums2
        
        //always apply binary search on smaller size array
        //because it require less Time Complexity
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        //Total elements on left side of partition(symmetry)
        int Total_elements_on_left=(n1+n2+1)/2;

        //Total elements in both arrays
        int total_elements=n1+n2;
        
        //binary search procedure on small size array
        int start=0; //take 0 elements from small array
        int end=n1;  //maximum case you can take all elements from small array
        
        while(start<=end){
            int mid1=start+(end-start)/2; //find mid1

            //logically, total mid2=total elements on left-elements taken from array 1
            int mid2=Total_elements_on_left-mid1;  

            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            
            //handling edge cases
            if(mid1<n1){
                r1=nums1[mid1];
            }

            if(mid2<n2){
                r2=nums2[mid2];
            }

            if(mid1-1>=0){
                l1=nums1[mid1-1];
            }

            if(mid2-1>=0){
                l2=nums2[mid2-1];
            }
             
            //possibility of getting correct symmetry
            if(l1<=r2 && l2<=r1){
                //check for odd number of elements
                if(total_elements%2!=0){
                    return max(l1,l2);
                }

                //check for even number of elements
                else{
                    return ( (double) ( max(l1,l2) + min(r1,r2) ) ) / 2.0;
                }
            }

            //reduce end
            else if(l1>r2){
                end=mid1-1;
            }

            //increase start
            else if(l2>r1){
                start=mid1+1;
            }
        }

        return 0;
    }
};
