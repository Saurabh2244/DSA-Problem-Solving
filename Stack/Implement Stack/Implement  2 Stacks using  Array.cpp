#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int size;
    int top1;
    int top2;
    int *arr;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        this->top1 = -1;
        this->top2 = size;
    }

    // Push in stack1
    void push1(int element) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = element;
        } else {
            cout << "Stack1 is overflow" << endl;
        }
    }

    // Push in stack2
    void push2(int element) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = element;
        } else {
            cout << "Stack2 is Overflow" << endl;
        }
    }

    // Pop from stack1
    void pop1() {
        if (top1 >= 0) {
            top1--;
        } else {
            cout << "Stack1 is Underflow" << endl;
        }
    }

    // Pop from stack2
    void pop2() {
        if (top2 < size) {
            top2++;
        } else {
            cout << "Stack2 is Underflow" << endl;
        }
    }

    // Top of stack1
    void topOfStack1() {
        if (top1 >= 0) {
            cout << arr[top1];
        } else {
            cout << "Stack1 is empty" << endl;
        }
    }

    // Top of stack2
    void topOfStack2() {
        if (top2 < size) {
            cout << arr[top2];
        } else {
            cout << "Stack2 is empty" << endl;
        }
    }
};

int main() {
    // Example usage
    Stack myStack(5);

    myStack.push1(10);
    myStack.push1(20);
    myStack.push2(30);
    myStack.push2(40);

    myStack.topOfStack1(); // Output: 20
    cout<<endl;
    myStack.topOfStack2(); // Output: 40
    cout<<endl;

    myStack.pop1();
    myStack.pop2();

    myStack.topOfStack1(); // Output: 10
    cout<<endl;
    
    myStack.topOfStack2(); // Output: 30
    cout<<endl;

    return 0;
}
