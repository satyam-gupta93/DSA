#include <bits/stdc++.h>
using namespace std;

    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src] = 0;
        
        for(int i = 0; i<V-1; i++){
            for(int j = 0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                
                if( dist[u]!=1e8  && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        //for negative cycle detecton relax one more time 
        for(int j = 0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                
                if( dist[u]!=1e8  && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    return {-1};
                }
        }

        return dist;
     
        
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {1, 3, 2},
        {4, 3, -1},
        {2, 4, 1},
        {1, 2, 1},
        {0, 1, 5}
    };
    int src = 0;

    vector<int> result = bellmanFord(V, edges, src);

    // Print result
    if (result.size() == 1 && result[0] == -1)
        cout << "Graph contains a negative weight cycle" << endl;
    else {
        cout << "Shortest distances from source " << src << ": ";
        for (int d : result) cout << d << " ";
        cout << endl;
    }

    return 0;
}