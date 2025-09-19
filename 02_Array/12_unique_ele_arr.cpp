#include<iostream>
using namespace std;

void printArray(int arr[],int n){ 
    for(int i=0 ; i<n; i++){
        cout<<"Element "<<i+1<<" is:"<<arr[i]<<endl;
    }
}

int findUnique(int arr[], int size){
    int ans = 0; 
    for(int i=0; i<size ; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
int main(){
    int arr[9]={2,1,2,1,6,6,5,4,5};
    
    cout<<"Unique:"<<findUnique(arr,9)<<endl;
    printArray(arr,5);


 

}