class Solution {

private:
    vector<vector<int>> ans;
    vector<bool> visited;
public:
    void allPathsSourceTargetUtil(vector<vector<int>>& graph, vector<int> & v, int x) {
        if(x == graph.size()-1) {
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < graph[x].size(); ++i) {
            v.push_back(graph[x][i]);
            allPathsSourceTargetUtil(graph, v, graph[x][i]);
            v.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        v.push_back(0);
        visited.resize(graph.size(), false);
        allPathsSourceTargetUtil(graph, v, 0);
        return ans;
    }
};
