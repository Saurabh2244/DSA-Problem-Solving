class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }

            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }

                else{
                    st.push(s[i]);
                }
            }
        }

        int openCnt=0;
        int closeCnt=0;

        while(!st.empty()){
            if(st.top()=='('){
                openCnt++;
            }

            else{
                closeCnt++;
            }

            st.pop();
        }

        return openCnt+closeCnt;
    }
};
