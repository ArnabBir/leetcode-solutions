class MovingAverage {

private: 
    double sum;
    int n;
    queue<int> q;
public:
    
    MovingAverage(int size) {
        n = size;
        sum = 0.0;
    }

    double next(int val) {

        int qsize = q.size();
        if(qsize == 0) {
            sum = val;
        }
        else if(qsize < n){
            sum += val;
        }
        else {
            int top = q.front();
            sum += val - top;
            q.pop();
        }
        q.push(val);
        return sum/q.size();
    }
};
