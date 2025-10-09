#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordL( wordList.begin(),wordList.end() );

        if(wordL.find(endWord) == wordL.end()){
            return 0;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){

            auto frontNode = q.front();
            q.pop();
            
            string word = frontNode.first;
            int lvl = frontNode.second;

            if(word == endWord){
                return lvl;
            }

            for(int i = 0; i<word.size(); i++){
                string temp = word;
                for(char c = 'a'; c<='z'; c++){
                    temp[i] = c;
                    if(wordL.find(temp) != wordL.end()){
                        q.push({temp,lvl+1});
                        wordL.erase(temp);
                    }
                }
            }
        }

        return 0;
    }

int main() {
 
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = ladderLength(beginWord, endWord, wordList);

    cout << "Shortest transformation length: " << result << endl;

    return 0;
}