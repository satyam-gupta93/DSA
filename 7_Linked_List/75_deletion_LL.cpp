#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void print(Node* head){

    Node *temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

void deleteAthead(Node* &head){

  if (head == NULL) return;

    Node *temp = head;
    head = head->next;

    delete temp;
}

void deleteAtend(Node* head){

    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp->next->next!=NULL){
        temp = temp->next;
    };
    delete temp->next;
    temp->next = NULL;

    
}

void deleteAtPosition(Node* head,int posi){

    if (head == NULL) return;

    if (posi == 1) {
        deleteAthead(head);
        return;
    }
    Node *current = head;
    int currPosi = 1;

    while(currPosi < posi -1 && current->next != NULL){
        current = current->next;
        currPosi++;
    }

    if (current == NULL || current->next == NULL) return;
    Node *temp = current->next;
    current->next = current->next->next;

    delete temp;
}

void deleteAtValue(Node* head, int data){

    if (head == NULL) return;
    
    Node* current = head;

    if(head->data==data){
        deleteAthead(head);
        return;
    }

    while(current->next->data != data  && current->next != NULL){
        current = current->next;
    }

    if(current->next == NULL) return; // value not found
    Node* temp = current->next;
    current->next = current->next->next;

    delete temp;
}

int main(){

    Node* head = new Node(10);

    Node *second = new Node(15);
    head->next = second;

    Node *third = new Node(20);
    second->next = third;

    Node *forth = new Node(25);
    third->next = forth;

    cout<<endl;

    print(head);

    // deleteAthead(head);
    // print(head);

    // deleteAtend(head);
    // print(head);

    // deleteAtPosition(head,2);
    // print(head);

    // deleteAtValue(head,20);
    // print(head);

    deleteAtValue(head,15);
    print(head);

    cout<<endl;



}