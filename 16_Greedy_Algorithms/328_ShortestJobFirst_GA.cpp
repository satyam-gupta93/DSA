#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& bt) {
      
        sort(bt.begin(),bt.end());
        
        int n = bt.size();
        
        int time = 0;
        
        int sum = 0;
        
        for(int i = 0; i<n-1; i++){
            time = time + bt[i];
            sum = sum + time;
        }
        

        
        return sum/n;
}

int main() {
    vector<int> burstTime = {4, 3, 7, 1, 2};

    cout << "Average Waiting Time:"<< solve(burstTime) << endl;

    return 0;
}
