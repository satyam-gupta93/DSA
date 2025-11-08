#include <bits/stdc++.h>
using namespace std;

class DisjoinSet{
  vector<int> rank,parent,size;
  
  public:
    DisjoinSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
         size.resize(n + 1, 1);
        for(int i = 0; i<=n; i++){
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

int spanningTree(int V, vector<vector<int>>& edges) {
       
        vector<pair<int,pair<int,int>>> edge;
        
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            edge.push_back({w,{u,v}});
        }
        
        DisjoinSet ds(V);
        sort(edge.begin(),edge.end());
        
        int sum = 0;
        
        for(auto i:edge){
            int w = i.first;
            int u = i.second.first;
            int v = i.second.second;
            
            if(ds.findUP(u)!=ds.findUP(v)){
                sum += w;
                ds.UnionByRank(u,v);
            }
        }
        
        return sum;
        

        
}


int main() {
    int V = 5; // number of vertices
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 3, 8},
        {1, 2, 3},
        {1, 4, 5},
        {2, 4, 7}
    };

    cout << "Minimum Spanning Tree Weight:" << spanningTree(V, edges) << endl;

    return 0;
}
