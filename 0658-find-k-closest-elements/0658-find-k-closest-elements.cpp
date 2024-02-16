class Solution {
public:
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Initialize binary search bounds
        int left = 0;
        int right = arr.size() - k;

        // Binary search against the criteria described
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Create output in correct format
        vector<int> result(arr.begin() + left, arr.begin() + left + k);

        return result;
    }
};