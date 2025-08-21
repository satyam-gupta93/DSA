#include<iostream>
using namespace std;

int power(int a,int b){
    int prodouct=1;
    for(int i=1; i<=b ; i++){
        prodouct = prodouct * a;
    }
    return prodouct;
}

int main(){
    cout<<power(2,0);
}