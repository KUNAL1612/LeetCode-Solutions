class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> na(26,0);
        vector<int> nb(26,0);
        int n=s1.size();
        if(n>s2.size()){
            return false;
        }
        for(int i=0;i<n;i++){
            na[s1[i]-'a']++;
            nb[s2[i]-'a']++;
        }
        if(na==nb){
            return true;
        }
        for(int i=n;i<s2.size();i++){
            nb[s2[i]-'a']++;
            nb[s2[i-n]-'a']--;
            if(na==nb){
                return true;
            }
            
        }
        return false;
    }
};
