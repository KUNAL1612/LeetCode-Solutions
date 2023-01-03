class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        for(int i=0;i<strs.size()-1;i++){
            if(strs[i].size() != strs[i+1].size()){
                return -1;
            }
        }
        int res = 0;
        int num = strs[0].size();
        for(int j=0;j<num;j++){
            for(int i=0;i<strs.size()-1;i++){
                if(strs[i][j] > strs[i+1][j]){
                    res++;
                    break;
                }
            }
        }
        return res;
        
    }
};

// r r j k
// f u r t
// g u z m