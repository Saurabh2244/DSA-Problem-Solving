// Clone a linked list with next and Random Pointer

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;
    
    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }
};

//insert at tail
void insertAtTail(Node*&head,Node*&tail,int data){
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

//insert at tail by array
void insertAtTailByArray(Node*&head,Node*&tail,vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        insertAtTail(head,tail,arr[i]);
    }
}

//clone list ==>bruteforce using map
Node* cloneLL(Node*&head){
    if(head==NULL){
        return NULL;
    }
    
    Node* ansHead=NULL;
    Node* ansTail=NULL;
    
    Node* c1=head;
    Node* c2=NULL;
    
    while(c1!=NULL){
        insertAtTail(ansHead,ansTail,c1->data);
        c1=c1->next;
    }
    
    c1=head;
    c2=ansHead;
    unordered_map<Node*,Node*>mpp;
    while(c1!=NULL){
        mpp[c1]=c2;
        c1=c1->next;
        c2=c2->next;
    }
    
    c1=head;
    c2=ansHead;
    
    while(c2!=NULL){
        c2->random=mpp[c1->random];
        c1=c1->next;
        c2=c2->next;
    }
    
    return ansHead;
}

//clone List==> Optimal
Node* solve(Node*&head){
    if(head==NULL){
        return NULL;
    }
    
    Node* ansHead=NULL;
    Node* ansTail=NULL;
    
    Node* c1=head;
    Node* t1=NULL;
    
    Node* c2=NULL;
    Node* t2=NULL;
    
    while(c1!=NULL){
        insertAtTail(ansHead,ansTail,c1->data);
        c1=c1->next;
    }
    
    c1=head;
    c2=ansHead;
    
    while(c1!=NULL){
        t1=c1->next;
        c1->next=c2;
        c1=t1;
        
        t2=c2->next;
        c2->next=c1;
        c2=t2;
    }
    c1=head;
    c2=ansHead;
    
    //adjust random pointer
    while(c1!=NULL){
        if(c1->next!=NULL){
            if(c1->random!=NULL){
                c1->next->random=c1->random->next;
            }
            
            else{
                c1->next->random=NULL;
            }
        }
        c1=c1->next->next;
    }
    
    c1=head;
    c2=ansHead;
    
    //make original state
    while(c1!=NULL){
        c1->next=c2->next;
        c1=c1->next;
        
        if(c1!=NULL){
            c2->next=c1->next;    
        }
        
        c2=c2->next;
    }
    
    return ansHead;
}

//print list
void printList(Node* &head){
    
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"("<<temp->random->data<<") ";
        temp=temp->next;
    }
}


int main()
{
    Node* h1=NULL;
    Node* t1=NULL;
    
    vector<int>l1={1,2,3,4,5};
    
    insertAtTailByArray(h1,t1,l1);
  
    h1->random=h1->next->next;
    h1->next->random=h1;
    
    h1->next->next->random=h1->next->next->next->next;
    h1->next->next->next->random=h1->next->next;
    h1->next->next->next->next->random=h1->next;
    
    Node* ans=solve(h1);
    printList(ans);

    return 0;
}
