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
        if(minHeap.size() == maxHeap.size()) {
            double a = minHeap.top();
            double b = maxHeap.top();
            median = (a + b)/2.0;
        }
        else {
            median = minHeap.top();
        }

        return median;
    }
};
