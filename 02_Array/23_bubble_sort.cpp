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

    for(int i = 0; i < n-1; i++){
        
        bool swapped = true;
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }

        if(swapped == false){
            break;
        }
        
    }
}

int main(){

    int arr[5] = { 64, 25, 12, 22, 11};

    printArr(arr,5);
    selectionSort(arr,5);
    printArr(arr,5);

}