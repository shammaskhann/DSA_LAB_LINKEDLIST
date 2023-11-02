#include <iostream>
using namespace std;
struct Node{
    int data; 
    Node* next;
};
Node* start = NULL;
void insertAtBeginning(int data){
       Node* newNode = new Node();
       newNode->data = data;
       //cout<<newNode->data<<endl;
       newNode->next = start;
       start = newNode;
}
void insertAtEnd(int data){
      Node* newNode = new Node();
      newNode->data = data;
      newNode->next = NULL;
      if(start == NULL){
      start = newNode;
      return;
}
Node* temp = start;
while(temp->next != NULL){
temp = temp->next;
}
temp->next = newNode;
}
void insertAtPosition(int data, int position){
	position = position + 1;
Node* newNode = new Node();
newNode->data = data;
if(position == 1){
newNode->next = start;
start = newNode;
return;
}
Node* temp = start;
for(int i = 1; i < position - 1; i++){
temp = temp->next;
}
newNode->next = temp->next;
temp->next = newNode;
}
void deleteFromBeginning(){
if(start == NULL){
cout<<"List is empty\n";
return;
}
Node* temp = start;
start = start->next;
delete temp;
}
void deleteFromEnd(){
if(start == NULL){
cout<<"List is empty\n";
return;
}
Node* temp = start;
while(temp->next->next != NULL){
temp = temp->next;
}
delete temp->next;
temp->next = NULL;
}
void deleteFromPosition(int position){
if(start == NULL){
cout<<"List is empty\n";
return;
}
if(position == 1){
Node* temp = start;
start = start->next;
delete temp;
return;
}
Node* temp = start;
for(int i = 1; i < position - 1; i++){
temp = temp->next;
}
Node* temp2 = temp->next;
temp->next = temp2->next;
delete temp2;
}
void traverse(){
if(start == NULL){
cout<<"List is empty\n";
return;
}
Node* temp = start;
while(temp != NULL){
cout<<temp->data<<" ";
temp = temp->next;
}
cout<<endl;
}
void main(){
do{
cout<<"1. Insert an element at beginning\n";
cout<<"2. Insert an elemt at the end of the link list\n";
cout<<"3. Insert an element at position provided by user\n";
cout<<"4. Traverse the list\n";
cout<<"5. Delete an elment from beginning\n";
cout<<"6. Delete an elment from end\n";
cout<<"7. Delete an elment from position provided by user.\n";
cout<<"8. Exit\n";
cout<<"Enter your choice: ";
int choice;
cin>>choice;
switch(choice){
case 1:
cout<<"Enter data: ";
int data;
cin>>data;
insertAtBeginning(data);
break;	
case 2:
cout<<"Enter data: ";
cin>>data;
insertAtEnd(data);
break;
case 3:
cout<<"Enter data: ";
cin>>data;
cout<<"Enter position: ";
int position;
cin>>position;
insertAtPosition(data, position);
break;
case 4:
traverse();
break;
case 5:
deleteFromBeginning();
break;
case 6:
deleteFromEnd();
break;
case 7:
cout<<"Enter position: ";
cin>>position;
deleteFromPosition(position);
break;
case 8:
exit(0);
break;
default:
cout<<"Invalid choice\n";
break;
}
}while(true);
}