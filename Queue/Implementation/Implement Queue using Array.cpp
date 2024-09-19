#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    
    //constructor
    Queue(int size){
        this->size=size;
        arr=new int[size];
        this->front=0;
        this->rear=0;
    }
    
    //push element in queue
    void push(int elm){
        //check overflow
        if(rear==size-1){
            cout<<"Queue is overflow"<<endl;
            return;
        }
        
        else{
            arr[rear]=elm;
            rear++;
        }
    }
    
    //pop element from Queue
    void pop(){
        //check underflow
        if(front==rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        
        else{
            int ans=arr[front];
            arr[front]=-1;
            front++;
            
            if(front==rear){
                front=0;
                rear=0;
            }
            
            cout<<"Remove element: "<<ans<<endl;
            return;
        }
    }
    
    //find front of Queue
    void getFront(){
        //check underflow
        if(front==rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        
        else{
            cout<<"Front Elm: "<<arr[front]<<endl;
            return;
        }
    }
    
    //is empty Queue
    bool isEmpty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }
    
    //print Queue
    void printQueue(){
        for(int i=front;i<rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
};

int main()
{
    Queue myQueue(6);
    
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    
    myQueue.getFront();
    myQueue.printQueue();
    
    myQueue.pop();
    
    myQueue.getFront();
    myQueue.printQueue();
    
    myQueue.pop();
    
    myQueue.getFront();
    myQueue.printQueue();
    
    myQueue.pop();
    
    myQueue.getFront();
    myQueue.printQueue();
    
    return 0;
}
