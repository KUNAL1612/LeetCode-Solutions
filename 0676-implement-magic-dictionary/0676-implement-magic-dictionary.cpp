class MagicDictionary {
    unordered_set<string> words;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(string word : dictionary){
            words.insert(word);
        }
    }
    
    bool search(string searchWord) {
        for(int i = 0; i <searchWord.size(); i++){
            char ch = searchWord[i];
            for(char c = 'a'; c <= 'z'; c++){
                if(c == ch)
                    continue;
                else{
                    searchWord[i] = c;
                    if(words.find(searchWord)!= words.end())
                        return true;
                }
            }
            searchWord[i] = ch;
        }
        return false;
    }
};


// assuming I have the trie set up properly

// (trieNode, int i, int flag, string input){
//     if( i == input.size() && flag>=0){
//         return true;
//     }
//     if(TrieNode -> next[i] != NULL){
//         (trieNode, i+1, flag, input);
//     }
//     else{
//         if(flag == 0){
//             return false;
//         }
//         flag--;
//         for(int i.= 0; i<26;i++){
            
//         }
//     }
// }

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */