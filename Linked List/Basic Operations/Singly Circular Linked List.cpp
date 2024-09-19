#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
      int data;
      Node *next;
      
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertNode(Node *&tail,int target,int data){
    
    //empty
    if(tail==NULL){
        Node*temp=new Node(data);
        tail=temp;
        temp->next=temp;
        return;
    }
    
    Node *curr=tail->next;
    bool flag=false;
    
    do{
        if(curr->data==target){
            flag=true;
            break;
        }
        
        curr=curr->next;
        
    }while(curr!=tail->next);
    
    
    if(flag==false){
        cout<<"Target is Not Found. So we can't add"<<endl;
        return;
    }
    
    Node *temp=new Node(data);
    temp->next=curr->next;
    curr->next=temp;
    
    if(curr==tail){
        tail=temp;
    }
}

void delete_from_value(Node *&tail,int target){
    
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    
    if(tail->next==tail && tail->data==target){
        Node *temp=tail;
        tail=NULL;
        
        delete temp;
        return;
    }
    
    Node *curr=tail->next;
    bool flag=false;
    
    do{
        if(curr->next->data==target){
            flag=true;
            break;
        }
        
        curr=curr->next;
        
    }while(curr!=tail->next);
    
    if(curr->next==tail){
        tail=curr;
    }
    
    Node *temp=curr->next;
    
    curr->next=temp->next;
    temp->next=NULL;
    
    delete temp;
}

void printList(Node *&tail){
    
    if(tail==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    
    Node*curr=tail->next;
    
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
        
    }while(curr!=tail->next);
}

int main(){
    Node *tail=NULL;
    
    insertNode(tail,0,1);
    insertNode(tail,1,2);

    insertNode(tail,2,3);
    
    printList(tail);
    cout<<endl<<endl;
    
    insertNode(tail,3,8);
    printList(tail);
    cout<<endl<<endl;
    
    delete_from_value(tail,2);
    printList(tail);
    cout<<endl<<endl;
    cout<<tail->data<<endl;
}
