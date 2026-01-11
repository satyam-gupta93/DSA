#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n) recursion stack
*/
    int solveRec(int i,int j,int isTrue,string &s){
        if(i>j){
            return 0;
        }
        if(i == j){
            if(isTrue){
                return s[i] == 'T';
            }else{
                return s[i] == 'F';
            }
        }
        
        int ways = 0;
        for(int k = i+1; k<=j-1; k = k+=2){
            int lT = solveRec(i,k-1,1,s);
            int lF = solveRec(i,k-1,0,s);
            int rT = solveRec(k+1,j,1,s);
            int rF = solveRec(k+1,j,0,s);
            
            if(s[k] == '&'){
                if(isTrue){
                    ways = ways + lT*rT;
                }else{ // False;
                    ways = ways +  lT * rF + lF * rF + lF*rT;
                }
            }else if(s[k] == '|'){
                if(isTrue){
                    ways = ways +  lT * rF + lT * rT + lF*rT;
                }else{
                    ways = ways + lF*rF;
                }
            }else{
                if(isTrue){
                    ways = ways +  lF * rT + lT*rF;
                }else{
                    ways = ways + lT*rT + lF*rF;
                }
            }
            
        }
        
        return ways;
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n^3)
   SC: O(n^2)
*/
    int solveMemo(int i,int j,int isTrue,string &s,vector<vector<vector<int>>> &dp){
        if(i>j){
            return 0;
        }
        if(i == j){
            if(isTrue){
                return s[i] == 'T';
            }else{
                return s[i] == 'F';
            }
        }
        
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue];
        }
        
        int ways = 0;
        for(int k = i+1; k<=j-1; k = k+=2){
            int lT = solveMemo(i,k-1,1,s,dp);
            int lF = solveMemo(i,k-1,0,s,dp);
            int rT = solveMemo(k+1,j,1,s,dp);
            int rF = solveMemo(k+1,j,0,s,dp);
            
            if(s[k] == '&'){
                if(isTrue){
                    ways = ways + lT*rT;
                }else{ // False;
                    ways = ways +  lT * rF + lF * rF + lF*rT;
                }
            }else if(s[k] == '|'){
                if(isTrue){
                    ways = ways +  lT * rF + lT * rT + lF*rT;
                }else{
                    ways = ways + lF*rF;
                }
            }else{
                if(isTrue){
                    ways = ways +  lF * rT + lT*rF;
                }else{
                    ways = ways + lT*rT + lF*rF;
                }
            }
            
        }
        
        return dp[i][j][isTrue] =  ways;
    }
/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n^3)
   SC: O(n^2)
*/
int countWaysTab(string &s) {

        int n = s.size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int>(2,0)));
        
        

        
        for(int i = n-1;i>=0;i--){
          
            for(int j = i; j<=n-1; j++){
                for(int isTrue = 0; isTrue<=1; isTrue++){
                    if(i>j)continue;
                    if(i==j){
                        if(isTrue)dp[i][j][isTrue]= s[i]=='T';
                        else dp[i][j][isTrue]= s[i]=='F';
                        continue;
                    }
                    int ways = 0;
                    for(int k = i+1; k<=j-1; k+=2){
                        int lT = dp[i][k-1][1];
                        int lF = dp[i][k-1][0];
                        int rT = dp[k+1][j][1];
                        int rF = dp[k+1][j][0];
                        
                        if(s[k] == '&'){
                            if(isTrue){
                                ways = ways + lT*rT;
                            }else{ // False;
                                ways = ways +  lT * rF + lF * rF + lF*rT;
                            }
                        }else if(s[k] == '|'){
                            if(isTrue){
                                ways = ways +  lT * rF + lT * rT + lF*rT;
                            }else{
                                ways = ways + lF*rF;
                            }
                        }else{
                            if(isTrue){
                                ways = ways +  lF * rT + lT*rF;
                            }else{
                                ways = ways + lT*rT + lF*rF;
                            }
                        }
                        
                    }
                    dp[i][j][isTrue] = ways;
                }
        }
        
        
    }
    return dp[0][n-1][1];
}


int main() {

    string s = "T|T&F^T";
    int n = s.size();

    cout << "Recursion:"<< solveRec(0, n - 1, 1, s) << endl;

    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(n, vector<int>(2, -1))
    );
    cout << "Memoization:"<< solveMemo(0, n - 1, 1, s, dp) << endl;

    cout << "Tabulation:"<< countWaysTab(s) << endl;

    return 0;
}
