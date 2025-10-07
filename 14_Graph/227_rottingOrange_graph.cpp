#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        
     int n = grid.size();
     int m = grid[0].size();
    
      // push rotten in queue and count no of fresh
     queue<pair<pair<int,int>,int>> q;
     int fresh = 0;
     for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
            }else if(grid[i][j]==1){
                fresh++;
            }
        }
     }

    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};
    int time = 0;

    while(!q.empty()){

        auto front = q.front();
        q.pop();

        int x = front.first.first;
        int y = front.first.second;
        int t = front.second;

        time = max(t,time);

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if( nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == 1){
                grid[nx][ny] = 2;
                fresh--;
                q.push({{nx,ny},t+1});
            }
        }
    }

    if(fresh){
        return -1;
    }

    return time;
}

// Simple main function
int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << "Minimum minutes to rot all oranges: " << orangesRotting(grid) << endl;
    return 0;
}
