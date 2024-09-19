//Brute Force==> Store Elements in array

class Solution{
public:
    void Reverse(stack<int> &st){
        vector<int>ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        for(int i=0;i<ans.size();i++){
            st.push(ans[i]);
        }
    }
};

================================================================================================================================
================================================================================================================================

//Optimal Solution==> Use recursion. Use insert at bottom concept

class Solution{
public:
    
    void insertAtBottom(stack<int>&st,int elm){
        if(st.empty()){
            st.push(elm);
            return;
        }
        
        int temp=st.top();
        st.pop();
        
        insertAtBottom(st,elm);
        st.push(temp);
    }
    
    void solve(stack<int>&st){
        if(st.empty()){
            return;
        }
        
        int elm=st.top();
        st.pop();
        solve(st);
        insertAtBottom(st,elm);
    }
    
    void Reverse(stack<int> &St){
        solve(St);
    }
};
