class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        if(nums[right] > nums[left]) return nums[0];
        
        while(right - left > 1)
        {
            int middle = (left + right)/2;
            
            if(nums[middle] > nums[left])
                left = middle;
            else if(nums[middle] < nums[right])
                right = middle;
        }
        
        return nums[max(left, right)];
    }
};