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
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertAtHead(Node* &head, int data){

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAfterHead(Node* head,int data){
    Node* temp = new Node(data);

    temp->next = head->next;
    head->next = temp;
    
}

void insertAtLast(Node* head,int data){
    Node *temp = new Node(data);
    Node *temp2 = head;

    while(temp2->next!=NULL){
        temp2 = temp2->next;

    }
    temp2->next = temp;
}

void insertAtPosition(Node* head,int data,int pos){

    
    Node *temp = new Node(data);
    Node* current = head; 
    int currPosi = 1;
    while(currPosi < pos-1){
         
        current = current -> next;
        currPosi++;
       
    }

    temp->next = current->next;
    current->next = temp;

}
int main(){

    Node* head = new Node(15);
    print(head);
    
    insertAtHead(head,20);
    print(head);

    insertAtHead(head,25);
    print(head);

    insertAtLast(head,30);
    print(head);

    insertAfterHead(head,26);
    print(head);

    insertAtPosition(head,21,3);
    print(head);

    insertAtPosition(head,24,1);
    print(head);




}