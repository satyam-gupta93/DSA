#include<iostream>
#include<stack>
using namespace std;

int main(){
    cout<<"Welcome to the world of Stack..!"<<endl;

    stack<int> s;

    s.push(5);
    s.push(10);

    cout<<"Printing top element:"<<s.top()<<endl;
    s.pop();
    cout<<"Printing top element:"<<s.top()<<endl;
    cout<<"Check is empty:"<<s.empty()<<endl;
    s.pop();
    cout<<"Check is empty:"<<s.empty()<<endl;

     s.push(5);
    s.push(10);
    cout<<"Size:"<<s.size()<<endl;

}

