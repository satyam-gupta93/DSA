#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int balance = 0;
        int defi = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            balance += (gas[i] - cost[i]);
            if (balance < 0) {
                defi += balance;
                start = i + 1;
                balance = 0;
            }
        }
        if(defi+balance>=0){
            return start;
        }else{
            return -1;
        }
    }
};

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    
    Solution obj;
    int startStation = obj.canCompleteCircuit(gas, cost);
    
    if (startStation != -1)
        cout << "Start at station index: " << startStation << endl;
    else
        cout << "No possible start station" << endl;
    
    return 0;
}
