#include<iostream>
using namespace std;

void printArr(int arr[][3], int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rotateMat(int arr[][3],int n){
    

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
  

    for(int i = 0; i<n; i++){
        int s = 0;
        int e = n-1;  
        while(s<=e){
            swap(arr[i][s], arr[i][e]);
            s++;
            e--;
        }
    }



    
}

int main(){
    int arr[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
    printArr(arr, 3);
    rotateMat(arr,3);
    printArr(arr, 3);
  
}
