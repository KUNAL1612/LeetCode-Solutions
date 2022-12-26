class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastgoodindex=nums.size()-1;
        for(int i=lastgoodindex;i>=0;i--){
            if(i+nums[i]>=lastgoodindex){
                lastgoodindex=i;
            }
        }
        return lastgoodindex==0;
    }
};

// idea is to only check if it's possible to go back. So keep a min (or max) index that is reachable. Also only change it if the new last good index is lower. 