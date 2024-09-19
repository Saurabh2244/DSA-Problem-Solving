// Brute Force==> Use 2 loops and check

/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* curr=head;
        
        while(curr!=NULL){
            Node* runner=curr;
            
            while(runner->next!=NULL){
                
                if(runner->next->data==curr->data){
                    Node* temp=runner->next;
                    runner->next=temp->next;
                    
                    temp->next=NULL;
                    delete temp;
                }
                
                else{
                    runner=runner->next;
                }
            }
            
            curr=curr->next;
        }
        
        return head;
    }
};

==========================================================================================================================

// Optimal Solution==> Use Set. Check curr is present in set or not. If present then remove. If not then prev=curr and curr=curr->next


/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* curr=head;
        Node* prev=NULL;
        
        unordered_set<int>st;
        
        while(curr!=NULL){
            
            if(st.find(curr->data)!=st.end()){
                
                Node* temp=curr;
                curr=temp->next;
                prev->next=curr;
                
                temp->next=NULL;
                delete temp;
            }
            else{
                st.insert(curr->data);
                prev=curr;
                curr=curr->next;
            }
        }
        
        return head; 
    }
};
