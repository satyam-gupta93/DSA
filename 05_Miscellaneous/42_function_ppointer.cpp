#include<iostream>
using namespace std;

void print(int *ptr){

    cout<<"Value:"<<*ptr<<endl;
}

void update(int *ptr){
  
    *ptr = *ptr + 1;
}


int main(){

    int a = 5;
    int *ptr = &a;
  
   // print(ptr);
   cout<<"Before:"<<a;
    update(ptr);
   cout<<"After:"<<a; 
   // print(ptr);


}