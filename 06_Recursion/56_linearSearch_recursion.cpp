#include<iostream>
using namespace std;

bool linearSearch(int *arr, int size,int key){

    if(size==0){
        return 0;
    }
    if(arr[0]==key){
        return true;
    }else{
        return linearSearch(arr+1,size-1,key);
    }
    
}



int main(){

    int arr[5] = {2,54,4,6,1};

    bool  ans = linearSearch(arr,5,9);
    cout<<ans;
}