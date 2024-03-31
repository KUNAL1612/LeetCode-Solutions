class Solution {
public:
    vector<int> findAnagrams(string p, string s) {
        //same as leet 567
        vector<int> ans;
        vector<int> sp(26,0);
        vector<int> pp(26,0);
        
        int n=s.size();
        if(n>p.size()){
            return ans;
        }
        
        for(int i=0;i<n;i++){
            sp[s[i]-'a']++;
            pp[p[i]-'a']++;
        }
        if(sp==pp){
            
            ans.push_back(0);
        }
        for(int i=n;i<p.size();i++){
            pp[p[i]-'a']++; // move the sliding window
            pp[p[i-n]-'a']--;
            if(sp==pp){ //vector equality works!!!
                ans.push_back(i-n+1);
            }
        }
        return ans;
        
    }
};