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

void wavePrint(int arr[][3],int nRows, int mCols){
    for(int i  = 0; i < mCols; i++){

        if( i % 2 == 0){
            for(int j = 0; j < nRows; j++){
            cout<<arr[j][i]<<" ";
         }   
        }else{
            for(int j = nRows-1; j>=0; j--){
            cout<<arr[j][i]<<" ";
         }   
        }

      

       
    } 
}

int main(){
    int arr[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
    printArr(arr, 3);
    cout<<endl<<"Wave Print"<<endl;
    wavePrint(arr,3,3);

}
