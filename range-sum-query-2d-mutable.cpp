// Link : https://leetcode.com/problems/range-sum-query-2d-mutable

class SegRow {
    public:
        int val;
        int l, r;
        SegRow* left;
        SegRow* right;
        
        SegRow(int val, int l, int r) {
            this->val = val;
            this->l = l;
            this->r = r;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class SegMatrix {

    public:
        SegRow* row;
        int l, r;
        SegMatrix* left;
        SegMatrix* right;
        
        SegMatrix(SegRow* row, int l, int r) {
            this->row = row;
            this->l = l;
            this->r = r;
            this->left = nullptr;
            this->right = nullptr;
        }
};

SegMatrix* global_matrix;
vector<vector<int>> input;

class NumMatrix {
private:
    SegRow* buildSegRow(vector<int>& row, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        if (l == r) {
            return new SegRow(row[l], l, r);
        }
        int m = l + (r-l)/2;
        SegRow* node = new SegRow(0, l, r);
        SegRow* left = buildSegRow(row, l, m);
        SegRow* right = buildSegRow(row, m+1, r);
        if (left != nullptr) {
            node->val += left->val;
        }
        if (right != nullptr) {
            node->val += right->val;
        }
        node->left = left;
        node->right = right;
        return node;
    }

    SegRow* mergeRows(SegRow* left, SegRow* right, int l, int r) {
        if (left == nullptr && right == nullptr) {
            return nullptr;
        } 
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        SegRow* curr = new SegRow(left->val + right->val, l, r);
        int m = l + (r-l)/2;
        curr->left = mergeRows(left->left, right->left, l, m);
        curr->right = mergeRows(left->right, right->right, m+1, r);
        return curr;
    }

    SegMatrix* buildSegMatrix(vector<vector<int>>& matrix, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int n = matrix[l].size();
        if (l == r) {
            return new SegMatrix(buildSegRow(matrix[l], 0, n-1), l, r);
        }
        int m = l + (r-l)/2;
        SegMatrix* left = buildSegMatrix(matrix, l, m);
        SegMatrix* right = buildSegMatrix(matrix, m+1, r);
        SegRow* curr;
        if (left == nullptr) {
            curr = right->row;
        } else if (right == nullptr) {
            curr = left->row;
        } else {
            curr = mergeRows(left->row, right->row, 0, n-1);
        }
        SegMatrix* currMatrix = new SegMatrix(curr, l, r);
        currMatrix->left = left;
        currMatrix->right = right;
        return currMatrix;
    }

    int sumRowHelper(SegRow* row, int col1, int col2) {
        if (row == nullptr) {
            return 0;
        }
        int l = row->l;
        int r = row->r;
        if (col2 < l || col1 > r) {
            return 0;
        }
        if (col1 <= l && col2 >= r) {
            return row->val;
        }
        return sumRowHelper(row->left, col1, col2) + sumRowHelper(row->right, col1, col2);
    }

    int sumMatrixHelper(SegMatrix* node, int row1, int col1, int row2, int col2) {
        if (node == nullptr) {
            return 0;
        }
        int l = node->l;
        int r = node->r;
        if (row2 < l || row1 > r) {
            return 0;
        }
        if (row1 <= l && row2 >= r) {
            int result = sumRowHelper(node->row, col1, col2);
            return result;
        }
        return sumMatrixHelper(node->left, row1, col1, row2, col2) 
             + sumMatrixHelper(node->right, row1, col1, row2, col2);
    }

    void updateRowHelper(SegRow* row, int col, int val) {
        if (row == nullptr) {
            return;
        }
        int l = row->l;
        int r = row->r;
        if (col < l || col > r) {
            return;
        }
        row->val += val;
        int m = l + (r-l)/2;
        if (col <= m) {
            updateRowHelper(row->left, col, val);
        } else {
            updateRowHelper(row->right, col, val);
        }
    }

    void updateMatrixHelper(SegMatrix* matrix, int row, int col, int val) {
        if (matrix == nullptr) {
            return;
        }
        int l = matrix->l;
        int r = matrix->r;
        if (row < l || row > r) {
            return;
        }
        updateRowHelper(matrix->row, col, val);
        int m = l + (r-l)/2; 
        if (row <= m) {
            updateMatrixHelper(matrix->left, row, col, val);
        } else {
            updateMatrixHelper(matrix->right, row, col, val);
        }
    }
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
         input = matrix;
         global_matrix = buildSegMatrix(matrix, 0, (int)matrix.size()-1);
    }
 
    ~NumMatrix() {}
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMatrixHelper(global_matrix, row1, col1, row2, col2);
    }

    void update(int row, int col, int val) {
        updateMatrixHelper(global_matrix, row, col, val - input[row][col]);
        input[row][col] = val;
    }
    
};



/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
