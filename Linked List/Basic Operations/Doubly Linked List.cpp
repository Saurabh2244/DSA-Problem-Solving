#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    
    // Destructor
    ~Node() {
        if (next != NULL) {
            delete next;  // Recursively delete the next nodes
            next = NULL;  // Avoid dangling pointer
        }
        if (prev != NULL) {
            prev = NULL;  // Break the backward link to avoid dangling pointers
        }
    }

};

//insert at tail
void insertAtHead(Node*&head,Node*&tail,int data,int &length){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
        length++;
        return;
    }
    
    Node* temp=new Node(data);
    head->prev=temp;
    temp->next=head;
    
    head=temp;
    
    length++;
}

//insert at tail
void insertAtTail(Node*&head,Node*&tail,int data,int &length){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
        length++;
        return;
    }
    
    Node* temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
    
    tail=temp;
    length++;
}

//insert at head by array
void insertAtHeadByArray(Node*&head,Node*&tail,vector<int>&arr,int &length){
    for(int i=0;i<arr.size();i++){
        insertAtHead(head,tail,arr[i],length);
    }
}

//insert at tail by array
void insertAtTailByArray(Node*&head,Node*&tail,vector<int>&arr,int &length){
    for(int i=0;i<arr.size();i++){
        insertAtTail(head,tail,arr[i],length);
    }
}

//insert at position
void insertAtPosition(Node*&head,Node*&tail,int position,int data,int &length){
    if(head==NULL || position<=0 || position>length+1){
        cout<<"Invalid Position"<<endl;
        return;
    }
    
    if(position==1){
        insertAtHead(head,tail,data,length);
        return;
    }
    
    if(position==length+1){
        insertAtTail(head,tail,data,length);
        return;
    }
    
    Node* curr=head;
    while(position>1){
        curr=curr->next;
        position--;
    }
    
    Node* target=curr->prev;
    Node* temp=new Node(data);
    temp->next=curr;
    curr->prev=temp;
    target->next=temp;
    temp->prev=target;
    
    length++;
}

//delete from position
void deleteAtPosition(Node*&head,Node*&tail,int position,int &length){
    if(position<=0 || head==NULL || position>length){
        cout<<"Invalid Position"<<endl;
        return;
    }
    
    if(position==1){
        Node* temp=head;
        head=temp->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        
        length--;
        
        return;
    }
    
    Node* curr=head;
    while(position>1){
        curr=curr->next;
        position--;
    }
    
    if(curr->next==NULL){
        tail=curr->prev;
        Node* temp=tail->next;
        temp->prev=NULL;
        tail->next=NULL;
        
        delete temp;
        
        length--;
        
        return;
    }
    Node* target=curr->prev;
    target->next=curr->next;
    curr->next->prev=target;
    
    curr->next=NULL;
    curr->prev=NULL;
    
    delete curr;
    length--;
}

//print list
void print(Node*&head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}



int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    
    int length=0;
    
    vector<int>a1={1,2,3,4,5};
    insertAtHeadByArray(head,tail,a1,length);
    cout<<"Insert at Head:"<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;
    
    cout<<endl<<endl;
    
    vector<int>a2={10,20,30,40,50};
    insertAtTailByArray(head,tail,a2,length);
    cout<<"Insert at Tail:"<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;
    
    cout<<endl<<endl;
    
    insertAtPosition(head,tail,6,578,length);
    cout<<"Insert at Positiion:"<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;
    
    cout<<endl<<endl;
    
    deleteAtPosition(head,tail,5,length);
    cout<<"Delete at Positiion:"<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;
    cout<<"Length:"<<length<<endl;
    cout<<endl<<endl;
    

    return 0;
}
