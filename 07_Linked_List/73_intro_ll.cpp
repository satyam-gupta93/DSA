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

int main(){

    cout<<"Welcome the world of linked list..."<<endl;

    Node* node1 = new Node(10);
    // cout<<"Data:"<< node1->data <<endl;
    // cout<<"Next:"<<node1->next<<endl;
    Node* head = node1;
     print(head);
    insertAtHead(head,12);
    print(head);
    insertAtHead(head,15);
    print(head);



}