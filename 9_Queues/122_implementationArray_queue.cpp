#include<iostream>
using namespace std;

class Queue{
    int size;
    int *arr;
    int front;
    int rear;
public:
    Queue(int size){
       this->size = size;
       arr = new int[size];
       front = 0;
       rear = 0;
    }

    void push(int x){
        if(rear>=size){
            cout<<"Queuen is full!";
            return;
        }
        arr[rear] = x;
        rear++;
    }

    int pop(){
        if(rear==front){
            return -1;
        }else{
            int curr = front;
            front++;
            if(front==rear){
                front = 0;
                rear = 0;
            }
            return arr[curr];
        }
    }

    bool empty(){
        if(front==rear){
            return true;
        }else{
            return false;
        }
    }

    int getFront(){
        if(front==rear){
            return -1;
        }else{
            return arr[front];
        }
    }
        void print() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

void print1(Queue q) { // copy of q
    while (!q.empty()) {
        cout << q.getFront() << " ";
        q.pop();
    }
    cout << "\n";
}
main(){
    
   Queue q(10);

   q.push(10);
   q.push(115);
   q.push(20);
   q.push(10);

   cout<<"Top:"<<q.getFront()<<endl;

   q.pop();
   cout<<"Top:"<<q.getFront()<<endl;

   print1(q);




}