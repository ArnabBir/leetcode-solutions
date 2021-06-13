class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictionary;
        for(int i = 0; i < wordDict.size(); ++i) {
            dictionary.insert(wordDict[i]);
        }
        int n = s.size();
        set<int> done;
        done.insert(-1);
        for(int i = 0; i < n; ++i) {
            for(auto j : done) {
                if(dictionary.find(s.substr(j+1,i-j)) != dictionary.end()) {
                    done.insert(i);
                }
            }
        }
        return (done.find(n-1) != done.end());
    }
};
