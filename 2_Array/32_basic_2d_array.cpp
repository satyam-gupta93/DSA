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

int main(){
    int arr[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
    printArr(arr, 3);
}
