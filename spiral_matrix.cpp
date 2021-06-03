class Solution {
private:
    int dx[4] = {0,1, 0,-1};
    int dy[4] = {1,0,-1, 0};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int n2 = n*m;
        int d = 0;
        vector<int> v;
        while(n2--) {
            v.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
            if(i+dx[d] < 0 || i+dx[d] == n || j+dy[d] < 0 || j+dy[d] == m
              || matrix[i+dx[d]][j+dy[d]] == INT_MAX) {
                d = (d+1)%4;
            }
            i = i+dx[d];
            j = j+dy[d];
        }
        return v;
    }
};
