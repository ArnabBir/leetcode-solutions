class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        if(n < 3)   return 0; 
        vector<int> maxl(n);
        vector<int> maxr(n);
        for(int i = 1; i < n; ++i) {
            maxl[i] = max(maxl[i-1], height[i-1]);
        }
        for(int i = n-2; i >= 0; --i) {
            maxr[i] = max(maxr[i+1], height[i+1]);
        }
        int water = 0;
        for(int i = 1; i < n-1; ++i) {
            int minh = min(maxl[i], maxr[i]);
            water += (minh > height[i]) ? (minh - height[i]) : 0;
        }
        return water;
    }
};
