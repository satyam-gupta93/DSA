#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i = 0; i<edges.size(); i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            
        }
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        vector<int> vis(V,0);
        
        int sum = 0;
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int node = front.second;
            int wt = front.first;
            
            if( vis[node] == 1 ){
                continue;
            }
            
            vis[node] = 1;
            sum += wt;
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                int edw = it.second;
                
                if(!vis[adjNode]){
                    pq.push({edw,adjNode});
                }
                
            }
        }
        
        return sum;
}


// for getting mst 
// pair<int, vector<pair<int, int>>> spanningTree(int V, vector<vector<int>>& edges) {
//     unordered_map<int, list<pair<int, int>>> adj;
//     for (int i = 0; i < edges.size(); i++) {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         int w = edges[i][2];
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }

//     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
//     pq.push({0, {0, -1}});  // {weight, {node, parent}}

//     vector<int> vis(V, 0);
//     int sum = 0;
//     vector<pair<int, int>> mstEdges;

//     while (!pq.empty()) {
//         auto top = pq.top();
//         pq.pop();

//         int wt = top.first;
//         int node = top.second.first;
//         int parent = top.second.second;

//         if (vis[node]) continue;
//         vis[node] = 1;
//         sum += wt;

//         if (parent != -1) mstEdges.push_back({parent, node});

//         for (auto it : adj[node]) {
//             int adjNode = it.first;
//             int edw = it.second;

//             if (!vis[adjNode]) {
//                 pq.push({edw, {adjNode, node}});
//             }
//         }
//     }

//     return {sum, mstEdges};
// }

int main() {
    // Number of vertices
    int V = 5;

    // Manually defining edges: {u, v, w}
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7}
    };

    int totalWeight = spanningTree(V, edges);
    cout << "Total weight of Minimum Spanning Tree: " << totalWeight << endl;

    return 0;
}
