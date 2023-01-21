class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,1,string(1,s[0]),0,"");
        return res;
    }
    void backtracking(string& s, int index, string single, int dot, string total){
        if(dot > 3)
            return;
        else if(s.length() == index && dot == 3)
            res.push_back(total+'.'+single);
        else if(s.length() > index){
            //take it into single
            if(stoi(single+s[index]) < 256 && (single.length()== 0 || single[0] != '0'))
                backtracking(s,index+1,single+s[index],dot,total);
            //close up single and continue
            backtracking(s,index+1,string(1,s[index]),dot+1,(total.length()==0)?single:total+'.'+single);
        }
    }
};