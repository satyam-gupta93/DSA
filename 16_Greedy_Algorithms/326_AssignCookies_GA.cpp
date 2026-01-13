#include <bits/stdc++.h>
using namespace std;

    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()== 0){
            return 0;
        }
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0;
        int j = 0;
      
      
        
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                i++;
               
            }
                j++;
        
        }

        return i;
}
int main() {
    vector<int> greed = {1, 2, 3};
    vector<int> cookies = {1, 1};

    cout << "Maximum content children:"<< findContentChildren(greed, cookies) << endl;

    return 0;
}
