class Solution {
public:
    
    bool binarySearch(vector<vector<int>>& matrix, int target, int lx, int rx, int ly, int ry) {
        if(lx > rx || ly > ry)  return false;
        if(lx == rx && ly == ry)  return matrix[lx][ly] == target;
        int n = matrix.size();
        int m = matrix[0].size();
        if(lx < 0 || lx >= n || rx < 0 || rx >= n
           || ly < 0 || ly >= m || ry < 0 || ry >= m) {
            return false;
        }
        int mx = lx + ((rx-lx)>>1);
        int my = ly + ((ry-ly)>>1);
        if(matrix[mx][my] == target) {
            return true;
        }
        if(matrix[mx][my] > target) {
            return binarySearch(matrix,target,lx,mx,ly,my)
                || binarySearch(matrix,target,mx+1,rx,ly,my)
                || binarySearch(matrix,target,lx,mx,my+1,ry);
        }
        return binarySearch(matrix,target,mx+1,rx,my+1,ry) 
                || binarySearch(matrix,target,mx+1,rx,ly,my)
                || binarySearch(matrix,target,lx,mx,my+1,ry);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        return binarySearch(matrix, target, 0, n-1, 0, m-1);
    }
};
