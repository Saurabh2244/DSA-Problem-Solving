// Brute Force==> Store only invalid set in stack then calculate openCnt and closeCnt

int countRev (string s)
{
    // your code here
    if(s.length()%2!=0){
        return -1;
    }
    
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }
        
        else{
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            
            else{
                st.push(s[i]);
            }
        }
    }
    
    //Now stack contain only invalid set
    
    int open=0;
    int close=0;
    
    while(!st.empty()){
        if(st.top()=='{'){
            open++;
        }
        
        else{
            close++;
        }
        
        st.pop();
    }
    
    return (open+1)/2 + (close+1)/2;
    
}

===============================================================================================================================
===============================================================================================================================
// Optimal Solution==> open++
                      if close then (if open>0 then open--) (if(open==0 then close++)
int countRev (string s)
{
    // your code here
    if(s.length()%2!=0){
        return -1;
    }
 
    int open=0;
    int close=0;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='{'){
            open++;
        }
        
        else{
            if(open>0){
                open--;
            }
            else{
                close++;
            }
        }
    }

    return (open+1)/2 + (close+1)/2;
    
}
