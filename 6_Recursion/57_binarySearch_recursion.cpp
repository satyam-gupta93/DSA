#include<iostream>
using namespace std;

bool binarySearch(int *arr, int start, int end,int key){

    if(start>end){
        return false;
    }
    int mid = (start+(end))/2;

    if(arr[mid]==key){
        return true;
    }else if(arr[mid]<key){
        return binarySearch(arr,mid + 1,end,key);
    }else{
        return binarySearch(arr,start,mid - 1,key);
    }
    
}



int main(){

    int arr[5] = {1,2,4,6,8};

    bool  ans = binarySearch(arr,0,4,1);
    cout<<ans;
}