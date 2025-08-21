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

void spiralPrint(int arr[][3],int n, int m){
    

    int count = 0;
    int total = n * m;

    int startRow = 0;   
    int endCol = m-1;
    int endRow = n-1;
    int startCol = 0;

    while(count<total){

        for(int i = startCol; i <= endCol && count < total; i++){
            cout<<arr[startRow][i]<<" ";
            count++;
        }
        startRow++;
        for(int i = startRow; i <=endRow && count < total; i++){
            cout<<arr[i][endCol]<<" ";
            count++;

        };
        endCol--;
        for(int i = endCol; i >= startCol && count < total; i--){
            cout<<arr[endRow][i]<<" ";
            count++;
        };
        endRow--;
        for(int i = endRow; i >= startRow && count < total; i--){
            cout<<arr[i][startCol]<<" ";
            count++;
        };
        startCol++;

    }
}

int main(){
    int arr[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
   printArr(arr, 3);
    cout<<endl<<"Spiral Print"<<endl;
    spiralPrint(arr,3,3);
}
