#include<iostream>
using namespace std;


void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[],int s,int e){

    if(s>e){
        return;
    }
    int minIndex = s;
   
    for(int i = s+1; i <=e; i++){
        if(arr[minIndex]>arr[i]){
            minIndex = i;
        }
    }
    swap(arr[s],arr[minIndex]);

    selectionSort(arr,s+1,e);
    
}

int main(){

    int arr[5] = {5,4,3,2,1};

    print(arr,5);
    selectionSort(arr,0,4);
    print(arr,5);


}