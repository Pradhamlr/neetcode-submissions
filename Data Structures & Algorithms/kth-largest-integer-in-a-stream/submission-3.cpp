class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(auto it: nums) {
            pq.push(it);

            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > kth) {
            pq.pop();
        }

        return pq.top();
    }
};
