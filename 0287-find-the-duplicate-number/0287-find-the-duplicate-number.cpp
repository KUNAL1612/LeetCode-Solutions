class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len=nums.size();
        if(len==0){
            return 0;
        }
        int tortoise=nums[0];
        int hare=nums[0];
        do{
            tortoise=nums[tortoise];
            hare=nums[nums[hare]]; //double forward
        }while(tortoise!=hare);
        
        tortoise=nums[0];
        while(tortoise!=hare){
            tortoise=nums[tortoise];
            hare=nums[hare];
        }
        return hare;
    }
};


// loop from fast and slow pointers