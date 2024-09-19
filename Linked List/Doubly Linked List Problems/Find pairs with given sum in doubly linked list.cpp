// Problem is exactly Same as 2 Sum

============================================================================================================================
============================================================================================================================

// Brute Force==> Use 2 loops and check

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int,int>>ans;

    Node*curr=head;
    while(curr!=NULL){
        Node* runner=curr->next;

        while(runner!=NULL){
            if(curr->data + runner->data==k){
                pair<int,int>p={curr->data,runner->data};
                ans.push_back(p);
            }
            runner=runner->next;
        }
        curr=curr->next;
    }

    return ans;

}
============================================================================================================================
=============================================================================================================================

// Better solution ==>Use map and just use 1 loop and use concept of remain

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
#include<bits/stdc++.h>

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int,int>>ans;
    
    unordered_map<int,int>mpp;
    Node*curr=head;
    int index=0;
    while(curr!=NULL){
        int elm1=curr->data;
        int remain=k-elm1;

        if(mpp.find(remain)!=mpp.end()){
            pair<int,int>p={remain,elm1};
            ans.push_back(p);
        }

        mpp[curr->data]=index;
        index++;
        curr=curr->next;
    }

    return ans;
}

============================================================================================================================
============================================================================================================================

// Optimal SOLUTION==> Use 2 Pointer one at left end and other at right end.
                       If sum>target then right--;
                       If sum<target then left++
                       If sum==target then push in ans and left++ and right--

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
#include<bits/stdc++.h>

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int,int>>ans;

    Node* left=head;
    Node* right=head;

    while(right->next!=NULL){
        right=right->next;
    }

    while(left!=right && right->next!=left){
        int first=left->data;
        int second=right->data;

        if(first+second > k){
            right=right->prev;
        }

        else if(first+second <k){
            left=left->next;
        }

        else if(first+second==k){
            pair<int,int>p={first,second};
            ans.push_back(p);

            left=left->next;
            right=right->prev;
        }
    }

    return ans;
    
}
