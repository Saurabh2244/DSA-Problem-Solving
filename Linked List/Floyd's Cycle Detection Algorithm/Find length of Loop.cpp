// Brute Force==> Use map to store Node is visited or not

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    if(head==NULL || head->next==NULL){
        return 0;
    }
    
    unordered_map<Node*,int>mpp;
    
    Node*temp=head;
    while(temp!=NULL){
        
        if(mpp.find(temp)!=mpp.end()){
            int cnt=1;
            Node*curr=temp->next;
            
            while(curr!=temp){
                cnt++;
                curr=curr->next;
            }
            
            return cnt;
        }
        
        mpp[temp]=0;
        
        temp=temp->next;
    }
    
    return 0;
    
}

=======================================================================================================================

// Optimal Solution==> Floyd's Cycle Detection Algorithm


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    if(head==NULL || head->next==NULL){
        return 0;
    }
    
    Node* slow=head;
    Node* fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast){
            int cnt=1;
            slow=slow->next;
            while(slow!=fast){
                cnt++;
                slow=slow->next;
            }
            
            return cnt;
        }
    }
    
    return 0;
}
