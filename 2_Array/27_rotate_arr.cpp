#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;



void printArr(int arr[], int n){
    for( int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArr(int arr[], int start, int end){
    int s = start;
    int e = end;

    while(s<=e){

        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

void rotateArr(int arr[], int k){
      reverseArr(arr,0,4);
      reverseArr(arr,0,k-1);
      reverseArr(arr,k,4);
}


int main(){

    int arr[5] = { 64, 25, 12, 22, 11};

    printArr(arr,5);
    rotateArr(arr,2);
    printArr(arr,5);

}