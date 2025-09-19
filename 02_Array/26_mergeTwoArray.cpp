#include<iostream>
using namespace std;


void printArr(int arr[], int n){
    for( int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void mergeSortedArray(int arr1[], int arr2[], int m, int n, int arr3[]){
    int j = 0;
    int k = 0;
    int i = 0;
    while(k<n && j < m){
        
        if(arr1[j] > arr2[k]){
            arr3[i] = arr2[k];
            k++;
        }else if(arr1[j] < arr2[k]){
            arr3[i] = arr1[j];
            j++;
        }

        i++;
    }

    while(j<m){
           arr3[i++] = arr1[j++];
    };
    while(k<n){
        arr3[i++] = arr2[k++];
    }
    // for(int i = 0; i <; i++ ){

    //     if(arr1[j] > arr2[k]){
    //         arr3[i] = arr2[k];
    //         k++;
    //     }else if(arr1[j] < arr2[k]){
    //         arr3[i] = arr1[j];
    //         j++;
    //     }
    // }
}


int main(){

    int arr1[5] = { 3, 5, 7, 9, 11};
    int arr2[3] = { 1, 4, 6};

    int arr3[8] = {0};

    mergeSortedArray(arr1,arr2,5,3,arr3);
    printArr(arr3,8);

   

}