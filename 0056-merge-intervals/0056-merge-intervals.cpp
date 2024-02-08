class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& l, vector<int>& r) {return l[0] < r[0];});
        vector<vector<int>> ans;
        for (vector<int>& interval : intervals) {
            if (!ans.empty() && ans.back()[1] >= interval[0]) {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            } else {
                ans.push_back(interval);
            }
        }
        return ans;
    }
};