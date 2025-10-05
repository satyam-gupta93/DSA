#include <bits/stdc++.h>
using namespace std;

// Helper dfs function
void dfs(vector<vector<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int node) {

    ans.push_back(node);
    visited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(adj,visited,ans,i);
        }
    }

    
}

// Function to return DFS Traversal
vector<int> dfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> ans;
    unordered_map<int,bool> visited;

    // For all components
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(adj, visited, ans, i);
        }
    }

    return ans;
}

// Driver code to test
int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    vector<pair<int, int>> edges = {
        {0,1}, {0,4}, {1,2}, {1,3}, {4,3}
    };

    for(auto e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    vector<int> result = dfsTraversal(n, adj);

    cout << "DFS Traversal: ";
    for(auto x : result) cout << x << " ";
    cout << endl;

    return 0;
}
