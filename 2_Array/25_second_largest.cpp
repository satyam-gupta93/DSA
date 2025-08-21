#include<iostream>
using namespace std;

int secondLargest(int arr[], int n){

    // int first_larg = arr[0];
    // int second_larg = INT8_MIN;

    // for(int i = 0; i < n; i++){
    //     if(arr[i]>first_larg){
    //         first_larg = arr[i];
    //     }
    // }

    // for(int i = 0; i < n; i++){
    //     if(arr[i]>second_larg && arr[i]<first_larg){
    //         second_larg = arr[i];
    //     }
    // }
    // return second_larg;

    int first_larg = INT8_MIN;;
    int second_larg = INT8_MIN;

     for(int i = 0; i < n; i++) {
        if(arr[i] > first_larg) {
            second_larg = first_larg;
            first_larg = arr[i];
        }
        else if(arr[i] > second_larg && arr[i] < first_larg) {
            second_larg = arr[i];
        }
    }

    if (second_larg == INT8_MIN) {
        cout << "No second largest element exists.\n";
        return -1; // or any appropriate value to indicate failure
    }

    return second_larg;
}

int main(){

    int arr[5] = {6,4,3,2,1};
    cout<<"Second Largest:"<<secondLargest(arr,5);
}