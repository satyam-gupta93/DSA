#include<iostream>
using namespace std;

void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int *arr,int s,int e){
    
    int mid = (s+e)/2;

    int len1 = mid - s +1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

   
    for(int i = 0; i<len1; i++){
        first[i] = arr[i+s];
    };
    for(int j = 0; j<len2; j++){
        second[j] = arr[mid+1+j];
    };
    int i=0;
	int j=0;
	int k=s;

    while(i<len1 && j<len2){
        if(first[i]<second[j]){
            arr[k++] = first[i++];
        }else{
             arr[k++] = second[j++];
        }
    }

    while(i<len1){
        arr[k++] = first[i++];
    }
    while(j<len2){
        arr[k++] = second[j++];
    }
    
    
    delete[] first;
    delete[] second;
}

void mergeSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }

    int mid = (s + e)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main(){


    int arr[5] = {5,4,3,2,1};
    print(arr,5);
    mergeSort(arr,0,4);
    print(arr,5);


}