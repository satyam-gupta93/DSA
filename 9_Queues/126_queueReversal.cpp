#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q){
    stack<int> s;

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }


}
void reverse1(queue<int> &q){
    if(q.empty()){
        return;
    }
    
    int curr = q.front();
    
    q.pop();
    
    reverse(q);
    
     q.push(curr);
}

int main(){

    queue<int> q1;

    q1.push(10);
    q1.push(15);
    q1.push(20);
    q1.push(25);
    q1.push(30);
    q1.push(40);


    cout<<q1.front()<<endl;

    reverse(q1);
    cout<<q1.front()<<endl;

    reverse1(q1);
    cout<<q1.front()<<endl;
    

}

