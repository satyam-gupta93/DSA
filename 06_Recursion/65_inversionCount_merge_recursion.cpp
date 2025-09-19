#include<iostream>
using namespace std;

void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int mergeCount(int arr[], int s, int e){

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    for(int i = 0; i < len1; i++){
        left[i] = arr[s+i];
    }
    for(int j = 0; j < len2; j++){
        right[j] = arr[mid + 1 +j];
    }

    int i = 0;
    int j = 0;
    int k = s;
    int count = 0;
    while(i<len1 && j<len2){
        if(left[i]<right[j]){
            arr[k++] = left[i++];
        }else{
            count = count + (len1-i);
            arr[k++] = right[j++];
        }
    }
    while(i<len1){
        arr[k++] = left[i++];
    }
    while(j<len2){
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;

    return count;
}

int mergeSortCount(int arr[],int s,int e){

    int inverseCount = 0;
    if(s>=e){
        return 0;
    }
    int mid = (s+e)/2;

    inverseCount = inverseCount + mergeSortCount(arr,s,mid);
    inverseCount = inverseCount + mergeSortCount(arr,mid+1,e);

    inverseCount = inverseCount + mergeCount(arr,s,e);

    return inverseCount;
}

int main(){


    int arr[5] = {5,4,3,2,1};
    print(arr,5);
    int count = mergeSortCount(arr,0,4);
    // print(arr,5);
     cout << "Inversion count: " << count << endl;


}