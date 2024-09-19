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


void printList(Node* &head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node*flatMultilevel(Node*&head){
    queue<Node*>q;
    Node* temp=head;
    while(temp!=NULL){
        
       if(temp->bottom!=NULL){
           q.push(temp->bottom);
           temp->bottom=NULL;
       }
       
        if(temp->next==NULL && !q.empty()){
           Node* x=q.front();
           q.pop();
           
           temp->next=x;
           temp=x;
        }
        
        else{
            temp=temp->next;
        }
    }
    
    return head;
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
    
    Node*head6=NULL;
    Node*tail6=NULL;
    
    Node*head7=NULL;
    Node*tail7=NULL;
    
    Node*head8=NULL;
    Node*tail8=NULL;
    
    int arr1[] = {10, 5, 12, 7, 11}; 
    int arr2[] = {4, 20, 13}; 
    int arr3[] = {17, 6}; 
    int arr4[] = {9, 8}; 
    int arr5[] = {19, 15}; 
    int arr6[] = {2}; 
    int arr7[] = {16}; 
    int arr8[] = {3};
    
    insertAtTailByArray(head1,tail1,arr1,5);
    insertAtTailByArray(head2,tail2,arr2,3);
    insertAtTailByArray(head3,tail3,arr3,2);
    insertAtTailByArray(head4,tail4,arr4,2);
    insertAtTailByArray(head5,tail5,arr5,2);
    insertAtTailByArray(head6,tail6,arr6,1);
    insertAtTailByArray(head7,tail7,arr7,1);
    insertAtTailByArray(head8,tail8,arr8,1);
    
    head1->bottom = head2; 
    head1->next->next->next->bottom = head3; 
    head3->bottom = head4; 
    head4->bottom = head5; 
    head2->next->bottom = head6; 
    head2->next->next->bottom = head7; 
    head7->bottom = head8;
    
    
    Node* flat=flatMultilevel(head1);
    
    printList(flat);

    return 0;
}
