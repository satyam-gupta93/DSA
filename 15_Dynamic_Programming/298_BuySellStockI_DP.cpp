#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;

        for(int i =1; i<prices.size(); i++){
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit,cost);
            mini = min(mini,prices[i]);
        }

        return maxProfit;

}

int main(){
    vector<int> prices = {7,1,5,3,6,4};

    cout<<"Max Profit:"<<maxProfit(prices);
}