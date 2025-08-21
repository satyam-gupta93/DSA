#include<iostream>
using namespace std;

int pivotElement(int arr[], int size){

    int s = 0;
    int e = size - 1;

    while(s<e){

        int mid = s + (e-s)/2;
        
        if(arr[mid]>=arr[0]){
            s = mid + 1;
        }else{
            e = mid;
        }
    }

    return s;


}



int main(){

    int oddArr[5] = {1,2,3,2,1};
    int evenArr[6] = {1,2,3,4,5,6};

    int arr[5] = {3,8,10,17,1};
   
    cout<<"Pivot element is at index: "<<pivotElement(arr,5);

}