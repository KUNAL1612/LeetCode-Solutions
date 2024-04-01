class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string temp;
        int ans;
        while (getline(iss,temp,' ')){
            if(temp.size()!=0){
                ans = temp.size();
            }
            
        }
        return ans;
    }
};