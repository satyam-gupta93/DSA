#include <bits/stdc++.h>
using namespace std;

class DisjoinSet{
  vector<int> rank,parent,size;
  
  public:
    DisjoinSet(int n){
        rank.resize(n,0);
        parent.resize(n);
         size.resize(n , 1);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }
    
    int findUP(int node){
        if(parent[node]==node){
            return node;
        }
        
        return parent[node] = findUP(parent[node]);
    }
    
    void UnionByRank(int u,int v){
      
      int pu = findUP(u);
      int pv = findUP(v);
      
      if( pu == pv ){
          return;
      }
      
      if(rank[pu] < rank[pv] ){
           parent[pu] = pv;
      }else if(rank[pu] > rank[pv]){
          parent[pv] = pu;
      }else{
          parent[pv] = pu;
          rank[pu]++;
      }
      
    }
    void UnionBySize(int u, int v) {
        int pu = findUP(u);
        int pv = findUP(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    
};

int makeConnected(int n, vector<vector<int>>& connections) {

        DisjoinSet ds(n);
        if(connections.size() < n -1){
            return -1;
        }
        for(auto edge : connections){
            ds.UnionByRank(edge[0],edge[1]);
        }
        int compo = 0;
        for(int i = 0; i<n; i++){
            if(ds.findUP(i) == i ){
                compo++;
            }
        }

        return compo-1;
    
}

int main() {
    int n = 6; // number of computers
    vector<vector<int>> connections = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 2},
        {1, 3}
    };

    int ans = makeConnected(n, connections);
    cout << ans << endl; 

    return 0;
}