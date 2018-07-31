class Solution {
public:
    
    bool getFibonacci(string S, vector<int>& nums, int pos)   {
        
        if(pos == S.size() && nums.size() > 2)  return true;
        
        for(int i = pos; i < S.size(); ++i) {
            if(S[pos] == '0' && i > pos)    break;
            long num = stol(S.substr(pos, i-pos+1));
            if(num > INT_MAX)   break;
            if(nums.size() >= 2 && num > nums[nums.size()-2] + nums[nums.size()-1] )    break;
            if(nums.size() < 2 || num == nums[nums.size()-2] + nums[nums.size()-1]) {
                nums.push_back((int)num);
                if(getFibonacci(S, nums, i+1))    return true;
                nums.pop_back();
            }
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string S) {
        
        vector<int> nums;
        if(S.empty() || S.size() < 3)   {
            return nums;
        }
        getFibonacci(S, nums, 0);
        return nums;
    }
};
