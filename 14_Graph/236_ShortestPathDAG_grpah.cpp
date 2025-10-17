#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(unordered_map<int,list<pair<int,int>>> &adj,int V){
        
       vector<int> indegree(V,0);
        // find indegree
        for(int i = 0; i<V; i++){
            for(auto j:adj[i]){
                indegree[j.first]++;
            }
        }
        // finding zero indegree
        queue<int> q;
        for(int i = 0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto i : adj[front]){
                indegree[i.first]--;
                if(indegree[i.first]==0){
                    q.push(i.first);
                }
            }
        }
        
        return ans;
    }
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        // prepare adj list
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i = 0; i<E; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            int d = edges[i][2];
            
            adj[u].push_back({v,d});
        }
        
        vector<int> topo  =  topoSort(adj,V);
        
        // distance vector 
         vector<int> dist(V,INT_MAX);
         
         int src = 0;
         dist[src] = 0;
         
         for(auto node:topo){
             if(dist[node]!=INT_MAX){
                 for(auto i:adj[node]){
                     int v = i.first;
                     int w = i.second;
                     
                     if(dist[node] + w <dist[v]){
                         dist[v] = dist[node] + w;
                     }
                 }
             }
         }
         
         for(int i =  0; i<V;i++){
             if(dist[i]==INT_MAX){
                 dist[i] = -1;
             }
         }
         
         return dist;
         
         
        
 }

 int main() {
    int V = 6, E = 7;
    vector<vector<int>> edges = {
        {0,1,2}, {0,4,1}, {4,5,4}, {4,2,2}, {1,2,3}, {2,3,6}, {5,3,1}
    };
    
    vector<int> ans = shortestPath(V, E, edges);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}