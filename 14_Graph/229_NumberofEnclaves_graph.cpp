#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& g,int i,int j,int n, int m){
        
        if( i<0 || j<0 || i>=n || j>=m || g[i][j]!=1){
            return;
        }

        g[i][j] = -1;


        dfs(g,i-1,j,n,m);
        dfs(g,i,j+1,n,m);
        dfs(g,i+1,j,n,m);
        dfs(g,i,j-1,n,m);


    }
    int numEnclaves(vector<vector<int>>& g) {
        
        int n = g.size();
        int m = g[0].size();

        for(int i = 0; i<n; i++){
            if(g[i][0] == 1){
                dfs(g,i,0,n,m);
            }
            if(g[i][m-1] == 1){
                dfs(g,i,m-1,n,m);
            }
        }

        for(int j = 0; j<m; j++){
            if(g[0][j] == 1){
                dfs(g,0,j,n,m);
            }
            if(g[n-1][j] == 1){
                dfs(g,n-1,j,n,m);
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(g[i][j] == 1){
                    count++;
                }
                                                
            }
        }

        return count;



    }
int main() {
    // Example input grid
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int result = numEnclaves(grid);
    cout << "Number of enclaves: " << result << endl;

    return 0;
}