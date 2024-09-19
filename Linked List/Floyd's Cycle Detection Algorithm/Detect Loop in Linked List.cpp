// Brute Force==>Use map for to keep record of vis


/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(head==NULL || head->next==NULL){
            return false;
        }
        
        Node *temp=head;
        unordered_map<Node *,int>mpp;
        
        while(temp!=NULL){
            
            if(mpp.find(temp)!=mpp.end()){
                return true;
            }
            
            mpp[temp]=1;
            
            temp=temp->next;
        }
        
        return false;
    
    }
};

==============================================================================================================================

// Optimal Solution==> Use Floyd's Cycle Detecion Algorithm (slow fast approach)
/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(head==NULL || head->next==NULL){
            return false;
        }
        
        Node *slow=head;
        Node *fast=head;
        
        while(fast!=NULL  && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                return true;
            }
        }
        
        return false;
    }
};

