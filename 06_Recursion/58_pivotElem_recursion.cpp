#include<iostream>
using namespace std;

int pivotEle(int *arr, int start, int end){

    if(start>=end){
        return start;
    }
    int mid = (start+(end))/2;

    if(arr[mid]>arr[start]){
        return pivotEle(arr,mid + 1,end);
    }else{
        return pivotEle(arr,start,mid);
    }
    
}



int main(){

    int arr[4] = {4,1,2,3};

    int  ans = pivotEle(arr,0,3);
    cout<<ans;
}