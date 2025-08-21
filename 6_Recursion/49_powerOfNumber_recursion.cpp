#include<iostream>
using namespace std;

int powerNum(int num,int pow){
    if(pow==0){
        return 1;
    }
    pow = pow -1;
    return num * powerNum(num,pow);
}

int main(){

    int num = 2;
    int pow = 4;

    int ans = powerNum(2,4);
    cout<<"Ans:"<<ans;
}