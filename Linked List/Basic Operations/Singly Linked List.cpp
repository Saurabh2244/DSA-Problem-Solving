#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//create class of Node
class Node{
    public:
    
    int data;
    Node*next;
    
    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    
    //destructor
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        
        cout<<"memory is free for node with data "<<value<<endl;
    }
    
};

//insert at head
void insertAtHead(Node*&head,Node*&tail,int data){
    //if linked list is empty
    if(head==NULL){
        //create Node
        Node*node1=new Node(data);
        head=node1;
        tail=node1;
        return;
    }
    
    //if linked list is not empty
    Node*temp=new Node(data); //create Node
    temp->next=head;
    head=temp;
}

//insert at tail
void insertAtTail(Node*&head,Node*&tail,int data){
    //if linked list empty
    if(head==NULL){
        Node* node1=new Node(data);
        head=node1;
        tail=node1;
        return;
    }
    
    Node*temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

//insert at position
void insertAtPosition(Node*&head,Node*&tail,int position,int length,int data){
    if(position==1){
        insertAtHead(head,tail,data);
        return;
    }
    if(position-length==1){
        insertAtTail(head,tail,data);
        return;
    }
    
    else if(position-length>1){
        cout<<"It not possible to insert at position "<<position<<" because it is more than its length"<<endl;
        return;
    }
    
    Node*temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    
    //create node which would be insert
    Node*nodeToInsert=new Node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
    
    
}

//length of linked list
int length(Node*&head){
    int cnt=0;
    if(head==NULL){
        return cnt;
    }
    
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}


//delete position of linked list
void deletePosition(Node*&head,Node*&tail,int position,int length){
    if(position==1 && position!=0){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        
        delete temp;
        
    }
    
    
    else if(position<=length && position>0){
        Node*curr=head;
        Node*prev=NULL;
        
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        
        if(curr->next==NULL){
            tail=prev;
            prev->next=NULL;
            
        }
        prev->next=curr->next;
        curr->next=NULL;
        
        delete curr;
    }
    
    else{
        cout<<"Youe entered position is not valid"<<endl;
    }
}

//print linked list
void print(Node*&head){
    
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    //create head
    Node* head=NULL;
    
    //create tail
    Node* tail=NULL;
    
    cout<<"Insert at Head:"<<endl;
    insertAtHead(head,tail,10);
    print(head);
    
    insertAtHead(head,tail,20);
    print(head);
    
    insertAtHead(head,tail,30);
    print(head);
    
    cout<<endl<<endl;
    cout<<"Insert at tail:"<<endl;
    insertAtTail(head,tail,20);
    print(head);
    
    insertAtTail(head,tail,80);
    print(head);
    
    insertAtTail(head,tail,40);
    print(head);
    
    cout<<endl<<endl;
    
    int len=length(head);
    cout<<"length of linked list: "<<len<<endl;
    cout<<endl<<endl;
    
    insertAtPosition(head,tail,5,len,100);
    len=length(head);
    print(head);
    cout<<"length of linked list: "<<len<<endl;
    cout<<"Delete Position:"<<endl;
    //deletePosition
    deletePosition(head,tail,7,len);
    print(head);
    
    cout<<"Head data:"<<head->data<<endl;
    cout<<"Tail data:"<<tail->data<<endl;

    return 0;
}
