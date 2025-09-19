#include<iostream>
using namespace std;

void printArray(int arr[],int n){ 
    for(int i=0 ; i<n; i++){
        cout<<"Element "<<i+1<<" is:"<<arr[i]<<endl;
    }
}

void  reverseArray(int arr[],int size){
    // int temp[100];

    // for(int i=0 ; i<size/2 ; i++){
    //         temp[i] = arr[i];
    //         arr[i] = arr[size-i-1];
    //         arr[size-i-1] = temp[i];

    // }

    int start = 0;
    int end = size - 1;

    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

   
}

int main(){
    int arr[8]={2,1,5,4,3,10,5,8};
    
    reverseArray(arr,8);
    printArray(arr,8);


 

}