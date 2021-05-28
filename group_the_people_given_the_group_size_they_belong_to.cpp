class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
            int n = groupSizes.size();
        map<int,vector<int>> grpmap;
        for(int i = 0; i < n; ++i) {
            grpmap[groupSizes[i]].push_back(i);
}
vector<vector<int>> results;
for(auto & gm : grpmap) {
    int m = gm.first;
     vector<int> v = gm.second;
vector<int> temp;
    int k = v.size();
for(int i = 0; i < k; ++i) {
    temp.push_back(v[i]);
    if(temp.size() == m) {
        results.push_back(temp);
        temp.resize(0);
    }
}
}
return results;
    }
};
