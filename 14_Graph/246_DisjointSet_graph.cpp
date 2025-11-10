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

        if(pu == pv)
            return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    
};

int main() {
    DisjoinSet ds(7);

    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);

    // Check if 3 and 7 belong to the same set
    if (ds.findUP(3) == ds.findUP(7))
        cout << "Same component\n";
    else
        cout << "Different component\n";

    ds.UnionByRank(3, 7);

    if (ds.findUP(3) == ds.findUP(7))
        cout << "Same component\n";
    else
        cout << "Different component\n";

    

    DisjoinSet ds2(7);

    ds2.UnionBySize(1, 2);
    ds2.UnionBySize(2, 3);
    ds2.UnionBySize(4, 5);
    ds2.UnionBySize(6, 7);
    ds2.UnionBySize(5, 6);

    if (ds2.findUP(3) == ds2.findUP(7))
        cout << "Same component\n";
    else
        cout << "Different component\n";

    ds2.UnionBySize(3, 7);

    if (ds2.findUP(3) == ds2.findUP(7))
        cout << "Same component\n";
    else
        cout << "Different component\n";

    return 0;
}