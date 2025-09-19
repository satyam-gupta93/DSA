#include<iostream>
using namespace std;


void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[],int s,int e){

    if(s>e){
        return;
    }
    int temp = arr[s];
    int j;
    for(j= s - 1; j>=0; j-- ){
        if(arr[j] > temp){
            arr[j+1] = arr[j];
        }else{
            break;
        }
    }
    arr[j+1] = temp;
    insertionSort(arr,s+1,e);
}

int main(){

    int arr[5] = {5,4,3,2,1};

    print(arr,5);
    insertionSort(arr,1,4);
    print(arr,5);


}