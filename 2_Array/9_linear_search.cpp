#include<iostream>
using namespace std;

void printArray(int arr[],int n){ 
    for(int i=0 ; i<15 ; i++){
        cout<<"Element "<<i+1<<" is:"<<arr[i]<<endl;
    }
}
bool search(int arr[], int size , int key){
    for(int j = 0; j<size; j++){
        if( arr[j]==key){
            return true;
            break;
        }
    }
    return false;
}
int main(){
    int arr[5]={2,1,5,4,3};
    
    if(search(arr,5,6)){
        cout<<"Found!";
    }else{
        cout<<"Not found";
    }
    

}