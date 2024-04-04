class Solution {
public:
    int maxDepth(string s) {
        int curr = 0;
        int m = 0;
        for(auto c:s){
            if(c=='('){
                curr++;
                m = max(m,curr);
            }
            else if(c==')'){
                curr--;
            }
        }
        return m;
        
    }
};