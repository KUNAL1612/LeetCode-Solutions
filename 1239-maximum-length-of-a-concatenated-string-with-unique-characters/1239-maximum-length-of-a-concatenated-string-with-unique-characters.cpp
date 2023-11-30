class Solution {
public:
    int maxLength(vector<string>& arr) {
        int res = 0;
        string s = "";
        for(int i = 0; i < arr.size(); i++)
           res = max(res ,backtrack(arr, s, i));
        
        return res;
        
    }
    
    int backtrack(vector<string>& arr, string str,  int start){
        
        unordered_set<char>s(str.begin(), str.end()); //this is important 
        if (s.size() != ((int)str.length())) 
            return 0;
        
        int ret = str.length();
        for (int i = start; i < arr.size(); i++)
            ret = max(ret, backtrack(arr, str+arr[i], i+1));

        return ret;
    }
    
};