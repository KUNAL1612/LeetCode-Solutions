class Solution {
public:
// vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         // Initialize binary search bounds
//         int left = 0;
//         int right = arr.size() - k;

//         // Binary search against the criteria described
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             if (x - arr[mid] > arr[mid + k] - x) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }

//         // Create output in correct format
//         vector<int> result(arr.begin() + left, arr.begin() + left + k);

//         return result;
//     }
    
//     vector<int> findClosestElements(vector<int>& arr, int k, int x){
        
        
        
        
//     }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        
        // Base case
        if (arr.size() == k) {
            for (int i = 0; i < k; i++) {
                result.push_back(arr[i]);
            }
            
            return result;
        }
        
        // Binary search to find the closest element
        int left = 0;
        int right = arr.size();
        int mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // 1 3 5 7    -  4
        
        // Initialize our sliding window's bounds
        left -= 1;
        // right = left + 1;
        
        // While the window size is less than k
        while (right - left - 1 < k) {
            // Be careful to not go out of bounds
            if (left == -1) {
                right += 1;
                continue;
            }
            
            // Expand the window towards the side with the closer number
            // Be careful to not go out of bounds with the pointers
            if (right == arr.size() || abs(arr[left] - x) <= abs(arr[right] - x)) {
                left -= 1;
            } else {
                right += 1;
            }
        } 

        // Build and return the window
        for (int i = left + 1; i < right; i++) {
            result.push_back(arr[i]);
        }
        
        return result;
    }
};