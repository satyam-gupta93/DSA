#include<iostream>
using namespace std;


int binarySearch(int arr[], int size, int key){

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start = mid +1;

        }
        if(key<arr[mid]){
            end = mid - 1;
        }

        mid = start + (end-start)/2;

    }
    return -1;
}

int main(){

    int evenArr[5] = {1,2,3,4,5};
    int oddArr[6] = {1,2,3,4,5,6};

    if(true){
        cout<<"Element Found at index:"<<binarySearch(oddArr,6,7);
    }else{
        cout<<"Element not found";
    }


}