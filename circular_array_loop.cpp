class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            stack<int> s;
            s.push(i);
            while(!s.empty()) {
                int curr = s.top();
                s.pop();
                visited[curr] = true;
                int next = (curr + (nums[curr] % n) + n) % n;
                bool currsign = nums[curr] > 0;
                bool nextsign = nums[next] > 0;
                if(currsign == nextsign) {
                    if(curr == next)    break;
                    if(visited[next]) {
                        return true;
                    }
                    s.push(next);
                }
            }
        }
        return false;
    }
};
