#include<iostream>
using namespace std;


long long int sqrtBinary(int num){

    int s = 0;
    int e = num;
    long long int ans  = -1;
   

    while(s<=e){
        long long int mid = s  + (e-s)/2;
        long long int sqr = mid * mid;

        if(sqr == num){
            return mid;
        }else if(sqr<num){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }

    }

    return ans; 
}



int main(){
 

    cout<<"Square Root:"<<sqrtBinary(36);

}