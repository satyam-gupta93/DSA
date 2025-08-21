#include<iostream>
#include<vector>
using namespace std;

bool isPossible(int arr[], int n, int mid, int k){

    int painterCount = 1;
    int boardCount = 0;

    for(int i = 0; i < n; i++){

        if(arr[i]>mid){
            return false;
        }

        if( arr[i] + boardCount <= mid ){
            boardCount = boardCount + arr[i];
        }else{
            painterCount++;

            if(painterCount>k){
                return false;
            }

            boardCount = arr[i];
        }
    }

    return true;
}

int findTime(int boards[],int n, int k)
{
    
    int s = 0;

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum = sum + boards[i];

    }

    int e = sum;
    int ans = -1;

    while(s<=e){

        int mid = s + (e-s)/2;

        if(isPossible(boards,n,mid,k)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }

    }

    return ans;
}


int main(){

    int arr[4] = {12,34,67,90};
    int painter  = 2;


    cout<<"Result:"<<findTime(arr,4,painter);
    }


