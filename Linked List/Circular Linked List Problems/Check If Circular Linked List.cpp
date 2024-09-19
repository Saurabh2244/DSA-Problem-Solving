// Same as is loop is present or not.

Use Floyd's Cycle detection algorithm

/* Link list Node 
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

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
   if(head==NULL || head->next==NULL){
       return false;
   }
   
   Node* slow=head;
   Node* fast=head;
   
   while(fast!=NULL && fast->next!=NULL){
       slow=slow->next;
       fast=fast->next->next;
       
       if(slow==fast){
           return true;
       }
   }
   
   return false;
}
