#include<iostream>
#include<queue>
using namespace std;


int kSmallest(int arr[],int n,int k){

    priority_queue<int> pq;

    for(int i = 0; i<n; i++){
        pq.push(arr[i]);

        if(pq.size()>k){
            pq.pop();
        }
    }

    return pq.top();

}

int kLargest(int arr[],int n,int k){


    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }

        return pq.top();
    }



}

int main(){

     int arr[5] = {54,53,55,52,50};

    
     int Ksmall = kSmallest(arr,5,2);
     int kLarge = kLargest(arr,5,2);


     cout<<"K Smallest:"<<Ksmall<<endl;
     cout<<"K Largest:"<<kLarge<<endl;

     


}