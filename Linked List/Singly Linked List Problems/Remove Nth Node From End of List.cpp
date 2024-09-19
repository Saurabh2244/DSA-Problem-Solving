// Brute force==> nth node from end means length-n+1 th node from begining. So find length is necessary

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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || (head->next==NULL && n==1) ){
            return NULL;
        }
        
        int length=getLength(head);
        int target=length-n;

        if(target==0){
            return head->next;
        }

        if(target<0){
            return head;
        }

        int cnt=0;
        ListNode* curr=head;
        while(cnt<target-1){
            cnt++;
            curr=curr->next;
        }

        ListNode* temp=curr->next;
        curr->next=temp->next;
        temp->next=NULL;
        delete temp;

        return head;
    }
};

=============================================================================================================================================================================
=============================================================================================================================================================================

// Optimal Solution==> Just optimised above approach. We not need to find length. We find length-n from beginng. If we set one pointer at n+1 then 
                       when this pointer at end then another pointer at length-n position.
                        So, just solve by using 2 pointer approach

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }

        if(fast==NULL){
            return head->next;
        }

        ListNode* slow=head;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* temp=slow->next;
        slow->next=temp->next;

        temp->next=NULL;
        delete temp;

        return head;
    }
};
