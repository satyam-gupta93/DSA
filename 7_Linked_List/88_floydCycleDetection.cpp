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

bool checkLoop(Node *head){
    if(head==NULL){
        return false;
    }

   Node* slow = head;
   Node* fast = head;

   while(fast!=NULL && slow!=NULL){

        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            return true;
        }

   }
   return false;
}


void insertAtHead(Node* &head, int data){

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

int main(){

    
    Node* head = new Node(10);

    Node *second = new Node(15);
    head->next = second;

    Node *third = new Node(20);
    second->next = third;

    Node *forth = new Node(25);
    third->next = forth;
    third->next = head;

    cout<<endl;

    // print(head);
        checkLoop(head);
    // print(head);

    cout<<checkLoop(head);



}