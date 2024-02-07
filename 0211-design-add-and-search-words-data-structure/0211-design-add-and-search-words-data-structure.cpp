struct Node{
    bool end;
    struct Node* next[26];
    Node(){
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
        end=false;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int len=word.size();
        struct Node* temp=root;
        for(int i=0;i<len;i++){
            int index=word[i]-'a';
            if(temp->next[index]==NULL){
                struct Node* newNode=new Node();
                temp->next[index]=newNode;
                temp=newNode;
            }
            else{
                temp=temp->next[index];
            }
        }
        temp->end=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search2(word, 0, root);
    }
    bool search2(string word, int where, Node* root){
        if (where==word.length()) return root->end; // the dot represents where we are right now
        if (word[where]=='.'){
            for(int i=0;i<26;i++) {
                word[where] = 'a'+i; // temporarily setting the dot for something else
                if (search2(word, where, root)) return 1;
                word[where] = '.';
            }
            return 0;
        }
        if(root->next[word[where]-'a'])
            return search2(word, where+1, root->next[word[where]-'a']);
        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */