#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top = -1;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele){
        if(top<size-1){
            top++;
            arr[top] = ele;
        }else{
            cout<<"Stack Overflow!"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }else{
            cout<<"Stack underfow!"<<endl;
        }
    }
    int topVal(){
        if(top>=0){
            return arr[top];
        }else{
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
    }

    bool empty(){
        if(top>=0){
            return false;
        }
        else{
            return true;
        }
    }
};

int main(){

    Stack st(5);

    st.push(5);
    st.push(10);

    cout<<"Top element:"<<st.topVal()<<endl;

    st.pop();
    cout<<"Top element:"<<st.topVal()<<endl;

    cout<<"Check stack isEmpty:"<<st.empty()<<endl;
    st.pop();
    cout<<"Check stack isEmpty:"<<st.empty()<<endl;

    st.pop();
    st.push(5);
    st.push(10);
    st.push(5);
    st.push(10);
    st.push(5);
    
    




}