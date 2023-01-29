#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

class Trie{
public:
    char c;
    unordered_map<char, unique_ptr<Trie>> sons;
    int count;
    Trie(char _c){
        c = _c;
        count = 0;
    }
};

class Solution {
public:
    void buildTrie(unique_ptr<Trie>& node, const string& word, int p){
        if(p == word.length()){
            node->count++;
            return;
        }
        if(node->sons.find(word[p]) == node->sons.end()){
            node->sons[word[p]] = make_unique<Trie>(word[p]);
        }
        buildTrie(node->sons[word[p]], word, p+1);
    }

    bool search(unique_ptr<Trie>& node, unique_ptr<Trie>& root, const string& word, int p, int matchtime){
        if(node->count > 0){  // search from root again
            if(search(root, root, word, p, matchtime+1)){
                return true;
            }
        }
        if(p == word.length() && node.get() == root.get()){
            return matchtime > 1;
        }
        if(node->sons.find(word[p]) == node->sons.end()){
            return false;
        }
        else{
            return search(node->sons[word[p]], root, word, p+1, matchtime);
        }
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unique_ptr<Trie> root = make_unique<Trie>('\0');
        for(auto& word: words){
            buildTrie(root, word, 0);
        }
        vector<string> ans;
        for(auto& word: words){
           if(search(root, root, word, 0, 0)){
               ans.push_back(word);
           }
        }
        return ans;
    }
};
