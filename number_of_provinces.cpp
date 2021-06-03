class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        int ans1 = 0;
        vector<bool> visited(n);
        for(int i = 0; i < n; ++i) {
                if(visited[i])   continue;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                ++ans;
                while(!q.empty()) {
                    int x = q.front();
                    q.pop();
                    for(int j = 0; j < n; ++j) {
                        if(!visited[j] && (isConnected[x][j] || isConnected[j][x])) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }    
        }
        return ans;
    }
};
