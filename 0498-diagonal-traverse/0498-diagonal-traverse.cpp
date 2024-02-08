// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
//     }
// };

// 1 2 3 
    
// 4 5 6
    
// 7 8 9
    
//     // all items on the same diagonal have the same x,y coordinate sums
//     // alternate diagonals have even/odd sums
    
    
    class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix) {
        std::map<int, std::vector<int>> d;

        // Loop through matrix
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                // If no entry in dictionary for the sum of indices (diagonal), create one
                if (d.find(i + j) == d.end()) {
                    d[i + j] = {matrix[i][j]};
                } else {
                    // If you've already passed over this diagonal, keep adding elements to it
                    d[i + j].push_back(matrix[i][j]);
                }
            }
        }

        // We're done with the pass, let's build our answer array
        std::vector<int> ans;

        // Look at the diagonal and each diagonal's elements
        for (const auto& entry : d) {
            // Snake time, look at the diagonal level
            if (entry.first % 2 == 0) {
                // Here we append in reverse order because it's an even-numbered level/diagonal
                for (auto it = entry.second.rbegin(); it != entry.second.rend(); ++it) {
                    ans.push_back(*it);
                }
            } else {
                for (auto& x : entry.second) {
                    ans.push_back(x);
                }
            }
        }
        
        return ans;
    }
};