#include<iostream>
using namespace std;

void printArray(int arr[],int n){ 
    for(int i=0 ; i<n; i++){
        cout<<"Element "<<i+1<<" is:"<<arr[i]<<endl;
    }
}

void  alternateSwap(int arr[],int size){
    
    int start = 0;
    int end = 1;

    while(end<=size){
        swap(arr[start],arr[end]);
        start = start +2;
        end = end+2;
    }
   
}

int main(){
    int arr[8]={2,1,5,4,3,10,5,8};
    
    alternateSwap(arr,8);
    printArray(arr,8);


 

}