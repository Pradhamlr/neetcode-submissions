class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(maxHeap.size() + 1 < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        double median;

        if(maxHeap.size() == minHeap.size()) {
            double left = maxHeap.top();
            double right = minHeap.top();
            median = (left + right)/2.0;
        }
        else {
            median = minHeap.top();
        }

        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */