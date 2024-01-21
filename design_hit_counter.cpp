// Link: https://leetcode.com/problems/design-hit-counter/

class HitCounter {
private:
    priority_queue<int, vector<int>, greater<int> > hits;
    static const int INTERVAL = 300;

public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hits.push(timestamp);
        while (hits.top() + INTERVAL <= timestamp) {
            hits.pop();
        }
    }
    
    int getHits(int timestamp) {
        while (!hits.empty() && hits.top() + INTERVAL <= timestamp) {
            hits.pop();
        }
        return hits.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */