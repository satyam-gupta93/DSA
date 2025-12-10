#include <bits/stdc++.h>
using namespace std;

// PURE RECURSION 
// Time: O(2^n) 
int frogRec(int i, vector<int>& height) {
    if (i == 0) return 0;

    int left = frogRec(i - 1, height) + abs(height[i] - height[i - 1]);
    int right = INT_MAX;

    if (i > 1)
        right = frogRec(i - 2, height) + abs(height[i] - height[i - 2]);

    return min(left, right);
}



// 2) MEMOIZATION 
// Time: O(n), Space: O(n)
    int frogMemo(int indx, vector<int> &dp,vector<int>& height){
        
        if(indx==0){
            return 0;
        }
        if(dp[indx]!=-1){
            return dp[indx];
        }
        
        int left = frogMemo(indx-1,dp,height) + abs(height[indx] - height[indx-1]);
        int right = INT_MAX;
        
        if(indx>1){
            right = frogMemo(indx-2,dp,height) + abs(height[indx] - height[indx-2]);
        }
        
        return dp[indx] = min(left,right);
    }
    int minCostMemo(vector<int>& height) {
        // Code here
        int n = height.size();
        
        vector<int> dp(n+1,-1);
        
        return frogMemo(n-1,dp,height);
        
    }





// 3) TABULATION 
// Time: O(n), Space: O(n)
    int minCostTab(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n);
        
        dp[0] = 0;
        
        for(int i = 1; i<n; i++){
            int fs = dp[i-1] + abs(height[i]-height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = dp[i-2] + abs(height[i]-height[i-2]);
            }
            
            dp[i] = min(fs,ss);
        }
        
        return dp[n-1];
        
        
        
    }



// 4) SPACE OPTIMIZED DP 
// Time: O(n), Space: O(1)
    int minCostOptimized(vector<int>& height) {
        // Code here
        int n = height.size();
        if(n<=1){
            return 0;
        }
        int prev2 = INT_MAX;
        int prev1 = 0;
        int curr;
        
        for(int i = 1; i<n; i++){
            int fs = prev1 + abs(height[i]-height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = prev2 + abs(height[i]-height[i-2]);
            }
             curr = min(fs,ss);
            prev2 = prev1;
            prev1 = curr;
           
            
        }
        
        return curr;
        
        
        
 }



//MAIN FUNCTION 
int main() {
    vector<int> height = {20, 30, 40, 20};
    

    cout << "Pure Recursion:" << frogRec(height.size() - 1, height) << endl;
    cout << "Memoization:" << minCostMemo(height) << endl;
    cout << "Tabulation:" << minCostTab(height) << endl;
    cout << "Space Optimized:" << minCostOptimized(height) << endl;

    return 0;
}
