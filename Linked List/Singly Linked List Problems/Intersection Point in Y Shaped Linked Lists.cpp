// Brute Force==>Use set which store address of all nodes of list1. Then, traverse through list 2 and just check 2 ka address is present in set or not

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* curr1=headA;
        ListNode* curr2=headB;

        unordered_set<ListNode*>st;

        while(curr1!=NULL){
            st.insert(curr1);
            curr1=curr1->next;
        }

        while(curr2!=NULL){
            if(st.find(curr2)!=st.end()){
                return curr2;
            }

            curr2=curr2->next;
        }

        return NULL;
    }
};


=============================================================================================================================================================================
=============================================================================================================================================================================

// Optimal Solution==>Count length of both LL.Make difference as 0 because they start from samr level and check nod1==node2 or not

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *&head){
        int cnt=0;
        ListNode* curr=head;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }

        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int length1=getLength(headA);
        int length2=getLength(headB);

        if(length2>length1){
            return getIntersectionNode(headB,headA);
        }

        int diff=length1-length2;

        ListNode* curr1=headA;
        ListNode* curr2=headB;

        while(diff>0){
            curr1=curr1->next;
            diff--;
        }

        while(curr1!=NULL && curr2!=NULL){
            
            if(curr1==curr2){
                return curr1;
            }

            else{
                curr1=curr1->next;
                curr2=curr2->next;
            }
        }

        return NULL;
        
    }
};
