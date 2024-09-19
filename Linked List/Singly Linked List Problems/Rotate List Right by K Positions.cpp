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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || k==0){
            return head;
        }

        int length=0;

        ListNode* temp=head;

        while(temp->next!=NULL){
            length++;
            temp=temp->next;
        }
        
        length++;

        temp->next=head;

        temp=head;

        int jump=length-(k%length);

        while(jump>1){
            temp=temp->next;
            jump--;
        }

        head=temp->next;
        temp->next=NULL;

        return head;

    }
};
