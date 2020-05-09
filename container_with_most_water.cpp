class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxA = 0;
        int x = 0, y = n-1;
        while(x < y) {
            maxA = max(maxA, (y-x)*min(height[x], height[y]));
            if(height[x] <= height[y] ) {
                ++x;
            }
            else {
                --y;
            }
        }
        return maxA;
    }
};
