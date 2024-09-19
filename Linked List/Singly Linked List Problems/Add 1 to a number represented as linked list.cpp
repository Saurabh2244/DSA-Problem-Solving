// Same as add 2 numbers but here instead of curr2 use 1 and once it used then set val2=0

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node*rev(Node* &head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node*curr=head;
        Node*prev=NULL;
        while(curr!=NULL){
            Node*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    
    void insertAtTail(Node*&head,Node*&tail,int data){
        if(head==NULL){
            Node*node1=new Node(data);
            head=node1;
            tail=node1;
        }
        
        else{
            Node*temp=new Node(data);
            tail->next=temp;
            tail=temp;
        }
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        Node* head1=head;
        head1=rev(head1);
        
        Node*curr1=head1;
        
        Node*ansHead=NULL;
        Node*ansTail=NULL;
        
        int carry=0;
        int curr2=1;
        
        while(curr1!=NULL){
            
            int sum=curr1->data+curr2+carry;
            curr2=0;
            int digit=sum%10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            carry=sum/10;
            
            curr1=curr1->next;
        }
        
        while(carry!=0){
            int sum=carry;
            int digit=sum%10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            carry=sum/10;
        }
        
        ansHead=rev(ansHead);
        
        return ansHead;
   
    }
};

=====================================================================================================================

//Optimal Version==> Instead of using 2 seprate loops. Use just single loop

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node*rev(Node* &head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node*curr=head;
        Node*prev=NULL;
        while(curr!=NULL){
            Node*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    
    void insertAtTail(Node*&head,Node*&tail,int data){
        if(head==NULL){
            Node*node1=new Node(data);
            head=node1;
            tail=node1;
        }
        
        else{
            Node*temp=new Node(data);
            tail->next=temp;
            tail=temp;
        }
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        Node* head1=head;
        head1=rev(head1);
        
        Node*curr1=head1;
        
        Node*ansHead=NULL;
        Node*ansTail=NULL;
        
        int carry=0;
        int val2=1;
        
        while(curr1!=NULL || carry!=0){
            
            int val1=0;
            
            if(curr1!=NULL){
                val1=curr1->data;
                curr1=curr1->next;
            }
            
            int sum=val1+val2+carry;
            val2=0;
            
            int digit=sum%10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            carry=sum/10;
        }
        
        ansHead=rev(ansHead);
        return ansHead;
    }
};
