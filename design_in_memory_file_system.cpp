// Link : https://leetcode.com/problems/design-in-memory-file-system/

class TrieNode {
    private:
        unordered_map<string, TrieNode*> children;
        bool end;
        vector<string> values;
    
    public:
        TrieNode() {
            end = false;
        }

        bool isEnd() {
            return this->end;
        }

        TrieNode* getChild(string key) {
            return this->children[key];
        }

        vector<string> getAllChildren() {
            vector<string> children_names;
            for (auto node_itr : children) {
                children_names.push_back(node_itr.first);
            }
            return children_names;
        }

        bool hasChild(string key) {
            return this->children.find(key) != this->children.end();
        }

        void addChild(string key) {
            if (this->children.find(key) == this->children.end()) {
                this->children[key] = new TrieNode();
            }
        }

        vector<string> getValues() {
            return this->values;
        }

        void addValue(string value) {
            this->values.push_back(value);
        }

        void markEnd() {
            this->end = true;
        }
};

class FileUtils {
    private:
        static const char DELIMITER = '/'; 
    public:
        static vector<string> parsePath(string pathstr) {
            vector<string> path;
            pathstr = pathstr.substr(1);
            stringstream pathstrss(pathstr);
            string dir;
            while (getline(pathstrss, dir, DELIMITER)) {
                path.push_back(dir);
            }
            return path;
        }
};

class FileSystem {
private:
    TrieNode* root;

    TrieNode* mkdirUtil(vector<string>& paths) {
        TrieNode* curr = root;
        for (string p : paths) {
            curr->addChild(p);
            curr = curr->getChild(p);
        }
        return curr;
    }

public:
    FileSystem() {
        this->root = new TrieNode();
    }
    
    vector<string> ls(string path) {
        vector<string> paths = FileUtils::parsePath(path);
        TrieNode* curr = root;
        for (string p : paths) {
            if (!curr->hasChild(p)) {
                return {};
            }
            curr = curr->getChild(p);
        }
        if (curr->isEnd()) {
            return {paths.back()};
        }
        vector<string> children = curr->getAllChildren();
        sort(children.begin(), children.end());
        return children;
    }
    
    void mkdir(string path) {
        vector<string> paths = FileUtils::parsePath(path);
        mkdirUtil(paths);
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> paths = FileUtils::parsePath(filePath);
        TrieNode* curr = mkdirUtil(paths);
        curr->markEnd();
        curr->addValue(content);
    }
    
    string readContentFromFile(string filePath) {
        vector<string> paths = FileUtils::parsePath(filePath);
        TrieNode* curr = root;
        for (string p : paths) {
            if (!curr->hasChild(p)) {
                return "";
            }
            curr = curr->getChild(p);
        }
        vector<string> contents = curr->getValues();
        string concat_content;
        for (string content : contents) {
            concat_content.append(content);
        }
        return concat_content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
