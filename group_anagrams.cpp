class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string> > um;
        for(int i = 0; i < n; ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if(um.find(str) != um.end()) {
                um[str].push_back(strs[i]);
            }
            else {
                vector<string> v;
                v.push_back(strs[i]);
                um[str] = v;
            }
        }
        vector<vector<string>> result;
        for(auto & m : um) {
            result.push_back(m.second);
        }
        return result;
    }
};
