#include<iostream>
using namespace std;

int sumArray(int *arr, int size){

   
    if(size==0){
        return 0;
    }

    return arr[0] + sumArray(arr+1,size-1);
}



int main(){


    int arr[1] = {2};

    int  ans = sumArray(arr,1);
    cout<<"Sum:"<<ans;
}