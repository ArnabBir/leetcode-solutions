// Link : https://leetcode.com/problems/word-abbreviation/

class Solution {

    class TrieNode {
        public:
            vector<TrieNode*> children;
            bool end;
            int count;
            TrieNode() {
                children = vector<TrieNode*>(26, nullptr);
                end = false;
                count = 0;
            }
    };

    class Trie {
            TrieNode* root;
        public:
            Trie() {
                root = new TrieNode();
            }
            void insert(string s) {
                TrieNode* curr = root;
                for (int i = 0; i < s.size(); ++i) {
                    if (curr->children[s[i]-'a'] == nullptr) {
                        curr->children[s[i]-'a'] = new TrieNode();
                    }
                    curr = curr->children[s[i]-'a'];
                    curr->count = curr->count + 1;
                }
                curr->end = true;
            }

            int first_unique(string s) {
                TrieNode* curr = root;
                int n = s.size();
                for (int i = 0; i < n; ++i) {
                    curr = curr->children[s[i]-'a'];
                    if (curr->count == 1) {
                        return i;
                    }
                }
                return n;
            }
    };

    string abbreviate(string s) {
        int n = s.size();
        if (n < 4) {
            return s;
        }
        return s[0] + to_string(n-2) + s.back();
    }
    

public:
     vector<string> wordsAbbreviation(vector<string>& words) {
        int n = words.size();
        unordered_map<string, vector<string> > um;
        for (string word : words) {
            um[abbreviate(word)].push_back(word);
        }
        unordered_map<string, string> result_map;
        for (auto it : um) {
            string abbr = it.first;
            vector<string> words = it.second;
            string first = *words.begin();
            wordsAbbreviationUtil(result_map, words);
        }
        vector<string> ans;
        for (string word : words) {
            ans.push_back(result_map[word]);
        }
        return ans;
    }

    void wordsAbbreviationUtil(unordered_map<string, string>& result_map, vector<string>& words) {
        int n = words.size();
        Trie* trie = new Trie();
        for (string word : words) {
            trie->insert(word);
        }
        vector<string> ans;
        for (string word : words) {
            int idx = trie->first_unique(word);
            int n = word.size();
            if (n < 4) {
                result_map[word] = word;
            } else {
                result_map[word] = word.substr(0,idx) + abbreviate(word.substr(idx));
            }
            
        }
    }
};