class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += arr[i] * ceil((i+1)*(n-i)/(double)2);
            cout<<sum<<" ";
        }
        return sum;
    }
};
