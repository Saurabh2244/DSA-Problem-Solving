// Brute Force==> Store linked list into vector. and Now problem become same as given vector is Palindrome or not


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<bits/stdc++.h>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    bool isPali(vector<int>&arr){
        int i=0;
        int j=arr.size()-1;
        
        while(i<=j){
            if(arr[i]!=arr[j]){
                return false;
            }
            
            else{
                i++;
                j--;
            }
        }
        
        return true;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL || head->next==NULL){
            return true;
        }
        
        vector<int>arr;
        
        Node* temp=head;
        
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        
        return isPali(arr);
    }
};

==========================================================================================================================

// Optimal Solution==> Find mid then reverse linked list from mid->next and compare before mid and after mid part


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    
    Node *reverse(Node *&head){
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node *curr=head;
        Node *prev=NULL;
        
        while(curr!=NULL){
            Node *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    
    Node *getMid(Node*&head){
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node *slow=head;
        Node *fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL || head->next==NULL){
            return true;
        }
        
        Node*mid=getMid(head);
        
        Node *temp1=mid;
        Node* temp2=mid->next;
        
        temp2=reverse(temp2);
        
        Node *runner=head;
        while(temp2!=NULL){
            if(temp2->data != runner->data){
                return false;
            }
            
            else{
                runner=runner->next;
                temp2=temp2->next;
            }
        }
        
        //again make it as given
        temp2=temp1->next;
        temp2=reverse(temp2);
        
        return true;
    }
};

