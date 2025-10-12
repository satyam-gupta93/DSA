#include <bits/stdc++.h>
using namespace std;
    
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
        
       // finding indegree
       vector<int> indegree(V,0);
        for(int i = 0; i<V; i++){
             for(auto j:adj[i]){
                 indegree[j]++;
             }
         }

         // finding zero indegree to push in queue
         queue<int> q;
         for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
         }

         // bfs
         while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto i : adj[front]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
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