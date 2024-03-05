class MovingAverage {
public:
    deque<int> q;
    float running_sum = 0.0;
    int gsize;
    MovingAverage(int size) {
        gsize = size;
    }
    
    double next(int val) {
        if(q.size() < gsize){
            q.push_back(val);
            running_sum += val;
        }
        else{
            auto val2 = q.front();
            q.pop_front();
            running_sum -= val2;
            q.push_back(val);
            running_sum += val;
            
        }
        return running_sum * 1.0 /q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */