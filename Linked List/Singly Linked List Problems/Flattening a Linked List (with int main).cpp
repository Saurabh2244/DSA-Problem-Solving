#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* next;
    Node* bottom;
    int data;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->bottom=NULL;
    }
};

void insertAtTail(Node* &head,Node*&tail,int data){
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

void insertAtTailByArray(Node*&head,Node*&tail,int arr[],int n){
    for(int i=0;i<n;i++){
        insertAtTail(head,tail,arr[i]);
    }
}

void insertAtBottom(Node* &head,Node*&runner,int data){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        runner=temp;
        return;
    }
    
    Node* temp=new Node(data);
    runner->bottom=temp;
    runner=temp;
}


void insertAtBottomByArray(Node* &head,int arr[],int n){
    Node* runner=head;
    for(int i=0;i<n;i++){
        insertAtBottom(head,runner,arr[i]);
    }
}

void printList(Node* &head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->bottom;
    }
}

Node* merge2LL(Node* &head1,Node*&head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    if(head1->data <= head2->data){
        head1->bottom=merge2LL(head1->bottom,head2);
        return head1;
    }
    
    else{
        head2->bottom=merge2LL(head1,head2->bottom);
        return head2;
    }
}

Node* flatten(Node* root){
    //base case
    if(root==NULL || root->next==NULL){
        return root;
    }
    
    root->next=flatten(root->next);
    
    root=merge2LL(root,root->next);
    root->next=NULL;
    
    return root;
}

int main()
{
    Node*head1=NULL;
    Node*tail1=NULL;
    
    Node*head2=NULL;
    Node*tail2=NULL;
    
    Node*head3=NULL;
    Node*tail3=NULL;
    
    Node*head4=NULL;
    Node*tail4=NULL;
    
    Node*head5=NULL;
    Node*tail5=NULL;
    
    int arr1[]={5,10,19,28};
    int arr2[]={7,8,30};
    int arr3[]={20};
    int arr4[]={22,50};
    int arr5[]={35,40,45};
    
    insertAtTailByArray(head1,tail1,arr1,4);
    
    insertAtBottomByArray(head1,arr2,3);
    insertAtBottomByArray(head1->next,arr3,1);
    insertAtBottomByArray(head1->next->next,arr4,2);
    insertAtBottomByArray(head1->next->next->next,arr5,3);
    
    Node* flat=flatten(head1);
    
    printList(flat);

    return 0;
}
