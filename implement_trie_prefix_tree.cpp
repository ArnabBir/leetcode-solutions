class TrieMap {
    public:
        unordered_map<char, TrieMap*> um;
        bool endOfWord;
        TrieMap(){
            endOfWord = false;
        }
};

class Trie {

private:
    TrieMap* trieMap;
    
    
public:
    /** Initialize your data structure here. */
    Trie() {
        trieMap = new TrieMap();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        TrieMap* temp = trieMap;
        for(int i = 0; i < n; ++i) {
            if(temp->um.find(word[i]) == temp->um.end()) {
                temp->um[word[i]] = new TrieMap();
            }
            temp = temp->um[word[i]];
        }
        temp->endOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        TrieMap* temp = trieMap;
        for(int i = 0; i < n; ++i) {
            if(temp->um.find(word[i]) == temp->um.end()) {
                return false;
            }
            temp = temp->um[word[i]];
        }
        return temp->endOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        int n = word.size();
        TrieMap* temp = trieMap;
        for(int i = 0; i < n; ++i) {
            if(temp->um.find(word[i]) == temp->um.end()) {
                return false;
            }
            temp = temp->um[word[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
