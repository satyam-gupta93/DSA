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

int getLength(Node *head){

    Node *  temp = head;

    int len = 0;

    while(temp!=NULL){
        len++;
        temp = temp->next;
        
    }

    return len;
}

void print(Node* head){

    Node* temp = head;
    cout<<"NULL<->";
    while(temp!=NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

    
}


void insertAtHead(Node* &head,int data){

    if(head==NULL){
        Node * temp  = new Node(data);
        head = temp;
    }
    else{
        Node *temp = new Node(data);
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    
}

void insertAtEnd(Node* &head,int data){

 

    Node *newNode = new Node(data);
    Node *temp = head;

    while(temp->next!=NULL){
        temp = temp->next;

    }
    temp->next = newNode;
    newNode->prev = temp;




}

void insertAtPosition( Node* &head,int data,int posi){


    if(posi==1){
        insertAtHead(head,data);
    }
    Node* current = head;
    Node *temp = new Node(data);
    int currPosi = 1;

    while(currPosi < posi - 1){
        current = current->next;
        currPosi++;
    }

    temp->next = current->next;
    current->next = temp;
    temp->prev = current;



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

    cout<<"Length of the liked list:"<<getLength(head)<<endl;
    print(head);


    insertAtHead(head,5);
    print(head);

    insertAtEnd(head,30);
    print(head);

    insertAtPosition(head,17,4);
    print(head);

    cout<<"Length of the liked list:"<<getLength(head)<<endl;


    cout<<endl;

}