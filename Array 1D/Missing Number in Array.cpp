// Approach 1==> Algebric Approach (Sum of First "N" Numbers)
class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int TotalSum=n*(n+1)/2;
        
        int actualSum=0;
        
        for(int i=0;i<array.size();i++){
            actualSum+=array[i];
        }
        
        int missingNum=TotalSum-actualSum;
        return missingNum;
    }
};

=======================================================================================================

// Approach 2==> Using Bit Manipulation (XOR Operator)
class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int XOR1=0;
        int XOR2=0;
        
        for(int i=0;i<array.size();i++){
            XOR1=XOR1^array[i];
        }
        
        for(int i=1;i<=n;i++){
            XOR2=XOR2^i;
        }
        
        return XOR1^XOR2;
    }
};
