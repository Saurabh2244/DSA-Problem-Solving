// Approach==> Reverse given linked list and use sum, digit and carry variable. carry=sum/10; digit=sum%10
               Create New linked list in which add digit

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    void insertAtTail(Node*&head, Node* &tail, int data){
        if(head==NULL){
            Node* temp=new Node(data);
            head=temp;
            tail=temp;
            return;
        }
        
        Node* temp=new Node(data);
        tail->next=temp;
        tail=temp;
    }
    
    Node* reverse(Node* &head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr!=NULL){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* head1=reverse(first);
        Node* head2=reverse(second);
        
        int carry=0;
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        
        while(head1!=NULL && head2!=NULL){
            int sum=carry+head1->data+head2->data;
            
            int digit=sum%10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            carry=sum/10;
            
            head1=head1->next;
            head2=head2->next;
        }
        
        while(head1!=NULL){
            int sum=carry+head1->data;
            
            int digit=sum%10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            carry=sum/10;
            
            head1=head1->next;
        }
        
        while(head2!=NULL){
            int sum=carry+head2->data;
            
            int digit=sum%10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            carry=sum/10;
            
            head2=head2->next;
        }
        
        while(carry!=0){
            int sum=carry;
            
            int digit=sum%10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            carry=sum/10;
        }
        
        ansHead=reverse(ansHead);
        
        return ansHead;



    }
};
=================================================================================================================================
Instead of creating 4 loops. Use 1 loop and check conditions

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    void insertAtTail(Node*&head, Node* &tail, int data){
        if(head==NULL){
            Node* temp=new Node(data);
            head=temp;
            tail=temp;
            return;
        }
        
        Node* temp=new Node(data);
        tail->next=temp;
        tail=temp;
    }
    
    Node* reverse(Node* &head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr!=NULL){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* head1=reverse(first);
        Node* head2=reverse(second);
        
        int carry=0;
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        
        while(head1!=NULL || head2!=NULL || carry!=0){
            int val1=0;
            int val2=0;
            
            if(head1!=NULL){
                val1=head1->data;
            }
            
            if(head2!=NULL){
                val2=head2->data;
            }
            
            int sum=carry+val1+val2;
            
            int digit=sum%10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            carry=sum/10;
            
            if(head1!=NULL){
                head1=head1->next;
            }
            
            if(head2!=NULL){
                head2=head2->next;
            }
            
        }
        
        ansHead=reverse(ansHead);
        
        return ansHead;
    }
};
