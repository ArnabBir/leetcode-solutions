// Link : https://leetcode.com/problems/array-transformation/

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int moves;
        int n = arr.size();
        do {
            moves = 0;
            vector<int> temp = arr;
            for (int i = 1; i < n-1; ++i) {
                if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                    --temp[i];
                    ++moves;
                }
                if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                    ++temp[i];
                    ++moves;
                }
            }
            arr = temp;
        } while (moves > 0);
        return arr;
    }
};
