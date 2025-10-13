
#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        // prepare adj list
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
        
        
        // pushing indgree of zero in queue 
        queue<int> q;
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        
        //bfs
        int cnt = 0;
        
        while(!q.empty()){
            
            int front = q.front();
            q.pop();
            
            cnt++;
            
            for(auto i : adj[front]){
                indegree[i]--;
                
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        if(cnt == V){
            return false;
        }else{
            return true;
        }
        
    }
int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 1}
    };

    if (isCyclic(V, edges))
        cout << "Graph contains a cycle " << endl;
    else
        cout << "Graph is acyclic " << endl;

    return 0;
}