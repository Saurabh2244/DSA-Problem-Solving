// Brute Force==> Create 2 linked list even and odd. Iterate over given LL and check element is odd or even and according to that add in even odd LL

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
class Solution{
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
    
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* evenHead=NULL;
        Node* evenTail=NULL;
        
        Node* oddHead=NULL;
        Node* oddTail=NULL;
        
        Node* curr=head;
        while(curr!=NULL){
            
            if(curr->data%2==0){
                insertAtTail(evenHead,evenTail,curr->data);
            }
            
            else{
                insertAtTail(oddHead,oddTail,curr->data);
            }
            
            curr=curr->next;
        }
        
        if(evenHead!=NULL){
            evenTail->next=oddHead;
            return evenHead;
        }
        
        return oddHead;

    }
};

==========================================================================================================================

// Optimal Solution==> SAME AS BRUTE FORCE BUT DON'T CREATE SEPRATE LL. Just Adjust Pointers.

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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* evenHead=NULL;
        Node* evenTail=NULL;
        
        Node* oddHead=NULL;
        Node* oddTail=NULL;
        
        Node* curr=head;
        
        while(curr!=NULL){
            
            if(curr->data %2==0){
                
                if(evenHead==NULL){
                    evenHead=curr;
                    evenTail=curr;
                }
                
                else{
                    evenTail->next=curr;
                    evenTail=evenTail->next;
                }
                
            }
            
            else{
                
                if(oddHead==NULL){
                    oddHead=curr;
                    oddTail=curr;
                }
                
                else{
                    oddTail->next=curr;
                    oddTail=oddTail->next;
                }
            }
            
            curr=curr->next;
        }
        
        if(evenHead!=NULL){
            evenTail->next=oddHead;
            
            if(oddTail!=NULL){
                oddTail->next=NULL;
            }
            
            return evenHead;
        }
        
        return oddHead;
    }
};
