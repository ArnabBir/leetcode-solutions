class MedianFinder {

private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    double median;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        if( min_heap.size() < max_heap.size()) {
            if((double)num >= median) {
                min_heap.push(num);
            }
            else {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
             median = ((long)min_heap.top() + (long)max_heap.top()) / (double)2;
        }
        else if (min_heap.size() > max_heap.size()){
            if((double)num < median) {
                max_heap.push(num);
            }
            else {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
             median = ((long)min_heap.top() + (long) max_heap.top()) / (double)2;
        }
        else {
            if((double)num < median) {
                max_heap.push(num);
                median = max_heap.top();
            }
            else {
                min_heap.push(num);
                median = min_heap.top();
            }
        }
       
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
