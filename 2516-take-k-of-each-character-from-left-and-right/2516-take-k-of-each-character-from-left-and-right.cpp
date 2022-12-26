class Solution {
public:
    int takeCharacters(string s, int k) {
        int count_a=0,count_b=0,count_c=0;
        int n=s.size();
        int ans=n;
        for(int i=0;i<n;i++){
            if(s[i]=='a') count_a++;
            if(s[i]=='b') count_b++;
            if(s[i]=='c') count_c++;
        }
        if(count_a<k||count_b<k||count_c<k) return -1;
        int i=n-1,j=n-1;
        while(i>=0){
            if(s[i]=='a') count_a--;
            if(s[i]=='b') count_b--;
            if(s[i]=='c') count_c--;
            while(count_a<k||count_b<k||count_c<k){
            if(s[j]=='a') count_a++;
            if(s[j]=='b') count_b++;
            if(s[j]=='c') count_c++;
                j--;
            }
            ans=min(ans,i+n-1-j); i--;
        }
        return ans;
    }
};