#include <bits/stdc++.h>
using namespace std;

// solution with dfs
void dfs(vector<vector<int>>& image,int x, int y, int color,int initial,int n,int m){

    if(x<0 || y<0 || x>=n || y>=m || image[x][y]!=initial){
        return;
    }

    image[x][y] = color;

    dfs(image,x-1,y,color,initial,n,m); // up
    dfs(image,x,y+1,color,initial,n,m); // right
    dfs(image,x+1,y,color,initial,n,m); // down
    dfs(image,x,y-1,color,initial,n,m); // left
     
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(color == image[sr][sc]){
            return image;
        }
        int n = image.size();
        int m = image[0].size();

        int initial = image[sr][sc];

        // dfs solution
        dfs(image,sr,sc,color,initial,n,m);


        // bfs solution
        
        // queue<pair<int,int>> q;
        // q.push({sr,sc});

        // vector<int> dx = {-1,0,1,0};
        // vector<int> dy = {0,1,0,-1};


        // while(!q.empty()){
        //     auto front = q.front();
        //     q.pop();
        //     int x = front.first;
        //     int y = front.second;

        //     image[x][y] = color;

        //     for(int i = 0; i<4; i++){
        //          int nx = x + dx[i];
        //          int ny = y + dy[i];

        //          if(nx>=0 && ny>=0 && nx<n && ny<m && image[nx][ny]== initial){
        //                 image[nx][ny] = color;
        //                 q.push({nx,ny});
        //          }
        //     }
        // }

        return image;
    }


int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, color = 2;

   
    vector<vector<int>> result = floodFill(image, sr, sc, color);

    for (auto row : result) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
