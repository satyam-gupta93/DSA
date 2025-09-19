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

void removeDuplicate(Node* &head){
    Node* temp = head;

    while(temp!=NULL && temp->next!=NULL){
        if(temp->data == temp->next->data){
            Node* duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate; 
        }else{
            temp = temp->next;
        }
        
    }
}

int main(){

    
    Node* head = new Node(10);

    Node *second = new Node(15);
    head->next = second;

    Node *third = new Node(15);
    second->next = third;

    Node *forth = new Node(15);
    third->next = forth;
   

    cout<<endl;

    print(head);
    removeDuplicate(head);
     print(head);

    



}