class MedianFinder {
    priority_queue<double,vector<double>,greater<double>> sec;
    priority_queue<double> first;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(first.size() == 0 or first.top() > num)first.push(num);
        else sec.push(num);
        
        if(first.size() > sec.size() + 1){
            sec.push(first.top());
            first.pop();
        }else if(first.size() + 1 < sec.size()){
            first.push(sec.top());
            sec.pop();
        }
    }
    
    double findMedian() {
        if(first.size() + sec.size() & 1)return first.size() > sec.size() ? first.top() : sec.top();
        if(first.size() == sec.size())return first.empty()?0:( (first.top()+sec.top())/2.0);
        return -1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
