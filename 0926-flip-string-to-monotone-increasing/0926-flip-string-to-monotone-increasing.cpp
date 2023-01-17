class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> ones(s.size(),0);
        vector<int> zeros(s.size(),0);
        ones[0]=s[0]-'0';
        // these vectors have so far counts
        // first checking right most 0 and all 1's in it 
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                ones[i]=ones[i-1]+1;
            }
            else{
                ones[i]=ones[i-1];
            }
        }
        zeros[s.size()-1]=s[s.size()-1]=='1'?0:1;
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]=='0'){
                zeros[i]=zeros[i+1]+1;
            }
            else{
                zeros[i]=zeros[i+1];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<s.size()-1;i++){
            ans=min(ans, ones[i]+zeros[i+1]);
        }
        int a=min(zeros[0],ones[s.size()-1]);
        ans=min(a,ans);
        return ans;
    }
};