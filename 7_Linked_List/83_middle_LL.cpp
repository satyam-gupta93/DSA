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



int getLength(Node *head){
    Node *temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }

    return len;
};

// length appproach
Node *findMiddle(Node *head) {
    // Write your code here
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }

    int len = getLength(head);

    int start = (len/2);

    while(start>0){
        head = head->next;
        start--;
    }


    return head;

    
}

// two pointer approach
Node *findMiddleLL(Node* &head){
    Node *slow = head;
    Node *fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}




int main(){

    
    Node* head = new Node(10); 

    Node *second = new Node(15);
    head->next = second;

    Node *third = new Node(20);
    second->next = third;

    Node *forth = new Node(25);
    third->next = forth;

    // Node *five = new Node(25);
    // forth->next = five;

    cout<<endl;

    print(head);
   // head = findMiddle(head);
    
    head = findMiddleLL(head);
    print(head);

    




}