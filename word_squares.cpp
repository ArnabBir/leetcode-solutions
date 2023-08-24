/*
b a b a
a b a t
b a b a
a t a l

b a b a
a b a t
b a b a
a t a l

*/

class Solution {
    unordered_map<string, vector<string>> buildPrefixHashTable(vector<string>& words) {
        unordered_map<string, vector<string>> table;
        int n = words.size();
        int m = words[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                string key = words[i].substr(0,j);
                table[key].push_back(words[i]);
            }
        }
        return table;
    }

    void wordSquaresHelper(vector<string>& words,
                        vector<vector<string>>& squares,
                        vector<string>& current,
                        unordered_map<string, vector<string>>& table,
                        int x,
                        int m,
                        int n) {
        if (x == m) {
            squares.push_back(current);
            return;
        }
        string prefix;
        for (int i = 0; i < current.size(); ++i) {
            prefix += current[i][x];
        }
        vector<string> wordsWithPrefix = table[prefix];
        for (string word : wordsWithPrefix) {
            current.push_back(word);
            wordSquaresHelper(words, squares, current, table, x+1, m, n);
            current.pop_back();
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        unordered_map<string, vector<string>> table = buildPrefixHashTable(words);
        int n = words.size();
        int m = words[0].size();
        vector<vector<string>> squares;
        for (int i = 0; i < n; ++i) {
            vector<string> current;
            current.push_back(words[i]);
            wordSquaresHelper(words, squares, current, table, 1, m, n);
            current.pop_back();
        }
        return squares;
    }
};
