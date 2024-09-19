#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void insertNode(Node*& tail, int target, int data) {
    // Empty list
    if (tail == nullptr) {
        Node* temp = new Node(data);
        temp->next = temp;
        temp->prev = temp;
        tail = temp;
        return;
    }

    Node* curr = tail->next;
    bool flag = false;

    do {
        if (curr->data == target) {
            flag = true;
            break;
        }

        curr = curr->next;

    } while (curr != tail->next);

    if (!flag) {
        cout << "Target is Not Found. So we can't add" << endl;
        return;
    }

    Node* temp = new Node(data);
    temp->next = curr->next;
    temp->prev = curr;
    curr->next->prev = temp;
    curr->next = temp;

    if (curr == tail) {
        tail = temp;
    }
}

void delete_from_value(Node*& tail, int target) {
    if (tail == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (tail->next == tail && tail->data == target) {
        Node* temp = tail;
        tail = nullptr;
        delete temp;
        return;
    }

    Node* curr = tail->next;
    bool flag = false;

    do {
        if (curr->next->data == target) {
            flag = true;
            break;
        }

        curr = curr->next;

    } while (curr != tail->next);

    if (curr->next == tail) {
        tail = curr;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    temp->next->prev = curr;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
}

void printList(Node*& tail) {
    if (tail == nullptr) {
        cout << "List is Empty" << endl;
        return;
    }

    Node* curr = tail->next;

    do {
        cout << curr->data << " ";
        curr = curr->next;

    } while (curr != tail->next);
}

int main() {
    Node* tail = nullptr;

    insertNode(tail, 0, 1);
    insertNode(tail, 1, 2);
    insertNode(tail, 2, 3);

    printList(tail);
    cout << endl << endl;

    insertNode(tail, 3, 8);
    printList(tail);
    cout << endl << endl;

    delete_from_value(tail, 2);
    printList(tail);
    cout << endl << endl;

    return 0;
}
