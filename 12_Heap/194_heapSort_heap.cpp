#include<iostream>
#include<queue>
using namespace std;


void printArray(int arr[], int n) {
    for (int i = 0; i <n; i++) {
     cout << arr[i] << " ";
    }
    cout<<endl;
}

void heapify(int arr[],int n,int i){
    int large = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left] > arr[large] ){
        large = left;
    }
    if(right<n && arr[right] > arr[large]){
        large = right;
    }

    if(large!=i){
        swap(arr[large],arr[i]);
        heapify(arr,n,large);
    }
}


void heapSort(int arr[],int n){

    for(int i = n/2-1; i>=0; i--){
        heapify(arr,n,i);
    }

    for(int i = n-1; i>0; i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }


    // TC - O(nlog(n))
}

int main(){
    // 0 - index based
    int arr[5] = {54,53,55,52,50};
    int n = 5;

    cout<<"Original Array:";
    printArray(arr,n);
    
    cout<<"Heap Sort:";
    heapSort(arr,n);
    
   
    printArray(arr,n);



}