#include<iostream>
using namespace std;

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(Node* head1, Node* head2) {
       
       if(head1==NULL){
           return head2;
       }
       if(head2==NULL){
           return head1;
       }
       
       Node *dummy = new Node(-1);
       Node* tail = dummy;
       
       while(head1!=NULL && head2!=NULL){
           if(head1->data <= head2->data){
               tail->next = head1;
               head1 = head1->next;
           }else{
               tail->next = head2;
               head2= head2->next;
           }
           tail = tail->next;
       }
       
       if(head1!=NULL){
           tail->next = head1;
       }else{
           tail->next = head2;
       }
       
       
       Node *temp = dummy->next;
       
       delete dummy;
       
       return temp;
    }

void print(Node* head){
    Node *temp = head;
    
   while(temp!=NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
   }
   cout<<endl;
}

int main(){

     Node* head1 = new Node(18);

    Node* head2 = new Node(26);
    head2->next = new Node(38);
    head2->next->next = new Node(47);
    head2->next->next->next = new Node(69);
    head2->next->next->next->next = new Node(71);
    head2->next->next->next->next->next = new Node(95);


    Node* head = sortedMerge(head1,head2);

    print(head);


}