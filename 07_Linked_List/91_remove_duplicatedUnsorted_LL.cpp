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




void insertAtHead(Node* &head, int data){

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

// remove duplicate tc-o(n^2) and sc - o(1)
void removeDuplicate1(Node* &head){
    if(head==NULL || head->next==NULL){
        return;
    }
    Node* curr = head;
    while(curr!=NULL && curr->next!=NULL){
        Node* temp = curr;
        while(temp->next!=NULL){
            if(curr->data == temp->next->data){
                Node* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            }else{
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

// remove duplicat tc-o(n) and sc-o(n)
void removeDuplicate2(Node *head){
    if(head==NULL || head->next==NULL){
        return;
    }
    map<int,bool> vistied;
    Node* curr = head;
   
   vistied[curr->data] = true;
    while(curr!=NULL && curr->next!=NULL){

        
        if(vistied[curr->next->data]==true){
            Node *duplicate = curr->next;
            curr->next = curr->next->next;
            delete duplicate;
        }else{
            vistied[curr->next->data] = true;
            curr = curr->next;
        }
    }
}



int main(){

    
    Node* head = new Node(10);

    Node *second = new Node(15);
    head->next = second;

    Node *third = new Node(10);
    second->next = third;

    Node *forth = new Node(15);
    third->next = forth;
   

    cout<<endl;

    print(head);
    // removeDuplicate1(head);
    removeDuplicate2(head);
    print(head);

}