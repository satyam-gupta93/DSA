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


int maxRowSum(int arr[][3], int n){



    int maxi = INT8_MIN;
    int sum = 0;
    int indx = -1;

    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n; j++){
            sum = sum + arr[i][j];
            
        }
        cout<<"Sum:"<<sum;
        if(maxi<sum){
            maxi = sum;
            indx = i;
        }
    }
   return indx;
}

int main(){
    int arr[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
    printArr(arr, 3);

    cout<<"MAX sum in rpow indxis "<<maxRowSum(arr, 3);

}
