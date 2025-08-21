#include<iostream>
using namespace std;

void printArray(int arr[],int n){ 
    for(int i=0 ; i<15 ; i++){
        cout<<"Element "<<i+1<<" is:"<<arr[i]<<endl;
    }
}

int main(){
    int arr1[15];

    fill_n(arr1,15,1); // for fill all 15 element with 1

    cout<<"Size:"<<(sizeof(arr1)/sizeof(int))<<endl;

    printArray(arr1,15);

}