// Brute Force==> Find length and then originalPosition=length-posi. So find originalPosition from start

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    
    int getLength(Node *&head){
        int cnt=0;
        
        Node*curr=head;
        
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }
        
        return cnt;
    }
    
    int getNthFromLast(Node *head, int n)
    {
        // Your code here
        if(head->next==NULL && n==1){
            return head->data;
        }
        
        if(head->next==NULL && n!=1){
            return -1;
        }
        
        int length=getLength(head);
        
        if(n>length){
            return -1;
        }
        
        if(length==n){
            return head->data;
        }
        
        int jump=length-n;
        
        Node* temp=head;
        
        while(jump>1){
            temp=temp->next;
            jump--;
        }
        
        return temp->next->data;
    }
};

=========================================================================================================================
