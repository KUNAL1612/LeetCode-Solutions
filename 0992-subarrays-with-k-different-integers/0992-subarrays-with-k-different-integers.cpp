class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0, i = 0, j = 0, k = 0, N = A.size();
        unordered_map<int, int> m;
        while (j < N) {
            m[A[j] - '0'] = j; // last occurence of a character/number
            ++j;
            while (m.size() > K) {
                int d = A[i++] - '0';
                if (m[d] < i) m.erase(d); // double of a character
            }
            if (m.size() == K) {
                k = max(i, k); 
                while (m[A[k] - '0'] != k) ++k;
                ans += k - i + 1;
            }
        }
        return ans;
    }
};