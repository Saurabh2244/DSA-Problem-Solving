// Approach==> Just create 2 variables num1 and num2 and make number by traverse through LL and then multiply

/* Linked list node structure
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/

/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  
    long long int MOD=1000000007;
    long long int num1=0;
    long long int num2=0;
  
    Node* curr1=l1;
    while(curr1!=NULL){
        num1=(num1*10+curr1->data)%MOD;
        curr1=curr1->next;
    }
    
    Node* curr2=l2;
    while(curr2!=NULL){
        num2=(num2*10+curr2->data)%MOD;
        curr2=curr2->next;
    }
    
    return (num1*num2)%MOD;
  
}
