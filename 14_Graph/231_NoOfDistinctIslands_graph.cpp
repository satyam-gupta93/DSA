#include <bits/stdc++.h>
using namespace std;

void dfs(int x,int y,vector<vector<int>> &grid, vector<vector<int>> &visited,vector<pair<int,int>> &shape,int r0,int c0 ){

    int n = grid.size();
    int m = grid[0].size();

    visited[x][y] = 1;
    shape.push_back({x-r0,y-c0});

    vector<int> dx = { -1, 0, 1 ,0};
    vector<int> dy = {0,1,0,-1};

    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == 1 && !visited[nx][ny]){
            dfs(nx,ny,grid,visited,shape,r0,c0);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid){

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n,vector<int> (m,0));
    set<vector<pair<int,int>>> st;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                vector<pair<int,int>> shape;
                dfs(i,j,grid,visited,shape,i,j);
                st.insert(shape);
            }
        }
    }
    return st.size();
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };
    
    cout << "Number of Distinct Islands:" << countDistinctIslands(grid) << endl; // Output: 1
    return 0;
}