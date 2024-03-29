class Solution {
    int ret = 0 ;
    int k ;
    void dfs(vector<int>& nums, int cur, int prev, vector<int>&tmp){
        ret++ ;
        for(int i = cur+1; i < nums.size(); i++){
            bool flag = true ;
            for(auto& x : tmp){
                if((nums[i] - x) == k){
                    flag = false ;
                    break ;
                }
            }
            if(flag){ // this means it is possible to add nums[i] to it. 
                tmp.push_back(nums[i]) ;
                dfs(nums, i, nums[i], tmp) ;
                tmp.pop_back() ;
            }
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()) ;
        int n = nums.size() ;
        vector<int>tmp ;
        this->k = k ;
        for(int i = 0; i < n; i++){
            tmp.push_back(nums[i]) ;
            dfs(nums, i, nums[i], tmp) ;
            tmp.pop_back() ;
        }
        return ret ;
    }
};