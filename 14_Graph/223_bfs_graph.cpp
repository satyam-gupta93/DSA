#include <bits/stdc++.h>
using namespace std;

// Helper BFS function
void bfs(vector<vector<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int node) {

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto i : adj[frontNode]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

// Function to return BFS Traversal
vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> ans;
    unordered_map<int,bool> visited;

    // For all components
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bfs(adj, visited, ans, i);
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

    vector<int> result = bfsTraversal(n, adj);

    cout << "BFS Traversal: ";
    for(auto x : result) cout << x << " ";
    cout << endl;

    return 0;
}
