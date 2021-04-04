class Solution {
public:
    
    vector<int> getVersions(string version) {
        vector<int> v;
        int x;
        while((x = version.find(".")) != string::npos) {
            string sub = version.substr(0, x);
            v.push_back(stoi(sub));
            version.erase(0,sub.size()+1);
        }
        v.push_back(stoi(version));
        return v;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = getVersions(version1);
        vector<int> v2 = getVersions(version2);
        int x = 0;
        int n = max(v1.size(), v2.size());
        while(x < n) {
            int pos1, pos2;
            if(x < v1.size()) {
                pos1 = v1[x];
            }
            else {
                pos1 = 0;
            }
            if(x < v2.size()) {
                pos2 = v2[x];
            }
            else {
                pos2 = 0;
            }
            
            if(pos1 < pos2) {
                return -1;
            }
            else if(pos1 > pos2) {
                return 1;
            }
            ++x;
        }
        return 0;
    }
};
