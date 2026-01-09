#include <bits/stdc++.h>
using namespace std;

    bool compare(string s1,string s2){
        if( s1.size() + 1 != s2.size() ){
            return false;
        }

        int first = 0;
        int second = 0;

        while(second!=s2.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }else{
                second++;
            }
        }

        if(first == s1.size() && second == s2.size()){
            return true;
        }else{
            return false;
        }
    }
    static bool comp(string &s1,string &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        vector<int> dp(n,1);
        int maxi = 1;

        sort(words.begin(),words.end(),comp);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if( compare(words[j],words[i]) && dp[i] < 1 + dp[j] ){
                    dp[i] = 1 + dp[j];
                }
            }

            maxi = max(maxi,dp[i]);
        }

        return maxi;
}
int main() {
    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};

    cout << "Longest String Chain Length: "<< longestStrChain(words) << endl;

    return 0;
}
