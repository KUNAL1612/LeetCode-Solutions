class Solution {
public:
    
    
    void solve(int num, long long max_number, int k, vector<int> &ans){
        if(num >= max_number) {
            ans.push_back(num);
            return;
        }
        
        int digit = num % 10;
        int l = digit - k;
        int r = digit + k;
        
        if(l >= 0) solve((num * 10) + l, max_number, k, ans);
        if(l != r && r <= 9) solve((num * 10) + r, max_number, k, ans);
        return;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        long long max_number = 1;
        for(int i=1 ; i<n ; ++i) max_number *= 10;         
        for(int i=1 ; i<=9 ; ++i){
            solve(i,max_number,k,ans);
        }
        return ans;
    }
};