#include<iostream>
#include<math.h>
using namespace std;

void printArr(int arr[], int n){
    for( int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int n){

    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i; j < n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main(){

    int arr[5] = { 64, 25, 12, 22, 11};

    printArr(arr,5);
    selectionSort(arr,5);
    printArr(arr,5);

}