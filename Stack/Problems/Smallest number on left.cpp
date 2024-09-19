Brute Force==> Use 2 Loops

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int>ans;
        for(int i=0;i<n;i++){
            int elm=a[i];
            
            for(int j=i;j>=0;j--){
                if(a[j]<elm){
                    elm=a[j];
                    ans.push_back(elm);
                    break;
                }
            }
            
            if(elm==a[i]){
                ans.push_back(-1);
            }
        }
        

        return ans;
    }
};

=============================================================================================================================
=============================================================================================================================

//Optimal Solution==> Use stack and iterate from start

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int>ans;
        stack<int>st;
        st.push(-1);
        
        for(int i=0;i<n;i++){
            int elm=a[i];
            
            if(elm>st.top()){
                ans.push_back(st.top());
                st.push(elm);
            }
            
            else{
                while(!st.empty() && st.top()>=elm){
                    st.pop();
                }
                
                ans.push_back(st.top());
                st.push(elm);
            }
        }
        
        return ans;
   
    }
};
