#include<iostream>
using namespace std;

void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int s,int e){
    if(s>=e){
        return ;
    }
    for(int i = s; i < e; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,s,e-1);
}

int main(){


    int arr[5] = {5,4,3,2,1};
    print(arr,5);
   bubbleSort(arr,0,4);
    print(arr,5);


}