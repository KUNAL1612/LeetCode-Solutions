class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int total = 0;
        for(auto pile:piles){
            pq.push(pile);
            total+=pile;
        }
        
        
        while(!pq.empty() && k>0){
            int p = pq.top();
            pq.pop();
            total -= p/2;
            pq.push(p - p/2);
            k--;
        }
        
        return total;
    }
};