#include<iostream>
using namespace std;


int firstOccurence(int arr[], int size, int key){

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(arr[mid]==key){
             ans = mid;
             end = mid-1;
        }
        if(key>arr[mid]){

            start = mid +1;

        }
        if(key<arr[mid]){
            end = mid - 1;
        }

        mid = start + (end-start)/2;

    }
    return ans;
}

int lastOccurence(int arr[], int size, int key){

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(arr[mid]==key){
             ans = mid;
             start = mid+1;
        }
        if(key>arr[mid]){

            start = mid +1;

        }
        if(key<arr[mid]){
            end = mid - 1;
        }

        mid = start + (end-start)/2;

    }
    return ans;
}

int main(){

    int oddArr[9] = {1,2,4,4,4,4,4,4,5};
    int evenArr[6] = {1,2,3,4,5,6};

  
    cout<<"First occurrence of element at index:"<<firstOccurence(oddArr,9,4)<<endl;
    cout<<"Last occurrence of element at index:"<<lastOccurence(oddArr,9,4);
  


}