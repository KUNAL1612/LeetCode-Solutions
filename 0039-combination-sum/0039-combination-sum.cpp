class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int i=0;i<candidates.size();i++){
            check(candidates,i,target, 0);
        }
        return ans;
        
    }
    void check(vector<int>& candidates, int i, int target, int sum){
        if(candidates[i]+sum>target || i==candidates.size()){
            return;
        }
        res.push_back(candidates[i]);
        sum=sum+candidates[i];
        if(sum==target){
            ans.push_back(res);
        }
        else{
            for(;i<candidates.size();++i){
                check(candidates,i,target,sum);
            }
            
        }
        res.pop_back();
    }
};