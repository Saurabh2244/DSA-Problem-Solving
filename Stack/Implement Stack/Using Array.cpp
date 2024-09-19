#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;
    
    Stack(int size){
        this->size=size;
        top=-1;
        arr=new int[size];
    }
    
    void pushElm(int elm){
        if(size-top>1){
            top++;
            arr[top]=elm;
        }
        
        else{
            cout<<"Stack is overflow"<<endl;
            return;
        }
    }
    
    int popElm(){
        if(top>=0){
            int ans=arr[top];
            top--;
            return ans;
        }
        
        else{
            cout<<"Stack is underflow"<<endl;
            return -1;
        }
    }
    
    void getTop(){
        if(top>=0){
            cout<<"Top Element is "<<arr[top]<<endl;
            return;
        }
        
        else{
            cout<<"Stack is empty"<<endl;
            return;
        }
    }
    
    void isEmpty(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        
        else{
            cout<<"Stack is not empty"<<endl;
        }
        
        return;
    }
    
    void printStack(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        
        return;
    }
};


int main()
{
    int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;

    Stack myStack(stackSize);

    // Example 1: Pushing elements into the stack
    myStack.pushElm(10);
    myStack.pushElm(20);
    myStack.pushElm(30);

    // Example 2: Printing the stack
    cout << "Stack elements: ";
    myStack.printStack();
    cout << endl;

    // Example 3: Popping an element from the stack
    int poppedElement = myStack.popElm();
    if (poppedElement != -1)
    {
        cout << "Popped Element: " << poppedElement << endl;
    }

    // Example 4: Getting the top element of the stack
    myStack.getTop();

    // Example 5: Checking if the stack is empty
    myStack.isEmpty();

    // Example 6: Popping more elements to demonstrate underflow
    myStack.popElm();
    myStack.popElm();
    myStack.popElm(); // This will print Stack is underflow

    return 0;
}

