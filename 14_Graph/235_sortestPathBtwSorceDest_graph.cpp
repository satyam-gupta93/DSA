#include <bits/stdc++.h>
using namespace std;


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	
	unordered_map<int,list<int>> adj;
	for(int i = 0; i<edges.size(); i++){
		
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int> q;
	
	q.push(s);
	parent[s] = -1;
	visited[s] = 1;

	while(!q.empty()){

		int front = q.front();
		q.pop();

		for(auto i : adj[front]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	vector<int> ans;
	int currNode = t;
	ans.push_back(currNode);

	while(currNode!=s){
		currNode = parent[currNode];
		ans.push_back(currNode);
	}

	reverse(ans.begin(),ans.end());


	return ans;




	
	
}

int main() {
    int n = 9, m = 10;
    vector<pair<int,int>> edges = {
        {0,1}, {0,3}, {1,2}, {3,4}, {4,5}, {2,6},
        {5,6}, {6,7}, {6,8}, {7,8}
    };

    int s = 0, t = 8;

    vector<int> path = shortestPath(edges, n, m, s, t);

    cout << "Shortest path from " << s << " to " << t << ": ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}