// Brute Force==> Use array to store stack elements and sort them and again push in stack

#include <bits/stdc++.h> 
stack<int> sortStack(stack<int> &s)
{
	// Write code here.
	vector<int>ans;
    while(!s.empty()){
       ans.push_back(s.top());
       s.pop();
    }
   
    sort(ans.begin(),ans.end());
   
    for(int i=0;i<ans.size();i++){
       s.push(ans[i]);
    }

	return s;
}

===============================================================================================================================
===============================================================================================================================

// Optimal Solution==> Use Recursion

#include <bits/stdc++.h> 

void insertAtCorrectPlace(stack<int>&st,int elm){
	//base case
	if(st.empty() || (!st.empty() && st.top()<=elm)){
		st.push(elm);
		return;
	}

	int top=st.top();
	st.pop();

	insertAtCorrectPlace(st, elm);
	st.push(top);
}

void solve(stack<int>&s){
	if(s.empty()){
		return;
	}

	int elm=s.top();
	s.pop();

	solve(s);

	insertAtCorrectPlace(s,elm);
}
stack<int> sortStack(stack<int> &s)
{
	// Write code here.
	solve(s);
	return s;
}
