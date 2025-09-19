#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
       
    }
     cout<<endl;

}
int main(){
    queue<int> q;
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    print(q);
    q.pop();
    print(q);

}