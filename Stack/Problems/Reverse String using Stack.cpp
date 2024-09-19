#include <bits/stdc++.h> 
string reverseString(string str)
{
	// Write your code here.
	stack<char>st;

	for(int i=0;i<str.length();i++){
		st.push(str[i]);
	}

	string ans="";
	while(!st.empty()){
		ans+=st.top();
		st.pop();
	}

	return ans;
}
