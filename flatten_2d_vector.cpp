// Link : https://leetcode.com/problems/flatten-2d-vector

class Vector2D {
    int row;
    int index;
    vector<vector<int>> vec;
public:
    Vector2D(vector<vector<int>>& vec) {
        this->row = 0;
        this->index = 0;
        for (int i = 0; i < (int)vec.size(); ++i) {
            if (vec[i].size() == 0) {
                continue;
            }
            this->vec.push_back(vec[i]);
        }
    }
    
    int next() {
        int val = vec[row][index];
        int rowlen = vec[row].size();
        if (index < rowlen-1) {            
            ++index;
        } else if (index == rowlen-1) {
            ++row;
            index = 0;
        }
        return val;
    }
    
    bool hasNext() {
        return (row < (int)vec.size()) && (index < (int)vec[row].size());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
