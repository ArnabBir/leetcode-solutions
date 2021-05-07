class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        for(int i = 0; i < n; ++i) {
            long sum = 0;
            bool flag = true;
            for(int j = 0; j < n; ++j) {
                sum += (gas[(i+j)%n] - cost[(i+j)%n]);
                if(sum < 0) {
                    flag = false;
                    break;
                }
            }
            if(flag && sum >= 0)    return i;
        } 
        return -1;
    }
};
