class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(),s.end());
        int end=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(s.begin()+start,s.begin()+end);
                start=i+1;
                end=start;
            }
            else{
                end++;
            }
        }
        reverse(s.begin()+start,s.begin()+end);
    }
};