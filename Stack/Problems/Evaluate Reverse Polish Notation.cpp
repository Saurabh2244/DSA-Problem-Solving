class Solution {
public:
    unordered_set<string> operatorSet={"+","-","*","/"};
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(operatorSet.find(tokens[i])==operatorSet.end()){
                st.push(stoi(tokens[i]));
            }

            else{
                int first=st.top();
                st.pop();

                int second=st.top();
                st.pop();

                if(tokens[i]=="+"){
                    st.push(second+first);
                }

                else if(tokens[i]=="-"){
                   st.push(second-first);
                }

                else if(tokens[i]=="*"){
                    st.push(second*first);
                }

                else if(tokens[i]=="/"){
                    st.push(second/first);
                }
            }
        }

        return st.top();
    }
};
