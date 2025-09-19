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

bool binarySearch(int arr[][3],int n,int m,int key){

    int s = 0;
    int e = (n*m)-1;

    while(s <= e ){

        int mid =  s + (e - s )/2;
        int ele = arr[mid/m][mid%m];   //IMP line 
        if(ele == key){
            return 1;
            break;
        }else if(ele < key){
             s = mid + 1;
        }else{
            e = mid - 1;
        }
           
        
    }

    return 0;
}

int main(){
    int arr[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
    printArr(arr, 3);
    if( binarySearch(arr,3,3,10)){
        cout<<"Element Found!!";
    }else{
        cout<<"Element not Found!";
    }
  
    
  
}
