class Solution {
public:
    bool detectCapitalUse(string word) {
        int tot_caps = 0;
        for(int i=1;i<word.size();i++){
            if(isupper(word[i])){
                tot_caps++;
            }
        }
        
        if(tot_caps == 0){
            return true; // no caps at all
        }
        
        if(tot_caps == word.size()-1 && isupper(word[0])){
            return true;
        }
        
        return false;
    }
};