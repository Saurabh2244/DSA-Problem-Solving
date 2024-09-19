// Brute Force==> Use map for store node is visited or not


/*struct Node
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
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        if(head==NULL || head->next==NULL){
            return -1;
        }
        
        unordered_map<Node*,int>mpp;
        
        Node* temp=head;
        
        while(temp!=NULL){
            
            if(mpp.find(temp)!=mpp.end()){
                return temp->data;
            }
            
            mpp[temp]=1;
            
            temp=temp->next;
        }
        
        return -1;;
    }
};

=============================================================================================================================

// Optimal Solution==> Use Floyd's Cycle Detection Algorithm


