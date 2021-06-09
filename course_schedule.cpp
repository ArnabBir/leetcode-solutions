class Solution {
public:
    
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int x) {
        visited[x] = 1;
        for(int i = 0; i < adj[x].size(); ++i) {
            int y = adj[x][i];
            if(visited[y] == 0) {
                if(!dfs(adj, visited, y)) {
                    return false;
                }
            }
            else if(visited[y] == 1) {
                return false;
            }
        }
        visited[x] = 2;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int e = prerequisites.size();
        for(int i = 0; i < e; ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses, 0);
        int count = 0;
        for(int i = 0; i < numCourses; ++i) {
            if(visited[i]) continue;
            if(!dfs(adj, visited, i)) {
                return false; 
            }
        }
        return true;
    }
};
