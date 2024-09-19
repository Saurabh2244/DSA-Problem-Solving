// Same as merge sort for array. Just split linked list into 2 parts by using mid. After that use recursion

/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution{
  public:
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
    
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next; 
        }
       
       return slow;
    }
    
    Node* solve(Node* &head1, Node*&head2){
        
        Node* curr1=head1;
        Node* next1=curr1->next;
        
        Node* curr2=head2;
        
        while(next1!=NULL && curr2!=NULL){
            
            if(curr1->data <= curr2->data && curr2->data <=next1->data){
                
                Node* next2=curr2->next;
                curr1->next=curr2;
                curr2->next=next1;
                
                curr1=curr2;
                curr2=next2;
            }
            
            else{
                curr1=next1;
                next1=next1->next;
            }
        }
        
        while(curr2!=NULL){
            curr1->next=curr2;
            return head1;
        }
        
        return head1;
    }
    
    Node* merge2LL(Node* &head1, Node* &head2){
        
        if(head1==NULL){
            return head2;
        }
        
        if(head2==NULL){
            return head1;
        }
        
        if(head1->data > head2->data){
            return merge2LL(head2,head1);
        }
        
        return solve(head1,head2);
    }
    
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node*mid=getMid(head);
        
        Node* left=head;
        Node* right=mid->next;
        
        mid->next=NULL;
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        Node *ans=merge2LL(left,right);
        
        return ans;
    }
};
