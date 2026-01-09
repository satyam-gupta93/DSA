#include <bits/stdc++.h>
using namespace std;

vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> ans;
        vector<int> hash(n);
        vector<int> dp(n,1);
        
        int maxi =1;
        int lastIndex = 0;
        for(int i = 0; i<n ; i++){
            hash[i] = i;
            for(int prev = 0; prev<i; prev++){
                if(arr[prev] < arr[i] && dp[i] < 1 + dp[prev]){
                    dp[i] = max(dp[i],1 + dp[prev]);
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        ans.push_back(arr[lastIndex]);
        
        while( hash[lastIndex] != lastIndex ){
            lastIndex = hash[lastIndex];
            ans.push_back(arr[lastIndex]);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
}

int main(){
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    
    vector<int> ans = getLIS(arr);
    cout<<"LIS:";
    for(int i =0; i<ans.size(); i++){
        cout<< ans[i] << " ";
    }
}
