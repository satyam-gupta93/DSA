#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;


    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

};

void print(Node* head){

    Node* temp = head;
    cout<<"NULL<->";
    while(temp!=NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

    
}


void deleteAtHead(Node* &head){

    if(head==NULL){
        return;
    }

    if(head->next==NULL){
        head = NULL;
        return;
    }

    Node *temp = head;
    
    head = head->next;

   delete temp;
}

void deleteAtEnd(Node *&head){
    Node *temp = head;

    if(head->next==NULL){
        head = NULL;
        return;
    }

    while(temp->next->next!=NULL ){
        temp= temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = NULL;

    delete temp2;
}

void deleteAtPosition(Node* &head,int posi){

    if (head == NULL) return;

    if (posi == 1) {
        deleteAtHead(head);
        return;
    }

    Node* curr = head;
    int currPosi = 1;

    // Move to the (posi - 1)th node
    while (currPosi < posi - 1 && curr->next != NULL) {
        curr = curr->next;
        currPosi++;
    }

    // Safety check: if curr or curr->next is NULL, position is invalid
    if (curr == NULL || curr->next == NULL) return;

    Node* nodeToDelete = curr->next;
    curr->next = nodeToDelete->next;

    // If nodeToDelete is not the last node
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = curr;
    }

    delete nodeToDelete;
  
}

void deleteAtValue(Node* &head, int value){

    if(head==NULL){
        return;
    }
    if(head->data == value){
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL && temp->next->data != value){
        temp = temp->next;
    }

    if(temp->next==NULL || temp == NULL){
        return;
    }
    Node *nodeTodelete = temp->next;
    temp->next = nodeTodelete->next;

    if(nodeTodelete->next!=NULL){
        nodeTodelete->next->prev = temp;
    }

    delete nodeTodelete;
}

int main(){

    Node* head = new Node(10);

    Node *first = new Node(15);
    head->next = first;
    first->prev = head;

    Node *second = new Node(20);
    first->next = second;
    second->prev = first;

    Node *third = new Node(25);
    second->next = third;
    third->prev = second;

    cout<<endl;

    print(head);

    deleteAtHead(head);
    print(head);

    deleteAtEnd(head);
    print(head);

    deleteAtPosition(head,2);
    print(head);

    deleteAtValue(head,15);
    print(head);


    cout<<endl;

}