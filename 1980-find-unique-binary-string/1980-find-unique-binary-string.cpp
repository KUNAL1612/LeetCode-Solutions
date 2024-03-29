// class Solution {
// public:
//     string findDifferentBinaryString(vector<string>& nums) {
//         unordered_set<int> integers;
//         for (string num : nums) {
//             integers.insert(stoi(num, 0, 2));
//         }
        
//         int n = nums.size();
//         for (int num = 0; num <= n; num++) {
//             if (integers.find(num) == integers.end()) { // maybe a hash to avoid O(n^2) search
//                 string ans = bitset<16>(num).to_string();
//                 return ans.substr(16 - n);
//             }
//         }
        
//         return "";
//     }
// };


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++) {
            char curr = nums[i][i];
            ans += curr == '0' ? '1' : '0';
        }
        
        return ans;
    }
};

// better answer: we know that there are only one character difference between two 
    