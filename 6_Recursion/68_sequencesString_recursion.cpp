#include <bits/stdc++.h>
using namespace std;

void solve(string &str, vector<string> &ans, string output, int indx) {
    if (indx >= str.size()) {
        if (output.length()>0){
             ans.push_back(output);
        } 
           
        return;
    }

    // Exclude the current character
    solve(str, ans, output, indx + 1);

    // Include the current character
    output.push_back(str[indx]);
    solve(str, ans, output, indx + 1);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    int indx = 0;
    solve(str, ans, output, indx);
    return ans;
}

int main() {
    
        string str;
        cin >> str;

        vector<string> result = subsequences(str);

        for (string s : result) {
            cout << s << " ";
        }
        cout << endl;
   
    return 0;
}
