// class Solution {
// public:
//     unordered_map<int, vector<int>> numstoIndices;
//     Solution(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++){
//             numstoIndices[nums[i]].push_back(i);
//         }
//     }
    
//     int pick(int target) {
//         int siz = numstoIndices[target].size();
//         int index_to_return = rand() % siz;
//         return numstoIndices[target][index_to_return];
//     }
// };


// class Solution {
// public:
//     vector<int> A;
//     Solution(vector<int>& nums) {
//         A = nums;
//     }
    
//     // C++: random = min + rand() % (max - min + 1) 
//     int pick(int target) {
//         int count = 0;
//         int res = -1;
//         for (int i = 0; i < A.size(); i++) {
//             if (A[i] == target) {
//                 if (res == -1) {  // this is important
//                     res = i;
//                 }
//                 count++;
//                 // int rand = 1 + std::rand() % (count - 1 + 1);
//                 int rand = 1 + std::rand() % count;  // so this value is going to be between 1 and count
//                 if (rand == count) {
//                     res = i;
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int count = 0;
        int res = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                count++;
                int random = rand()%count + 1;
                if (random == count) {
                    res = i;
                }
            }
        }
        return res;
    }
};




/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */