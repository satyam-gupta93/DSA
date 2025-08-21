#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    public:
    Node* front = NULL;
    Node* rear = NULL;
   
    void push(int x){
        Node* newNode = new Node(x);

        if(rear==NULL){
            front = rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    int pop(){
        if(front==NULL){
            return -1;
        }
        int val = front->data;
        Node *temp = front;
        front = front->next;
        if(front==NULL){
            rear = NULL;
        }

        delete temp;
        return val;

    }

    bool empty(){
        if(front==NULL){
            return true;
        }else{
            return false;
        }
    }

    int getFront(){
        if(front==NULL){
            return -1;
        }else{
            return front->data;
        }
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    cout << q.getFront() << endl; // 10
    q.pop();
    cout << q.getFront() << endl; // 20
    cout << (q.empty() ? "Empty" : "Not Empty") << endl;
}