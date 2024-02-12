// Link : https://leetcode.com/problems/design-a-leaderboard/

class Leaderboard {
    unordered_map<int,int> score_map;
    map<int, unordered_set<int> > rank_map;
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        int curr_score = score_map[playerId];
        int new_score = curr_score + score;
        score_map[playerId] = new_score;
        rank_map[curr_score].erase(playerId);
        rank_map[new_score].insert(playerId);
    }
    
    int top(int K) {
        map<int,unordered_set<int> >::reverse_iterator rit = rank_map.rbegin();
        int sum = 0;
        while (rit != rank_map.rend()) {
            int count = min(K, (int)rit->second.size());
            sum += (rit->first) * count;
            K -= count;
            ++rit;
        }
        return sum;
    }
    
    void reset(int playerId) {
        addScore(playerId, -score_map[playerId]);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
 