class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int e = edges.size();
        vector<int> count(e+2,0);
        for(int i = 0; i < e; ++i) {
            if((count[edges[i][0]]++) > 0) return edges[i][0];
            if((count[edges[i][1]]++) > 0) return edges[i][1];
            
        }
        return -1;
    }
};
