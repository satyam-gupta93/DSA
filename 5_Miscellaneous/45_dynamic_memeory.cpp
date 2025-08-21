#include<iostream>
using namespace std;

int main(){

// i)__ for variable............
    int* ptr = new int;
    *ptr = 10;
    cout<<"Value:"<<*ptr<<endl;
    delete ptr;


    //ii)__ for dynamic arrays.................
    int n;
    cout<<"Enter n:";
    cin>>n;
    int* arr = new int[n];

    for(int i = 0; i<n; i++){
        arr[i] = i*i;
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    delete[] arr;
};



