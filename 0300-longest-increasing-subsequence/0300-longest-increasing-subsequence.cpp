class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num > sub.back()) {
                sub.push_back(num);
            } else {
                int j = binarySearch(sub, num);
                sub[j] = num;
            }
        }
        
        return sub.size();
    }
    
private:
    int binarySearch(std::vector<int>& sub, int num) {
        int left = 0;
        int right = sub.size() - 1;
        int mid = 0;
        int result;
                
        while (left <= right) {
            mid = (left + right) / 2;
            if (sub[mid] == num) {
                return mid;
            }
            
            if (sub[mid] < num) {
                left = mid + 1;
            } else {
                result = mid;
                right = mid-1;
            }
        }
        
        return result;
    }
};

// the previous was n^2. Need to do in NlogN


// Initialize an array sub which contains the first element of nums.

// Iterate through the input, starting from the second element. For each element num:

// If num is greater than any element in sub, then add num to sub.
// Otherwise, perform a binary search in sub to find the smallest element that is greater than or equal to num. Replace that element with num.
// Return the length of sub.