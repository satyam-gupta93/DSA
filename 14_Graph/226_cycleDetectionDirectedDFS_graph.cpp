
#include <bits/stdc++.h>
using namespace std;

//solve by  Helper BFS function

// solve by dfs
    bool dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,int node){
        
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto i : adj[node]){
            
            if(!visited[i]){
                bool ans = dfs(adj,visited,dfsVisited,i);
                if(ans){
                    return true;
                }
            }else if(dfsVisited[i]){
                return true;
            }
        }
        
        dfsVisited[node] = false;
        
        return false;
        
    }

// Function to return detect Traversal
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        // predpare adj list 
        unordered_map<int,list<int>> adj;
        for(int i = 0; i<edges.size(); i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;
        for(int i = 0; i<V; i++){
        if(!visited[i]){
                bool ans = dfs(adj,visited,dfsVisited,i);
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
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},  // forms a cycle: 0 → 1 → 2 → 0
        {3, 4}   // no cycle in this component
    };


    bool ans = isCyclic(n, edges);

    cout << "Check Cycle: "<<ans;
    
    cout << endl;

    return 0;
}
