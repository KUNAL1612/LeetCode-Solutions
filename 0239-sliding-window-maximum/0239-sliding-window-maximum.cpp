class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        //nlogn solution
        for(int i=0;i<k;i++) {
            pq.push({nums[i],i});
        }
        
        ans.push_back(pq.top().first);
        
        for(int i=k;i<nums.size();i++) {
            
            //empty previous indexes elements
            while(!pq.empty() && pq.top().second <= (i-k)) {
                pq.pop();
            }
            
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);
            
        }
        
        
        return ans;
        
    }
};