#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* start = NULL;
void push(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = start;
    start = newNode;
}
void pop() {
    if (start == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = start;
    start = start->next;
    delete temp;
}
void display() {
    if (start == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = start;
    while (temp != NULL) {
        cout << temp->data << " | ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
}