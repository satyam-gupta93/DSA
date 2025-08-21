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

bool check(Node *head){
    
    if(head==NULL){
        return true;
    }
    Node *temp = head->next;

    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }

    if(temp==head){
        return true;
    }else{
        return false;
    }
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
    cout<<check(head);




}