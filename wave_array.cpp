vector<int> Solution::wave(vector<int> &A) {
    int n = A.size();
    int m = n/2;
    sort(A.begin(), A.end());
    vector<int> result;
    for(int i = 0; i < n/2; ++i) {
        result.push_back(A[2*i+1]);
        result.push_back(A[2*i]);
    }
    if(n%2) {
        result.push_back(A[n-1]);
    }
    return result;
}
