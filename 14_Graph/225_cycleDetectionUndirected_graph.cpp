#include <bits/stdc++.h>
using namespace std;

//solve by  Helper BFS function
bool bfs(vector<vector<int>> &adj, unordered_map<int,bool> &visited, int node) {

    unordered_map<int,int> parent;
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    parent[node] = -1;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
       
        for(auto i : adj[frontNode]) {
            if(visited[i]==true && parent[frontNode] != i){
                return true;
            }
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
                 parent[i] = frontNode;
            }
        }
    }
    return false;
}

// solve by dfs
bool dfs(vector<vector<int>> &adj, unordered_map<int,bool> &visited, int node,int parent){

    visited[node] = true;

    for( auto i:adj[node] ){
        if(!visited[i]){
            bool ans = dfs(adj,visited,i,node);
            if(ans){
                return true;
            }
        }else if(parent!=i){
            return true;
        }
    }
    return false;
}

// Function to return detect Traversal
bool detectCycle(int n, vector<vector<int>> &adj) {
  
    unordered_map<int,bool> visited;

    // For all components
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {

            // solve bfs
            //bool ans = bfs(adj, visited, i);

            // solve dfs
            bool  ans  = dfs(adj,visited,i,-1);

            if(ans){
                return true;
            }
        }
    }

    return false;
}

// Driver code to test
int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},  // forms a cycle: 0-1-2-0
        {3, 4}   // separate component, no cycle
    };


    for(auto e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    bool ans = detectCycle(n, adj);

    cout << "Check Cycle: "<<ans;
    
    cout << endl;

    return 0;
}
