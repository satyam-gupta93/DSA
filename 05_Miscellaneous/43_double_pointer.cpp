#include<iostream>
using namespace std;


void update(int **p){
   // p = p + 1; no change
     //*p  = *p + 1; change in a address
     **p = **p + 1; //change in a value
}


int main(){

    int a = 5;
    int *ptr = &a;
  
    int** ptr1 = &ptr;

    // cout<<"1st:"<<a<<endl;
    // cout<<"2nd:"<<*ptr<<endl;
    // cout<<"3rd:"<<**ptr1<<endl;


    // cout<<"1st:"<<&a<<endl;
    // cout<<"2nd:"<<ptr<<endl;
    // cout<<"3rd:"<<*ptr1<<endl;

    // cout<<"1st:"<<&ptr<<endl;
    // cout<<"2nd:"<<ptr1<<endl;



    // cout<<"1st:"<<&ptr1<<endl;


   

     cout<<"1st:"<<a<<endl;
    cout<<"2nd:"<<ptr<<endl;
     cout<<"3rd:"<<ptr1<<endl;

      update(ptr1);

    
     cout<<"1st:"<<a<<endl;
    cout<<"2nd:"<<ptr<<endl;
     cout<<"3rd:"<<ptr1<<endl;

}