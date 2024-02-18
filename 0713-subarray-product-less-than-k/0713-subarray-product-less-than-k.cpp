class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if (k == 0) return 0;
        double logk = log(k);
        std::vector<double> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + log(nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < prefix.size(); i++) {
            int lo = i + 1, hi = prefix.size();
            while (lo < hi) {
                int mi = lo + (hi - lo) / 2;
                if (prefix[mi] < prefix[i] + logk - 1e-9) {
                    lo = mi + 1;
                } else {
                    hi = mi;
                }
            }
            ans += lo - i - 1;
        }
        return ans;
    }
};