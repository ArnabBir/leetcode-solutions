class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 1)  return heights[0];
        stack<int> s;
        int h, area;
        int max_area = 0;
        int i = 0;
        while(i < n) {
            if(s.empty() || (heights[s.top()] <= heights[i])) {
                s.push(i++);
            }
            else {
                h = heights[s.top()];
                s.pop();
                area = i * h;
                if(!s.empty()) {
                    area = h * (i - s.top() -1);
                }
                max_area = max(area, max_area);
            }
        }
        while(!s.empty()) {
            h = heights[s.top()];
            s.pop();
            area = i * h;
            if(!s.empty()) {
                area = h * (i - s.top() -1);
            }
            max_area = max(area, max_area);
        }
        return max_area;
    }
    
};
