class Solution {
public:
    string removeDuplicates(string s) {
        if(s.size()<=1){
            return s;
        }
        stack<char> s1;
        string ans;
        s1.push(s[0]);
        int a=0;
        for(int i=1;i<s.size();i++){
            if(!s1.empty() && s1.top()==s[i]){
                s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }
        while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};