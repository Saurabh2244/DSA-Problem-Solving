// Brute Force==> Create Linked List Delete Middle element

#include <bits/stdc++.h> 

class Node{
   public:
   int data;
   Node*next;

   Node(int data){
      this->data=data;
      this->next=NULL;
   }
};

void insertAtTail(Node* &ansHead,Node*&ansTail,int data){
   if(ansHead==NULL){
      Node*temp=new Node(data);
      ansHead=temp;
      ansTail=temp;
      return;
   }

   Node* temp=new Node(data);
   ansTail->next=temp;
   ansTail=temp;
}

Node* removeMid(Node*&head){
   if(head==NULL || head->next==NULL){
      return NULL;
   }

   Node* slow=head;
   Node*prev=NULL;
   Node*fast=head->next;

   while(fast!=NULL && fast->next!=NULL){
      prev=slow;
      slow=slow->next;
      fast=fast->next->next;
   }

   if(prev!=NULL){
      prev->next=slow->next;
      slow->next=NULL;
      delete slow;
   }

   else{
      head=slow->next;
      delete slow;
   }

   return head;
}

Node* rev(Node*&head){
   if(head==NULL || head->next==NULL){
      return head;
   }

   Node* prev=NULL;
   Node* curr=head;
   Node* temp=NULL;

   while(curr!=NULL){
      temp=curr->next;
      curr->next=prev;
      prev=curr;
      curr=temp;
   }

   return prev;
}

void deleteMiddle(stack<int>& inputStack, int N){
   Node* ansHead = NULL;
   Node* ansTail = NULL;

   // Create a linked list from the stack
   while (!inputStack.empty()) {
      int elm = inputStack.top();
      insertAtTail(ansHead, ansTail, elm);
      inputStack.pop();
   }

   // Remove the middle element
   Node* ans = removeMid(ansHead);

   // Reverse the remaining elements
   Node* Ans = rev(ans);

   // Push the reversed elements back to the stack
   Node* curr = Ans;
   while (curr != NULL) {
      inputStack.push(curr->data);
      curr = curr->next;
   }
}

=============================================================================================================================
=============================================================================================================================

// Brute Force==> Use array 

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        vector<int>store; //store all elements in array
        while(!s.empty()){
            store.push_back(s.top());
            s.pop();
        }
        
        vector<int>ans;//create new array which store all except mid
        
        int mid=store.size()/2;
        
        for(int i=0;i<store.size();i++){
            if(i==mid){
                continue;
            }
            
            ans.push_back(store[i]);
        }
        
        reverse(ans.begin(),ans.end()); //reverse array
        
        //again push in stack
        for(int i=0;i<ans.size();i++){
            s.push(ans[i]);
        }
    }
};

=============================================================================================================================
=============================================================================================================================

// Optimal Solution==> Use Recursion. Base case is==> when cnt reach size/2 then remove top and return.
                      After return add top element in stack once

#include <bits/stdc++.h> 
void solve(stack<int>&inputStack,int cnt,int N){

   //base case
   if(cnt==N/2){
      inputStack.pop();
      return;
   }

   int elm=inputStack.top();
   inputStack.pop();

   solve(inputStack,cnt+1,N);
   
   inputStack.push(elm);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int cnt=0;
   solve(inputStack,cnt,N);
}
