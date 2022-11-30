class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() < 1) return -1;
        
        
        int left = 0;
        int right = nums.size() - 1;
        
        // find the index of minimun
        int indexMin = GetMinimunsIndex(nums);
        
        left = 0;
        right = nums.size() - 1;
        if(target >= nums[indexMin] && target <= nums[right])
            return this->BinarySearch(nums, target, indexMin, nums.size());
        else if(target >= nums[indexMin] && target >= nums[left])
            return this->BinarySearch(nums, target, 0, indexMin);
        
        // not found
        return -1;
    }
    
    int BinarySearch(vector<int>& nums, int target, int first, int last)
    {
        int left = first;
        int right = last - 1;
        
        while(left <= right)
        {
            int middle = (left + right)/2;
            
            if(nums[middle] == target)
                return middle;
            else if(nums[middle] < target)
                left = middle + 1;
            else if(nums[middle] > target)
                right = middle - 1;
        }
        
        // not found
        return -1;
    }
    
    int GetMinimunsIndex(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        
        if(nums[right] > nums[left]) return 0;
        
        while(right - left > 1)
        {
            int middle = (left + right)/2;
            
            if(nums[middle] > nums[left])
                left = middle;
            else if(nums[middle] < nums[right])
                right = middle;
        }
        
        return right;
    }
};

// 1- take the middle and compare with target, if matches return.
// 2- if middle is bigger than left side, it means left is sorted
// 2a- if [left] < target < [middle] then do recursion with left, middle - 1 (right)
// 2b- left side is sorted, but target not in here, search on right side middle + 1 (left), right
// 3- if middle is less than right side, it means right is sorted
// 3a- if [middle] < target < [right] then do recursion with middle + 1 (left), right
// 3b- right side is sorted, but target not in here, search on left side left, middle -1 (right)