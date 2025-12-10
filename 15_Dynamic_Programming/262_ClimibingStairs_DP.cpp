#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int solve(int indx,vector<int> &dp){
        if(indx<=1){
            return 1;
        }
        if(dp[indx]!=-1){
            return dp[indx];
        }

        return dp[indx] = solve(indx-1,dp) + solve(indx-2,dp);
}
int climbStairsMemo(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
}

//  SPACE OPTIMIZED DP 
int climbStairsDP(int n) {
        
        if(n<=1){
            return 1;
        }
        int prev2 = 1;
        int prev1 = 1;

        int curr;

        for(int i = 2; i<=n; i++){
            curr = prev2+ prev1;
            prev2 = prev1;
            prev1  = curr;
        }

        return curr;
}



//  MAIN FUNCTION 
int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    cout << "\nWays using Memoization: " << climbStairsMemo(n) << endl;
    cout << "Ways using Space Optimized DP: " << climbStairsDP(n) << endl;

    return 0;
}
