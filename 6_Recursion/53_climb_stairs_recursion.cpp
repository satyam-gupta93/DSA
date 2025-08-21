
#include<iostream>
using namespace std;

int countDistinctWays(int nStairs) {
    //  Write your code here.
    if(nStairs<0){
        return 0;
    }
    if(nStairs==0){
        return 1;
    }
    return countDistinctWays(nStairs-2) + countDistinctWays(nStairs-1);
}


int main(){

    int n = 3;
    cout<<"ANS:"<<countDistinctWays(n);
    
}

