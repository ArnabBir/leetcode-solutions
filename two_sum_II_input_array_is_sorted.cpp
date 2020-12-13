class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size()-1;
        int i = 0;
        while(i < j) {
            if(numbers[i]+numbers[j] == target) {
                vector<int> result;
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
            else if(numbers[i]+numbers[j] < target) {
                ++i;
            }
            else {
                --j;
            }
        }
        return vector<int>();
    }
};
