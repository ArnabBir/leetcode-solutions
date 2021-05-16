class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        map<int, vector<int>> um;
        for(int i = 0; i < n-1; ++i) {
            if(temperatures[i] < temperatures[i+1]) {
                ans[i] = 1;
                for(auto & itr : um) {
                    if(itr.first < temperatures[i+1]) {
                        vector<int> pos = itr.second;
                        for(int j = 0; j < pos.size(); ++j) {
                            ans[pos[j]] = i+1-pos[j];
                        }
                        um.erase(itr.first);
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                um[temperatures[i]].push_back(i);
            }
        }
        return ans;
    }
};
