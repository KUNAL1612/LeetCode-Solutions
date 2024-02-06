class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> triplet(3);
        int front, rear;
        
        sort(nums.begin(), nums.end());
        // [-1, 0, 1, 2, -1, -4] --> [-4, -1, -1. 0. 1, 2]
        
        // three pointer: one at current (the one we're trying to pair), one ahead slightly (as in we start from i+1), one at end.
        
        for (int i = 0; i<nums.size(); i++){
            int target = -nums[i]; // 4
            front = i+1; 
            rear = nums.size() - 1;
            while(front < rear){
                int sum = nums[front] + nums[rear];
                
                if (sum < target){
                    front++; // target not found sum too low so increase front
                } else if(sum > target){
                    rear--; // target not found sum too high so decrease rear
                } else{
                    //found
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[rear];
                    
                    
                    // we don't want duplicates for the front or back since if either of these are the same 
                    // since for [a,b,c] --> = -b -c so if -b is repeated and then -c is also repeated
                    while(front < rear && nums[front] == triplet[1])
                        front++;
                    while(front < rear && nums[rear] == triplet[2])
                        rear--;
                    result.push_back(triplet);
                }
            }
            while (i+1 < nums.size() && nums[i+1] == nums[i])
                i++; // repeated first digit
            
        }
        return result;
    }
};