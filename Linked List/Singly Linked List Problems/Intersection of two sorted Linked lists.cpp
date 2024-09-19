// Approach==> Just use 2 Pointer Approach

/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    
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
    
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        if(head1==NULL || head2==NULL){
            return NULL;
        }
        
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        
        Node* curr1=head1;
        Node* curr2=head2;
        
        while(curr1!=NULL && curr2!=NULL){
            
            if(curr1->data==curr2->data){
                
                insertAtTail(ansHead,ansTail,curr1->data);
                
                curr1=curr1->next;
                curr2=curr2->next;
            }
            
            else if(curr1->data < curr2->data){
                curr1=curr1->next;
            }
            
            else{
                curr2=curr2->next;
            }
        }
        
        return ansHead;
    }
};
