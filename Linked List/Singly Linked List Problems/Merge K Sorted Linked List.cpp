// Approach==> Use merge sort algo as it is. Use start,end ,mid concept on vector of Node

/*Linked list Node structure
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    Node* merge2LL(Node* &left,Node* &right){
        if(left==NULL) return right;
        if(right==NULL) return left;
        
        if(left->data <= right->data){
            left->next=merge2LL(left->next,right);
            return left;
        }
        
        else{
            right->next=merge2LL(left,right->next);
            return right;
        }
    }
    
    Node* solve(int start,int end,Node *arr[]){
        //base case
        if(start==end){
            return arr[start];
        }
        
        int mid=start+(end-start)/2;
        
        Node* left=solve(start,mid,arr);
        Node* right=solve(mid+1,end,arr);
        
        Node* ans=merge2LL(left,right);
        
        return ans;
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        // Your code here
        if(K==0){
            return NULL;
        }   
        
        int start=0;
        int end=K-1;
        
        return solve(start,end,arr);
    }
};
