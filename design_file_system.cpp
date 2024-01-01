class TrieNode {
        bool end;
        int value;
    public:
        unordered_map<string, TrieNode*> children;
        TrieNode() {
            this->end = false;
            this->value = -1;
        }

        int getValue() {
            return this->value;
        }

        void setValue(int value) {
            this->value = value;
        }

        bool isEnd() {
            return this->end;
        }

        void setEnd(bool end) {
            this->end = end;
        }
};

class Trie {
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }
        bool insert(vector<string> parts, int value) {
            TrieNode* curr = root;
            int n = parts.size();
            for (int i = 1; i < n; ++i) {
                if (curr->children.find(parts[i]) == curr->children.end()) {
                    if (i < n-1) {
                        return false;
                    }
                    TrieNode* leafNode = new TrieNode();
                    leafNode->setValue(value);
                    leafNode->setEnd(true);
                    curr->children[parts[i]] = leafNode;
                    
                } else {
                    if (i == n-1) {
                        return false;
                    }
                }
                curr = curr->children[parts[i]];
            }
            return true;
        }
        
        int search(vector<string> parts) {
            int n = parts.size();
            TrieNode* curr = root;
            for (int i = 1; i < n; ++i) {
                if (curr->children.find(parts[i]) == curr->children.end()) {
                    return -1;
                }
                curr = curr->children[parts[i]];
            }
            if (curr->isEnd()) {
                return curr->getValue();
            }
            return -1;
        }
};

class FileSystem {
    Trie* trie;

    vector<string> parsePath(string path) {
        stringstream pathstream(path);
        string part;
        vector<string> parts;
        while(getline(pathstream, part, '/')) {
            parts.push_back(part);
        }
        return parts;
    }

public:
    FileSystem() {
        this->trie = new Trie();
    }
    
    bool createPath(string path, int value) {
        vector<string> parts = parsePath(path);
        return trie->insert(parts, value);
    }
    
    int get(string path) {
        vector<string> parts = parsePath(path);
        return trie->search(parts);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */