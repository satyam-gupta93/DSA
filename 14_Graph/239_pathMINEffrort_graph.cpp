#include <bits/stdc++.h>
using namespace std;


    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});

        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};

        while(!pq.empty()){

            auto top = pq.top();
            pq.pop();

            int effort = top[0];
            int x = top[1];
            int y = top[2];

            if( x == n-1 && y == m-1 ){
                return effort;
            }

            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int neweffort = max(effort,abs(heights[x][y]-heights[nx][ny]));

                    if( neweffort < dist[nx][ny] ){
                        dist[nx][ny] =  neweffort;
                        pq.push({neweffort,nx,ny});
                    }
                }
            }
        }

        return 0;
 }

int main() {

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << "Minimum Effort Path: " << minimumEffortPath(heights) << endl;

    return 0;
}