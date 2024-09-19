// Brute Force==>Find length then traverse linked list

/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    
    int getLength(Node *&head){
        int cnt=0;
        
        Node *temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        return cnt;
    }
    
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        if(head==NULL){
            return -1;
        }
        
        int length=getLength(head);
        int mid=(length/2)+1;
        
        int cnt=0;
        Node *temp=head;
        while(cnt!=mid-1){
            cnt++;
            temp=temp->next;
        }
        
        return temp->data;
    }
};


==============================================================================================================================
//Optimal Solution==> Slow Fast Approach

/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        if(head==NULL || head->next==NULL){
            return head->data;
        }
        
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow->data;
    }
};
