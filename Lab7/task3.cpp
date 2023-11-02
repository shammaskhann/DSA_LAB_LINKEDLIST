#include<iostream>
using namespace std;

struct Node {
    int data; 
    Node *next; 
};

Node *addToEmpty(Node *last, int data) {
    if (last != NULL)
        return last;
    Node *temp = new Node();
    temp -> data = data;
    last = temp;
    last -> next = last;
    return last;
}
Node *addBegin(Node *last, int data) {
    if (last == NULL)
        return addToEmpty(last, data);
    Node *temp = new Node();
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    return last;
}
Node *addEnd(Node *last, int data) {
    if (last == NULL)
        return addToEmpty(last, data);
    Node *temp = new Node();
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
    return last;
}

void traverse(Node *last) {
    if (last == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node *p = last -> next;
    do {
        cout << p -> data << " ";
        p = p -> next;
    } while(p != last -> next);
}

int main() {
    Node *last = NULL;
    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    traverse(last);
    cout << endl;
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    traverse(last);
    cout << endl;
    last = addEnd(last, 12);
    traverse(last);

    return 0;
}