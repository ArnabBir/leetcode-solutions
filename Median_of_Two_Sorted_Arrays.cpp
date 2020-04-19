class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int t = (n1+n2);
        float m = floor(t/2);
        vector<int> v(n1+n2);
        for(int i = 0; i < n1; ++i) v[i] = nums1[i];
        for(int i = 0; i < n2; ++i) v[n1+i] = nums2[i];
        sort(v.begin(), v.end());
        if(t%2) return v[m];
        else return (v[m-1] + v[m])/ 2.0;
    }
};
