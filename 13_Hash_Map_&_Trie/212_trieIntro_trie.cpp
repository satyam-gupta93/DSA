#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i = 0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }

};

class Trie{
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode('\0'); // root node with empty char
        }

        void insert(string word){
            TrieNode* node = root;
            for(char ch : word){
                int indx = ch - 'a';
                if(node->children[indx]==NULL){
                    node->children[indx] = new TrieNode(ch);
                }
                node = node->children[indx];
            }
            node->isTerminal = true;
        }

        bool search(string word){

            TrieNode* node = root;

            for(char ch :word){
                int indx = ch - 'a';
                if(node->children[indx] == NULL ){
                    return false;
                }
                node = node->children[indx];
            }

            return node->isTerminal;
        }
        bool isStart(string word){
            TrieNode* node = root;

            for(char ch:word){
                int indx = ch - 'a';

                if(node->children[indx]==NULL){
                    return false;
                }
                node = node->children[indx];
            }
            return true;
        }
};



int main(){

    Trie t;

    t.insert("apple");
    t.insert("app");

    cout <<"Present:"<< t.search("apple") << endl; // 1 (true)
    cout <<"Present:"<<  t.search("app") << endl;   // 1 (true)
    cout << "Present:"<< t.search("appl") << endl;  // 0 (false)
    cout <<" Is Start:"<<  t.isStart("appl") << endl;  // 0 (false)

}