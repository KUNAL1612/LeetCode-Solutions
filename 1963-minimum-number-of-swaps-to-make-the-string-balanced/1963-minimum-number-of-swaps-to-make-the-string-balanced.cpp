class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        for(auto c : s) {
            if(c == ']') {
                if(open) open--;
                
            } 
            else open++;
        }
        int ans = (open + 1) / 2; //  so because we don't need to swap out every open bracket and every close bracket. Consider the example below where only one swap will balance both the imbalanced opening brackets. 
        return ans;
    }
};

// [ ] [ ] [ [ ] [ ] [ ] ]