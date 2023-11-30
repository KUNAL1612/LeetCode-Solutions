class Solution {
public:
    bool makesquare(vector<int>& nums) {
        
        if (nums.size() == 0)
            return false;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum % 4 != 0) return false;
        
        int target = sum / 4;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        if (any_of(nums.begin(), nums.end(), [&](int v) { return v > target; }))
            return false;
        
        int n = nums.size();
        
        vector<bool> visited(n, false);
        
        return find(nums, 4, target, 0, 0, visited);
    }
    
    bool find(vector<int>& nums, int sides_left, int target, int sum, int start, vector<bool>& visited)
    {
        if (sides_left == 1) return true;
        
        if (sum > target)
            return false;
        else if (sum == target)
        {
            return find(nums, sides_left-1, target, 0, 0, visited);
        }
        
        for (int i = start; i < nums.size(); i++)
        {
            if (sum + nums[i] > target) continue;
            
            if (visited[i]) continue;
            
            visited[i] = true;
            
            if (find(nums, sides_left, target, sum + nums[i], i+1, visited) ) return true;
            
            visited[i] = false;
        }
        
        return false;
    }
};