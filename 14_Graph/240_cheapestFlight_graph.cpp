#include <bits/stdc++.h>
using namespace std;

// Dijkstra doesn't work here because it only optimizes cost and ignores the number of stops.
// A path with lower cost but too many stops should be rejected, while a slightly more expensive
// path with fewer stops may be valid. So plain Dijkstra can  states incorrectly.


int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
                // prepare adj list 
        unordered_map<int,list<pair<int,int>>> adj;

        for(int i = 0; i<flights.size(); i++){

            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v,w});
        }

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        queue<vector<int>> q;
        q.push({0,src,0});

        while(!q.empty()){

            auto front = q.front();
            q.pop();
            
            int stop = front[0];
            int node = front[1];
            int cost = front[2];

            if(stop > k){
                continue;
            }

            for(auto nbr : adj[node]){
                int nbrNode = nbr.first;
                int nbrCost = nbr.second;

                if( cost + nbrCost < dist[nbrNode] && stop<=k){
                    dist[nbrNode] = cost + nbrCost;
                    q.push({stop+1,nbrNode,dist[nbrNode]});
                }
            }
        }

        if(dist[dst] == INT_MAX){
            return -1;
        }

        return dist[dst];

}

int main() {

    int n = 4;  // number of cities
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };
    int src = 0, dst = 3, k = 1;

    int result = findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest Price from " << src << " to " << dst << " with at most " << k 
         << " stops: " << result << endl;

    return 0;
}