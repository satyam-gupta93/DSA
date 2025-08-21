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

Node * reverseDLL(Node* head) {
        // Your code here
        if(head==NULL || head->next == NULL){
            return head;
        }
        Node* curr = head;
        Node* forward = NULL;
        
        while(curr!=NULL){
            forward = curr->next;
            curr->next = curr->prev;
            curr->prev = forward;
            head = curr;
            curr = forward;
        }
        
        return head;
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
    head = reverseDLL(head);
    print(head);





    cout<<endl;

}