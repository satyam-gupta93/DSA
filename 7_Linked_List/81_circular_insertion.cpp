#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


void print(Node *head){

    Node *temp = head;

    if (head == NULL) return;

    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);
    cout<<"head"<<endl;
}

void insertAtHead(Node* &head,int data){

    Node *newNode = new Node(data);
    Node *temp = head;

    
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }


    while(temp->next!=head){
        temp = temp->next;
    }


    newNode->next = head;
    temp->next = newNode;
    head = newNode;

}

void insertAtEnd(Node* &head,int data){

    if(head == NULL){
        insertAtHead(head,data);
    }

    Node *newNode = new Node(data);
    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void insertAtPosition(Node* &head, int data,int posi){

    if(posi<1){
        return;
    }
    if(posi==1){
        insertAtHead(head,data);
        return;
    }

    if(head==NULL){
        insertAtHead(head,data);
        return;
    }

    int currPosi = 1;
    Node *temp = head;

    while(currPosi < posi - 1 && temp->next!=NULL){
        temp = temp->next;
        currPosi++;
    }

    if(temp->next == head && currPosi < posi - 1){
        insertAtEnd(head, data);
        return;
    }

    Node *newNode = new Node(data);

    newNode->next = temp->next;
    temp->next = newNode;


}

int main(){

    Node *head = new Node(5);

    Node *first = new Node(10);
    head->next = first;

    Node *second = new Node(15);
    first->next = second;

    Node *third = new Node(20);
    second->next = third;

    Node *fourth = new Node(25);
    third->next = fourth;


    fourth->next = head;

    print(head);

    insertAtHead(head,4);
    print(head);

    insertAtEnd(head,30);
    print(head);

    insertAtPosition(head,7,3);
    print(head);

    









}