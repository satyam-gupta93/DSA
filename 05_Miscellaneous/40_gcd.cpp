#include<iostream>
using namespace std;

int getGcd(int a,int b){
    
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }

    while(a!=b){
        if(a>b){
            a = a - b;
        }else{
            b = b - a;
        }
    }

    return a;
}

int main(){

    cout<<"GCD:"<<getGcd(24,12);

}