class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balance = 0; //count left - count right
        int open_count = 0;
        string firstPass = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                // add it for now, if there are extras we will remove them later
                open_count++;
                balance++;
                firstPass += s[i];
            }
            else if(s[i] == ')'){
                if(balance==0){
                    continue;
                }
                balance--;
                firstPass += s[i];
            }
            else{
                //just a normal character
                firstPass += s[i];
            }
        }
        
        
        string finalResult = "";
        // remaining opening brackets = balance
        // these can all be removed from the end
        for(int i = firstPass.size()-1;i>=0;i--){
            if(firstPass[i] == '(' && balance>0){
                balance--;
                continue;
            }
            finalResult += firstPass[i];
        }
        reverse(finalResult.begin(),finalResult.end());
        return finalResult;
    }
};