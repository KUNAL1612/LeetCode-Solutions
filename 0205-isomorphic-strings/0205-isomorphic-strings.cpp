class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        set<char> s1;      
        unordered_map<char,char> m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end()){
                s[i]=m[s[i]];
                if(s[i]!=t[i]){
                    return false;
                }
                
            }
            else{
                m[s[i]]=t[i];
                if(s1.find(t[i])!=s1.end()){ // keys that already have a mapping and are in string t
                    return false;
                }
                s1.insert(t[i]);
            }
        }
        return true;
    }
};