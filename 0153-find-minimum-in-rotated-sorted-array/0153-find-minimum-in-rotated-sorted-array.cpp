class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        if(nums[right] > nums[left]) return nums[0]; // cross checking for everything where we don't need to binary sort at all
        
        while(right - left > 1)
        {
            int middle = (left + right)/2;
            
            if(nums[middle] > nums[left])
                left = middle;
            else if(nums[middle] < nums[right])
                right = middle;
        }
        
        return nums[right]; // we need to return the max of lo and hi
    }
};


// int left = 0, right = nums.size()-1;
