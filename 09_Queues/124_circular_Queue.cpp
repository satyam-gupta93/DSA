#include<iostream>
using namespace std;

class Queue{
    public:
        int *arr;
        int size;
        int front;
        int rear;


        Queue(int k){
            this->size = k;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push(int val){
            if( ((rear+1)%size) == front){
                cout<<"Queue is Fulll!"<<endl;
                return;
            }
            if(front==-1){
                front = rear = 0;
            }else{
                rear = (rear+1)%size;
            }
            arr[rear] = val;
        }

        void pop(){
            if(front==-1){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            if(front==rear){
                front = rear = -1;
            }else{
                front = (front+1)%size;
            }
        }
        int getFront(){
            if(front==-1){
                return -1;
            }else{
                return arr[front];
            }
        }
};

int main(){

    Queue q(5);

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);
    
    cout<<q.getFront()<<endl;

    q.pop();
    cout<<q.getFront()<<endl;

    // q.pop();
    // cout<<q.getFront()<<endl;

    // q.pop();
    // cout<<q.getFront()<<endl;

    // q.pop();
    // cout<<q.getFront()<<endl;

    // q.pop();
    // cout<<q.getFront()<<endl;

    // q.pop();
    q.push(30);
    cout<<q.getFront()<<endl;





}