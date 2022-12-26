class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        // create 3x array
        // index + len 
        // find smallest modulo of distance
        
        if(words.size()==0){
            return -1;
        }
        
        if(words[startIndex] == target){
            return 0;
        }
        
        vector<string> new_words;
        for(int i=0;i<3;i++){
            for(auto st:words){
                new_words.push_back(st);
            }
        }
        
        unordered_map<string, vector<int>> dists;
        for(int i=0;i<new_words.size();i++){
            dists[new_words[i]].push_back(i);
        }
        
        int retval = INT_MAX;
        // cout<<startIndex + words.size();
        for(auto ind:dists[target]){
            cout<<ind<<endl;
            int val = ind - startIndex - words.size();
            retval = min(retval, abs(val));
        }
        
        return retval<INT_MAX? retval:-1;
    }
};