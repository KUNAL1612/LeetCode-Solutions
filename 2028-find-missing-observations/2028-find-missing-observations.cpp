class Solution {
public:
    vector<int> ans;
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int target = (mean * (n + m)) - sum;
        if(target < n || target > 6 * n) return {};
        if(n == 1) return {target};
        int rem = target%n;
        for(int i = 1; i <= n; i++){
            ans.push_back(target/n);
            if(rem > 0) {ans[i - 1] += 1; rem--;}
        }
        
        return ans;
    }
};