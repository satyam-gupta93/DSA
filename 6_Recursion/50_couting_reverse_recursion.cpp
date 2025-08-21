#include<iostream>
using namespace std;

void reverseCouning(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    n = n - 1;
    reverseCouning(n);
}

int main(){

    int num = 10;
    reverseCouning(num);
    
}