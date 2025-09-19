#include<iostream>
using namespace std;


bool isPossible(int arr[], int mid, int n, int m){

    int stdCount = 1;
    int pageSum = 0;

    for(int i = 0; i<n; i++){
        

        if(arr[i]>mid){
            return false;
        }
        if(arr[i] + pageSum <= mid){
            pageSum = pageSum + arr[i];
        }else{
            stdCount++;
            if(stdCount>m){
                return false;
            }
            pageSum = arr[i];
        }
    }

    return true;
}


int findPages(int arr[], int n, int m){

    int s = 0;
    int sum = 0;

    if(m > n) return -1;


    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }

    int e = sum;
    int ans = -1;
    while(s<=e){

        int mid = s + (e-s)/2;
        if(isPossible(arr,mid,n,m)){
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
int student  = 2;


cout<<"Result:"<<findPages(arr,4,student);
    

}