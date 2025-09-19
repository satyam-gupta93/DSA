#include<iostream>
using namespace std;


void update1(int a){ ///  copy of "a" is create
    a++;
}

void update(int &a){ /// no copy of "a" is create
    a++;
}

int main(){

    int a = 5;

    // int &ref = a;


    // cout<<"A:"<<a<<endl;
    // cout<<"Ref:"<<ref<<endl;


    // ref = 10;
    // cout<<"A:"<<a<<endl;
    // cout<<"Ref:"<<ref<<endl;


    // a = 15;
    // cout<<"A:"<<a<<endl;
    // cout<<"Ref:"<<ref<<endl;


    cout<<"Before:"<<a<<endl;
    update(a);
    cout<<"After:"<<a<<endl;
    
}