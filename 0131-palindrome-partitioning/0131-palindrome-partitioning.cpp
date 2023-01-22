class Solution {
public:
    
    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results; 
        vector<string> currentList;
        dfs(results, s, 0, currentList);
        return results;
    }
    
    
    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList){
        if(start>=s.size()){
            result.push_back(currentList);
        }
        
        
        for(int end=start;end<s.size();end++){
            if(isPalindrome(s,start,end)){
                currentList.push_back(s.substr(start,end-start+1));
                dfs(result,s,end+1,currentList);
                currentList.pop_back();
            }
        }
    }
    
    
    
};