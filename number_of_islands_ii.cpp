// Link : https://leetcode.com/problems/number-of-islands-ii/

class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0,-1, 1};

    int get_index(int x, int y, int m) {
        return x * m + y;
    }

    bool inside(int x, int y, int n, int m) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < m);
    }

    int get_parent(vector<int>& parent, int x) {
        if (x == parent[x]) {
            return x;
        }
        return (parent[x] = get_parent(parent, parent[x]));
    }

public:
    vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
        int p = positions.size();
        int v = n*m;
        vector<int> parent(v);
        vector<int> rank(v, 0);
        for (int i = 0; i <v; ++i) {
            parent[i] = i;
        }
        unordered_set<int> visited;
        vector<int> ans;
        int count = 0;
        for (vector<int> position : positions) {
            int ux = position[0];
            int uy = position[1];
            int idxu = get_index(ux, uy, m);
            if(visited.find(idxu) != visited.end()) {
                ans.push_back(count);
                continue;
            }
            visited.insert(idxu);
            ++count;
            for (int i = 0; i < 4; ++i) {
                int vx = ux + dx[i];
                int vy = uy + dy[i];
                int idxv = get_index(vx, vy, m);
                if (!inside(vx, vy, n, m) || visited.find(idxv) == visited.end()) {
                    continue;
                }
                int parentu = get_parent(parent, idxu);
                int parentv = get_parent(parent, idxv);
                if (parentv != parentu) {
                    --count;
                    if (rank[parentv] > rank[parentu]) {
                        parent[parentu] = parentv;
                    } else if (rank[parentv] < rank[parentu]) {
                        parent[parentv] = parentu;
                    } else {
                        parent[parentu] = parentv;
                        ++rank[parentv];
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
