// Approach==> Use Stack

bool isValid(char a,char b){
    if(a=='(' && b==')'){
        return true;
    }
    
    else if(a=='{' && b=='}'){
        return true;
    }
    
    else if(a=='[' && b==']'){
        return true;
    }
    
    else{
        return false;
    }
}

bool valid(string s){
    // code here
    string str=s;
    stack<char>st;
    
    for(int i=0;i<str.length();i++){
       
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
           st.push(str[i]);
        }
        
        else{
            if(st.empty() || (!st.empty() && !isValid(st.top(),str[i]))){
                return false;
            }
            
            else{
                st.pop();
            }
        }
    }
    
    if(st.empty()){
        return true;
    }
    
    return false;
}
