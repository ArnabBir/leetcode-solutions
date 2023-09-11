// Link : https://leetcode.com/problems/zigzag-iterator

class ZigzagIterator {
    int i1, i2;
    int n1, n2;
    vector<int> v1;
    vector<int> v2;
    int curr;
public:
    ZigzagIterator(vector<int>& a1, vector<int>& a2) {
        this->i1 = 0;
        this->i2 = 0;
        this->v1 = a1;
        this->v2 = a2;
        this->n1 = (int) v1.size();
        this->n2 = (int) v2.size();
        this->curr = (n1 == 0) ? 2 : 1;
    }

    int next() {
        if (curr == 1) {
            if (i2 < n2) {
                curr = 2;
            }
            return v1[i1++];
        } else {
            if (i1 < n1) {
                curr = 1;
            }
            return v2[i2++];
        }
    }

    bool hasNext() {
        return !(i1 == n1 && i2 == n2);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */