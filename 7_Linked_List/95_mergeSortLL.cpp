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
Node *merge(Node* left, Node* rigth){
    if(left==NULL){
        return rigth;
    }
    if(rigth==NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* tail = ans;

    while(left!=NULL && rigth!=NULL){
        if(left->data<=rigth->data){
            tail->next = left;
            left = left->next;
        }else{
            tail->next = rigth;
            rigth = rigth->next;
        }
        tail = tail->next;
    }

    if(left!=NULL){
        tail->next = left;
    }else{
        tail->next = rigth;
    }


    Node *temp = ans->next;
    delete ans;

    return temp;


}
Node *findMid(Node *head){
    Node *slow  = head;
    Node *fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast  = fast->next->next;
    }

    return slow;
}
Node *mergeSort(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *mid = findMid(head);

    Node* left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);


    //merge both 
    Node* result = merge(left,right);

    return result;
}



int main(){

    
    Node* head = new Node(20);

    Node *second = new Node(15);
    head->next = second;

    Node *third = new Node(12);
    second->next = third;

    Node *forth = new Node(15);
    third->next = forth;
   

    cout<<endl;

    print(head);
    head = mergeSort(head);
    print(head);

    



}