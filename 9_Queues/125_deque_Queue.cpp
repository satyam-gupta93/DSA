#include<iostream>
using namespace std;

class Deque{
    public:
        int *arr;
        int size;
        int front;
        int rear;


        Deque(int k){
            this->size = k;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        bool isFull(){
            if( ((rear+1)%size) == front){
                return true;
            }else{
                return false;
            }
        }
        bool isEmpty(){
            if(front==-1){
                return true;
            }else{
                 return false;
            }
               
            
        }
        void insertFront(int x){
            if(isFull()){
                cout<<"Deque Full!";
                return;
            }

            if(front==-1){
                front = rear = 0;
            }else if(front==0){
                front = size-1;
            }else{
                front--;
            }

            arr[front] =  x;
        }

        void insertRear(int x){
            if(isFull()){
                cout<<"Deque Fulled!"<<endl;
                return;
            }
            if(front==-1){
                front =  rear = 0;
            }else if(rear==size-1){
                rear = 0;
            }else{
                rear++;
            }
            arr[rear] =  x;
        }

        void deleteFront(){
            if(front==-1){
                cout<<"Deque empty!"<<endl;
                return;
            }
            if(front==rear){
                front = rear = -1;
            }else if(front == size-1){
                front = 0;
            }else{
                front++;
            }
        }
        void deleteRear(){
            if(front==-1){
                cout<<"Deque empty!"<<endl;
                return;
            }
            if(front==rear){
                front = rear = -1;
                return;
            }
            else if(rear==0){
                rear = size -1;
            }else{
                rear--;
            }
        }

        void display() {
            if (isEmpty()) {
                cout << "Deque is empty!\n";
                return;
            }
        cout << "Deque: ";
        int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % size;
            }
        cout << "\n";
    }

};

int main(){


 Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);

    dq.display();

    dq.deleteRear();
    dq.deleteFront();

    dq.display();



}