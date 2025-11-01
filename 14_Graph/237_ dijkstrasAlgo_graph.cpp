#include <bits/stdc++.h>
using namespace std;

// using set
vector<int> dijkstraSet(int V, vector<vector<int>> &edges, int src) {

    // preapare adj list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i = 0; i<edges.size(); i++){

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // dist vector
    vector<int> dist(V,INT_MAX);
    // set for storing min dist 
    set<pair<int,int>> st;
    st.insert({0,src});
    dist[src] = 0;


    while(!st.empty()){
        auto front = *(st.begin());
        int topNode = front.second;
        int nodeDist = front.first;

        st.erase(st.begin());

        for(auto nbr : adj[topNode]){
            
            if( nodeDist + nbr.second  < dist[nbr.first]){

                
                if(dist[nbr.first]!=INT_MAX){
                    st.erase({dist[nbr.first],nbr.first});
                }

                dist[nbr.first] = nodeDist + nbr.second;
                st.insert({dist[nbr.first],nbr.first});
            }
        }
    }

    return dist;
    
}

// using priority_queue(min Heap) 
vector<int> dijkstra_pq(int V, vector<vector<int>> &edges, int src) {

    // preapare adj list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i = 0; i<edges.size(); i++){

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // dist vector
    vector<int> dist(V,INT_MAX);

    // prioritry_queue
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    // pushing source node to queueu and dist to src to that node will be zero 
    pq.push({0,src});
    dist[src] = 0;

    while(!pq.empty()){

        int nodeDist = pq.top().first;
        int top = pq.top().second;
        pq.pop();

        if(nodeDist > dist[top]){
            continue;
        }

        // is small dist found in nbr
        for(auto i : adj[top]){
            int nbr = i.first;
            int nbrDist = i.second;
            if( nodeDist + nbrDist < dist[nbr]){
                dist[nbr] = nodeDist + nbrDist;

                pq.push({dist[nbr],nbr});
            }
        }
        



    }

    return dist;
    
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}
    };

    int src = 0;

    // set
    vector<int> result = dijkstraSet(V, edges, src);
    cout << "Shortest distances from source by set" << src << ":"<<endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << result[i] << endl;
    }

    //priority_queue 
    vector<int> result1 = dijkstra_pq(V, edges, src);
    cout << "Shortest distances from source priority queue" << src << ":"<<endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << result1[i] << endl;
    }

    return 0;
}