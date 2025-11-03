#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
        
        // preapare adj list 
        int mod = (1e9 + 7);
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i = 0; i<roads.size(); i++){

            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

        }

        vector<long long> dist(n,LLONG_MAX);
        dist[0] = 0;


         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
       
        vector<int> ways(n,0);
        ways[0] = 1;
 
        while(!pq.empty()){

            auto front = pq.top();
            pq.pop();

            long long time = front.first;
            int node = front.second;

            for(auto nbr : adj[node]){
                int nbrNode = nbr.first;
                 long long nbrTime = nbr.second;

                if(time + nbrTime < dist[nbrNode]){
                    dist[nbrNode] = time + nbrTime;
                    ways[nbrNode] = ways[node];
                    pq.push({  dist[nbrNode],nbrNode });
                }else if(dist[nbrNode] == time + nbrTime){
                    ways[nbrNode] =  (ways[nbrNode] + ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;

       


}

int main() {

    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5}
    };

    cout << "Number of shortest paths from node 0 to node " << n - 1 << " = "
         <<countPaths(n, roads) << endl;

    return 0;
}
