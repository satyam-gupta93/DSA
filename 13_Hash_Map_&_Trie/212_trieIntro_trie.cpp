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

            // Helper function to delete word and free memory
    bool removeHelper(TrieNode* node, string word, int depth) {
        if (!node) return false;

        // If end of word is reached
        if (depth == word.size()) {
            if (!node->isTerminal) return false; // word not found
            node->isTerminal = false;

            // If node has no children, we can delete it
            for (int i = 0; i < 26; i++)
                if (node->children[i] != NULL)
                    return false; // can't delete, has child

            return true; // signal to parent to delete this node
        }

        int idx = word[depth] - 'a';
        if (removeHelper(node->children[idx], word, depth + 1)) {
            delete node->children[idx];
            node->children[idx] = NULL;

            // Check if current node can also be deleted
            if (!node->isTerminal) {
                for (int i = 0; i < 26; i++)
                    if (node->children[i] != NULL)
                        return false; // can't delete, has other child
                return true; // can delete
            }
        }

        return false;
    }

    // Public delete function
    void remove(string word) {
        removeHelper(root, word, 0);
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


    
    t.remove("app");
    cout << "Present:"<< t.search("app") << endl;  // 0 (false)

}