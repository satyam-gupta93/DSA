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


    cout<<endl;

}