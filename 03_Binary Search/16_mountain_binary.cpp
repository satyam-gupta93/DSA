#include<iostream>
using namespace std;


int peakElement(int arr[], int size){

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<end){
       
        if(arr[mid]<arr[mid+1]){
            start = mid + 1;
        }else{
            end = mid;
        }
        mid = start + (end-start)/2;

    }
    return start;
}


int main(){

    int oddArr[5] = {1,2,3,2,1};
    int evenArr[6] = {1,2,3,4,5,6};

    int arr[4] = {0,10,5,2};
    cout<<peakElement(arr,4);
    


}