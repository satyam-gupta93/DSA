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
int getLength(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

// iteretive solution
Node* reverseKGroup(Node* &head,int k){

   
    if(head == NULL || k == 1){
        return head;
    }
    int len = getLength(head);
    if(len < k) return head; 
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int count = 0;
    
    while(curr!=NULL && count<k){
       
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // head = prev;

    if(forward!=NULL){
        head->next = reverseKGroup(forward,k);
    }



    return prev;
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
    head = reverseKGroup(head,3);
     print(head);




}