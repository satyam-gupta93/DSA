#include<iostream>
#include<map>
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

    map<Node*,bool> visited;

    Node *temp = head;

    while(temp!=NULL){

        if(visited[temp]==true){
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
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
   
    // print(head);

    cout<<checkLoop(head);



}