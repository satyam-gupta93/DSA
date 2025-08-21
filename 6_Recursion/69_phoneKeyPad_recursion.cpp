#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans, string output, int indx, string digits, string mapping[] ){

    if(indx >= digits.size()){
        ans.push_back(output);
        return;
    }

    int num = digits[indx] - '0';
    string value = mapping[num];


    for(int i = 0; i < value.length(); i++){
        output.push_back(value[i]);
        solve(ans,output,indx+1,digits,mapping);
        output.pop_back(); // backtrack
    }

}
vector<string> letterCombinations(string digits) {


        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output;

        int indx = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};

        solve(ans,output,indx,digits,mapping);

        return ans;
}

int main(){

    string digits;
    cout<<"Enter digtis:";
    cin>>digits;

    vector<string> result = letterCombinations(digits);

    for(string s : result){
        cout<<s<<" ";
    }
    cout<<endl;
}
