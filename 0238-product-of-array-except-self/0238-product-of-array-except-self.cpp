class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int len=nums.size();
        if(len==0){
            return ans;
        }
        vector<int> L(len,1);
        vector<int> R(len,1);
        L[0]=1; R[len-1]=1;
        for(int i=len-2;i>=0;i--){
            R[i]=R[i+1]*nums[i+1];
        }
        for(int i=1;i<len;i++){
            L[i]=L[i-1]*nums[i-1];
        }
        for(int i=0;i<len;i++){
            ans.push_back(L[i]*R[i]);
            
        }
        return ans;
    }
};