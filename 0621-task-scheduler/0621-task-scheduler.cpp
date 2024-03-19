class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int>m;
        int count=0;
        for(auto i:tasks){
            m[i]++;
            count=max(count,m[i]);
        }
        int ans=(count-1)*(n+1);
        
        for(auto i:m)if(i.second==count)ans++;
        
        return max((int)tasks.size(),ans); // first is for when the task does not force idle time. Basically the most popular task isn't popular enough to creatge empty slots and we can put everything together

    }
};