#include <bits/stdc++.h>
using namespace std;


bool isPallindrom(int i,int j,string s){
       while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
       }
       return true;
    }


/*
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n)
*/
    int solveRec(int i,string s){
        if( i == s.size()){
            return 0;
        }
       
        int mini = INT_MAX;
        
        for(int j = i; j<s.size(); j++){
          
            
            if(isPallindrom(i,j,s)){
                int cost = 1 + solveRec(j+1,s);
                mini = min(mini,cost);
            }
        }
        return mini;
    }

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n^2)
   SC: O(n)
*/
    int solveMemo(int i,string s,vector<int> &dp){
        if( i == s.size()){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }
       
        int mini = INT_MAX;
        
        for(int j = i; j<s.size(); j++){
          
            
            if(isPallindrom(i,j,s)){
                int cost = 1 + solveMemo(j+1,s,dp);
                mini = min(mini,cost);
            }
        }
        return dp[i] =  mini;
    }

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n^2)
   SC: O(n)
*/
int minCutTab(string &s) {

        int n = s.size();
        vector<int> dp(n+1,0);


        for(int i = n-1; i>=0; i--){
            int mini = INT_MAX;
            
            for(int j = i; j<s.size(); j++){
            
                
                if(isPallindrom(i,j,s)){
                    int cost = 1 + dp[j+1];
                    mini = min(mini,cost);
                }
            }
            dp[i] = mini;
        }


        
        return dp[0] - 1;
}


int main() {

    string s = "aab";

    cout << "Recursion:"<< solveRec(0, s) - 1 << endl;

    vector<int> dp(s.size(), -1);
    cout << "Memoization:"<< solveMemo(0, s, dp) - 1 << endl;

    cout << "Tabulation:"<< minCutTab(s) << endl;

    return 0;
}
