#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        
        // prepare adj list
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i = 0; i<m; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        //dist
        vector<int> dist(n+1,INT_MAX);
        dist[1] = 0;
        
        // parent
        vector<int> parent(n+1);
        for(int i = 1; i<n+1; i++){
            parent[i] = i;
        }
        
        // queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        
        
        while(!pq.empty()){
            
           int distNode= pq.top().first;
           int topNode = pq.top().second;
           pq.pop();
           
           
           for(auto nbr: adj[topNode] ) {
               
               int nbrNode = nbr.first;
               int nbrDist = nbr.second;
               
               if( distNode + nbrDist < dist[nbrNode] ){
                   
                   dist[nbrNode] = distNode + nbrDist;
                   pq.push({ dist[nbrNode], nbrNode });
                   
                   parent[nbrNode] = topNode;
               }
           }
        }
        
        if( dist[n] == INT_MAX ){
            return {-1};
        }
        
        int node = n;
        vector<int> path;
        
        while( parent[node] != node ){
            
            path.push_back(node);
            node = parent[node];
        }
        
        path.push_back(1);
        
        reverse(path.begin(),path.end());
        
   
    
        return path;
           
}

int main() {
    
    int n = 5;  // number of nodes
    int m = 6;  // number of edges

    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };

    vector<int> ans = shortestPath(n, m, edges);

    if (ans.size() == 1 && ans[0] == -1) {
        cout << "No path exists from 1 to " << n << endl;
    } else {
        cout << "Shortest path from 1 to " << n << " is: ";
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}