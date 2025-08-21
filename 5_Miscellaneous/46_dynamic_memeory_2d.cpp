#include<iostream>
using namespace std;

int main(){

    int row,col;
    cout<<"Enter row and column:";
    cin>>row>>col;

    // Allocate memory for row pointers
    int** arr = new int *[row]; 

    // Allocate memory for each row
    for(int i = 0; i < row; i++){
        arr[i] = new int[col];
    }

    //input
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            arr[i][j] = i*j;
        }
    }

    //output
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    // dellocatre memory
    for(int i = 0; i<row; i++){
        delete[] arr[i];
    }
    delete[] arr;
};



