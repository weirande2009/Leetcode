#include <unordered_map>
#include <string>
using namespace std;

struct MyNode{
    unordered_map<char, MyNode*> sons;
    char c;
    int num;
};

class WordDictionary {
private:
    // use trie to store
    MyNode* root;

    void dfsAdd(const string& word, MyNode* node, int pos){
        if(pos == word.length()){
            node->num++;
            return;
        }
        if(node->sons.find(word[pos]) == node->sons.end()){
            node->sons[word[pos]] = new MyNode();
            node->sons[word[pos]]->c = word[pos];
        }
        dfsAdd(word, node->sons[word[pos]], pos+1);
    }

    bool dfsSearch(const string& word, MyNode* node, int pos){
        if(pos == word.length()){
            return node->num > 0;
        }
        if(word[pos] == '.'){
            for(auto& p: node->sons){
                if(dfsSearch(word, p.second, pos+1)){
                    return true;
                }
            }
        }
        else{
            if(node->sons.find(word[pos]) != node->sons.end()){
                return dfsSearch(word, node->sons[word[pos]], pos+1);
            }
        }
        return false;
    }

public:
    WordDictionary() {
        root = new MyNode();
    }
    
    void addWord(string word) {
        dfsAdd(word, root, 0);
    }
    
    bool search(string word) {
        return dfsSearch(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */