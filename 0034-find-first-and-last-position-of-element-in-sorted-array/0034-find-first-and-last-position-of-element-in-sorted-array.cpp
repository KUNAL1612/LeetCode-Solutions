class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l, r, m = 0;
        vector<int> res = {-1, -1};
        if(nums.empty())
            return res;
        
        l = 0; r = nums.size() - 1;
        while(l < r){
            m = (l + r) / 2;
            if(target <= nums[m])
                r = m;
            else
                l = m + 1;
        }
    
        if (l == nums.size()  || nums[l] != target)
            return res;

        res[0] = l;
        
        l = 0; r = nums.size() ; m = 0;
        while(l < r){
            m = (l + r) / 2;
            if(target < nums[m])
                r = m;
            else{
                l = m + 1;
                //if (l = r) m = l;
            }
        }
        res[1] = l - 1 ;
        
        return res;
    }
};