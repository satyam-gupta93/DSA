#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod = 100000;
        queue<pair<int,int>> q;
        q.push({0,start});
        
        vector<int> dist(100000,INT_MAX);
        dist[start] = 0;
        
        while(!q.empty()){
            
            auto top = q.front();
            q.pop();
            
            int step = top.first;
            int node = top.second;
            
              if(node == end){
                    return step ;
            }
            
            for(auto i : arr){
                int num = (i*node)%mod;
                
              
                
                if(step + 1 < dist[num]){
                    dist[num] = step + 1;
                    q.push({dist[num],num});
                }
            }
        }
        
        return -1;
}

int main() {
   
    
    vector<int> arr = {2, 5, 7};
    int start = 3, end = 30;
    
    int ans = minimumMultiplications(arr, start, end);
    
    cout << "Minimum steps: " << ans << endl;
    
    return 0;
}