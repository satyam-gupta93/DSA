#include<iostream>
using namespace std;

void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int getPivot(int arr[],int s,int e){
    int pivot = arr[e];

    int i = s - 1;

    for(int j = s; j<e; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[e]);

    return i + 1;

}

void quickSort(int arr[],int s, int e){

    if(s>=e){
        return ;
    }

    int pi = getPivot( arr,s,e);

    quickSort(arr,s,pi-1);
    quickSort(arr,pi+1,e);


}


int main(){


    int arr[5] = {5,4,3,2,1};
    print(arr,5);
    quickSort(arr,0,4);
    print(arr,5);
 
  


}