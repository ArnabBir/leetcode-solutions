class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int dx[4] = {0, 0,-1,1};
        int dy[4] = {1,-1, 0,0};
        vector<vector<vector<vector<int>>>> adj(n, vector<vector<vector<int>>>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                for(int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 && x < n && y >= 0 && y < m) {
                        vector<int> temp;
                        temp.push_back(x);
                        temp.push_back(y);
                        temp.push_back(abs(heights[i][j]-heights[x][y]));
                        //cout<<temp[2]<<endl;
                        adj[i][j].push_back(temp);
                    }
                }
            }
        }
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push(make_pair(0,make_pair(0,0)));
        dist[0][0] = 0;
        while(!pq.empty()) {
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            int x = p.second.first;
            int y = p.second.second;
            for(int k = 0; k < adj[x][y].size(); ++k) {
                vector<int> temp = adj[x][y][k];
                int u = temp[0];
                int v = temp[1];
                int w = temp[2];
                if(dist[u][v] > max(dist[x][y], w)) {
                    dist[u][v] = max(dist[x][y], w);
                    //cout<<u<<" - "<<v<<" - "<<w<<" - "<<dist[u][v]<<endl;
                    pq.push(make_pair(dist[u][v], make_pair(u,v)));
                }
            }
        }
        return dist[n-1][m-1];
    }
};
