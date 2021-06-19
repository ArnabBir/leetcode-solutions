class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxPrice;
        int ans = 0;
        maxPrice = prices[n-1];
        for(int i = n-2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            ans = max(ans, maxPrice-prices[i]);
        }
        return ans;
    }
};
