// Link : https://leetcode.com/problems/shortest-word-distance

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < (int)wordsDict.size(); ++i) {
            if (word1 == wordsDict[i]) {
                pq.push({i,1});
            } else if (word2 == wordsDict[i]) {
                pq.push({i,2});
            }
        }
        int result = wordsDict.size()-1;
        int last1 = -1, last2 = -1;
        while (!pq.empty()) {
            pair<int,int> last = pq.top();
            pq.pop();
            if (last.second == 1) {
                last1 = last.first;
            } else if (last.second == 2) {
                last2 = last.first;
            }
            if (last1 != -1 && last2 != -1) {
                result = min(abs(last1 - last2), result);
            }
        }
        return result;
    }
};