#include<iostream>
using namespace std;

void counting(int n){
    if(n==0){
        return;
    }
    counting(n-1);
    cout<<n<<" ";
    
}

int main(){

    int num = 10;
    counting(num);
    
}