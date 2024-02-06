class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        // track first index of prefix sum % K
        unordered_map<int,int>track;
        
        // prefix sum
        int sum = 0;
        int n = nums.size();
        
        // prefix sum % K == 0 sequence can only occur from index 0 
        track[0] = -1;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            sum %= k;   // get prefix sum % K 
            
            // if the perfix sum % K exists in the Map
            // if then get the index pos and get length and check if sequence length > 1
            // if then return true
            if(track.count(sum)>0)
            {
                if((i-track[sum])>1) return true;                
            }
            else track[sum] = i;    // store the first occurence of prefix sum % K
        }
        
        return false;   // no multiple found and so return false
    }
};

// a map or a set for O(1)