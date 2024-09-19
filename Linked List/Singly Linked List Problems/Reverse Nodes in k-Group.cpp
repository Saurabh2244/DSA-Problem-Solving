// Approach==> We know how to reverse. So reverse upto k then call recursion and adjust nodes connection 

==================================================================================================================================
==================================================================================================================================

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* &head){
        
        int cnt=0;
        ListNode* temp=head;

        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }

        return cnt;
    }

    ListNode* reverse(ListNode* &head,int length,int k){

        //base case
        if(length<k){
            return head;
        }

        int cnt=0;
        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr!=NULL && cnt<k){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;

            cnt++;
        }
        
        if(curr!=NULL){
            head->next=reverse(curr,length-k,k);
        }

        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int length=getLength(head);

        return reverse(head,length,k);
    }
};
