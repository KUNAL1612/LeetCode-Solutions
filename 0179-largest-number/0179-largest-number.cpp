class Solution {
public:
    
    static bool compare(int a, int b){
        string a1=to_string(a);
        string b1=to_string(b);
        string order1=a1+b1;
        string order2=b1+a1;
        return order2<order1;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        if(nums[0]==0){
            return "0";
        }
        string ans;
        for(auto i:nums){
            ans+=to_string(i);
        }
        
        return ans;
    }
};