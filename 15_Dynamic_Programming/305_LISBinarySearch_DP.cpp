#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> temp;
        temp.push_back(arr[0]);
        
        for(int i = 0; i<n; i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
            }else{
                int indx = lower_bound(temp.begin(),temp.end(),arr[i]) -  temp.begin();
                temp[indx] = arr[i];
            }
        }
        
        return temp.size();
}

int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Lenght of Longest Commmon Sequence:"<< LIS(nums) << endl;

    

    return 0;
}
