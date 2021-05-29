class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor1 = 0, xor2 = 0;
        for(int i = 0; i < arr1.size(); ++i) {
            xor1 ^= arr1[i];
        }
        for(int j = 0; j < arr2.size(); ++j) {
            xor2 ^= arr2[j];
        }
        return xor1&xor2;
    }
};
