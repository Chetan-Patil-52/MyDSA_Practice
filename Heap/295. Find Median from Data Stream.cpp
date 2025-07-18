class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int> , greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        // Checks
        if(abs((int)maxHeap.size() - (int)minHeap.size()) >1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            double result = ((double)minHeap.top() + (double)maxHeap.top())/2;
            return result;
        }

        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
