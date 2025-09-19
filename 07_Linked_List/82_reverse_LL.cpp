#include<iostream>
using namespace std;


class Node{
    public:
    int data ;
    Node* next;


    Node(int data){
        this->data = data;  
        this->next = NULL;

    };
};

void print(Node* head){
    Node *temp = head;
    
   while(temp!=NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
   }
   cout<<endl;
}


void insertAtHead(Node* &head, int data){

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
// iteretive solution
Node* reverseLinkedList(Node* &head){

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while(curr!=NULL){
       
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    
    // head = prev;
    return prev;
}


// recursive solN 
// void reverse(Node* prev,Node* &curr,Node* forward,Node* &head){
//     if(curr == NULL){
//         head = prev;
//         return;
//     }
//     forward = curr->next;
//     curr->next = prev;
//     prev = curr;
//     curr = forward;
//     reverse(prev,curr,forward,head);
// }
void reverse(Node* prev, Node* &curr, Node* &head){
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* forward = curr->next;
    curr->next = prev;
    reverse(curr, forward, head);
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
    head = reverseLinkedList(head);
    cout<<"Reverse"<<endl;

    print(head);reverse(NULL, head, head);
    reverse(NULL, head, head);
    print(head);




}