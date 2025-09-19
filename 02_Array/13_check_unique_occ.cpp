#include<iostream>
using namespace std;

void printArray(int arr[],int n){ 
    for(int i=0 ; i<n; i++){
        cout<<"Element "<<i+1<<" is:"<<arr[i]<<endl;
    }
}

bool  checkUniqueOccurence(int arr[] , int size){

      int freq[2001] = {0};

     // calculating frequency
     for(int i=0; i<size ; i++){
        int index = arr[i]+1000;
        freq[index]++;
     } 

     int used[1001] = {0};
    for(int i=0 ; i<2001 ; i++){
        if(freq[i]>0){
            int count = freq[i];
            if(used[count]==1){
                return false;
            }
            used[count]= 1;
        }
    }

    return true;
}

int main(){
    int arr[6]={1,2,2,1,1,3};
    
    if(checkUniqueOccurence(arr,6)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    printArray(arr,5);


 

}