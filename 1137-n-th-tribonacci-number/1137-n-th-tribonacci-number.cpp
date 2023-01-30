class Tri{
private:
    
    int n = 38;
    vector<int> nums;
    
public:
    Tri(){
        nums = vector<int> (38,0);
        nums[0] = 0;
        nums[1] = 1;
        nums[2] = 1;
        for(int i=3;i<n;i++){
            nums[i] = nums[i-1] + nums[i-2] + nums[i-3];
        }
    }
    int get_val(int n){
        return nums[n];
    }
    
};
class Solution {

public:
    int tribonacci(int n) {
        Tri* t = new Tri();
        return t->get_val(n);
    }
};