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

   
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);
    cout<<"head"<<endl;
}


void deleteAtHead(Node* &head){

    if(head==NULL){
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    Node *deleteHead = head;

    while(temp->next!=head){
        temp = temp->next;
    }

    head = head->next;
    temp->next = head;


    delete deleteHead;

}


void deleteAtEnd(Node* &head){

    if(head->next ==head){
        deleteAtHead(head);
        return;
    }

    if(head==NULL){
        return;
    }

    Node* curr = head;


    while(curr->next->next!=head){
        curr = curr->next;
    }

    Node* temp = curr->next;
    curr->next = head;

    delete temp;


}

void deleteAtPosition(Node* &head,int posi){
        if (head == NULL || posi < 1) {
        return;
    }
    if(posi==1){
        deleteAtHead(head);
        return;
    }

    int currPosi = 1;
    Node* temp = head;

    while(currPosi < posi -1 && temp->next!=head){
        temp = temp->next;
        currPosi++;
    }

    if(temp->next->next == head){
        deleteAtEnd(head);
    }else{
        Node* deleteNode = temp->next;

        temp->next = temp->next->next;

        delete deleteNode;

    }
}


void deleteAtValue(Node* &head,int value){

    if(value==head->data){
        deleteAtHead(head);
        return;
    }
    if(head==NULL){
        return;
    }

    Node* curr = head;

    while(curr->next!=head && curr->next->data!=value){
        curr = curr->next;
    }
    if(curr->next == head){
        return;
    }
    Node* nodeDelete = curr->next;
    curr->next = nodeDelete->next;

    delete nodeDelete;
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

    deleteAtHead(head);
    print(head);

    deleteAtEnd(head);
    print(head);

    deleteAtPosition(head,2);
    print(head);

    deleteAtValue(head,10);
    print(head);

    deleteAtPosition(head,1);
    print(head);

    
    


}