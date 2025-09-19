#include <iostream>
using namespace std;
#include <vector>

int countPrime(int n){

      vector<bool> arr(n, true);;

    arr[0] = arr[1] = false;
    int count = 0;

    for(int i = 0; i<n; i++){

        if(arr[i]){
            count++;

            for(int j = i*i; j<n; j = j + i){
                arr[j] = 0;
            }
        }
    }

    return count;
}

int main() {
   
    int n = 15;

    cout<<"Count:"<<countPrime(10);

    return 0;
}
