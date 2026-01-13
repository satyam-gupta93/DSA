#include <bits/stdc++.h>
using namespace std;

    bool lemonadeChange(vector<int>& arr) {
        int n = arr.size();

        int fiveCount = 0;
        int tenCount = 0;

    

        for(int i = 0; i<n; i++){
            if(arr[i] == 5){
                fiveCount++;
            }else if(arr[i] == 10){
                if(fiveCount==0){
                    return false;
                }
                    tenCount++;
                    fiveCount--;
               
            }else{ // 20
                if(tenCount > 0 && fiveCount > 0){
                    tenCount--;
                    fiveCount--;
                }
                else if(fiveCount >= 3){
                    fiveCount -= 3;
                }
                else{
                    return false;
                }
            }
        }

        return true;

}

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};

    if (lemonadeChange(bills)) {
        cout << "True (Change can be given)" << endl;
    } else {
        cout << "False (Change cannot be given)" << endl;
    }

    return 0;
}
