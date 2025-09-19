#include<iostream>
using namespace std;

void printArray(int arr[],int n){ 
    for(int i=0 ; i<15 ; i++){
        cout<<"Element "<<i+1<<" is:"<<arr[i]<<endl;
    }
}

int main(){
    int arr[5]={2,1,5,4,3};
    int mini = arr[0];
    int max = arr[0];
    for (int i = 0 ; i<5;i++){
         
        if(mini>arr[i]){
            mini = arr[i];
        }

        if(max<arr[i]){
            max = arr[i];
        }
    }
    cout<<"Min in arr is: " <<mini<<endl;
    cout<<"Max in arr is: " <<max<<endl;
  

}