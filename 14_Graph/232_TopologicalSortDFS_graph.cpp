#include <bits/stdc++.h>
using namespace std;
    
    void topoSortDFS(int node, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj, stack<int> &s){
        
        visited[node] = true;
        
        
        for(auto i : adj[node]){
            if(!visited[i]){
                topoSortDFS(i,visited,adj,s);
            }
        }
        
        s.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> ans;
        // preapre adj list
        unordered_map<int,list<int>> adj;
        for(int i = 0; i<edges.size(); i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        // visited map
        unordered_map<int,bool> visited;
        stack<int> s;
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                topoSortDFS(i,visited,adj,s);
            }
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }


    int main() {
    // Example graph: 6 nodes (0 to 5)
    // Edges represent u -> v
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    int V = 6; // number of vertices

    vector<int> topo = topoSort(V, edges);

    cout << "Topological Sort Order: ";
    for (int node : topo){
          cout << node << " ";
    }
      cout << endl;

    return 0;
}