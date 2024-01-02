// Link : https://leetcode.com/problems/optimize-water-distribution-in-a-village/

class Solution {
    int get_parent(vector<int>& parents, int x) {
        if (x == parents[x]) {
            return x;
        }
        return (parents[x] = get_parent(parents, parents[x]));
    }

    static bool compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    } 

    public:
    int minCostToSupplyWater(int n, vector<int>& wells,     vector<vector<int>>& pipes) {
        vector<int> parents(n+1);
        vector<int> ranks(n+1, 0);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
            pipes.push_back({n+1, i+1, wells[i]});
        }
        parents[n] = n;
        int total = 0;
        sort(pipes.begin(), pipes.end(), compare);
        for (vector<int> pipe : pipes) {
            int h1 = pipe[0]-1;
            int h2 = pipe[1]-1;
            int cost = pipe[2];
            int ph1 = get_parent(parents, h1);
            int ph2 = get_parent(parents, h2);
            if (ph1 == ph2) {
                continue;
            }
            if (ranks[ph1] > ranks[ph2]) {
                parents[ph2] = ph1;
            } else if (ranks[ph1] < ranks[ph2]) {
                parents[ph1] = ph2;
            } else {
                parents[ph2] = ph1;
                ++ranks[ph1];
            }
            total += cost;
        }
        return total;
    }
};
