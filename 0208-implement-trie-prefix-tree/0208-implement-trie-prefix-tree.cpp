

struct Node{
    Node* next[26];
    bool end;
    Node(){
        for(int i=0;i<26; i++){
            next[i] = NULL;
        }
        end = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root; //dummy head 
    Trie() {
        root=new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len=word.size();
        Node *temp = root;
        for(int i=0;i<len;i++){
            int index=word[i]-'a';
            if(temp->next[index]==NULL){
                Node* newNode=new Node();
                temp->next[index]=newNode;
                temp=newNode;
            }
            else{
                temp=temp->next[index];
            }
        }
        temp->end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len=word.size();
        struct Node* temp=root;
        for(int i=0;i<len;i++){
            int index=word[i]-'a';
            if(temp->next[index]==NULL){
                return false;
            }
            temp=temp->next[index];
        }
        return temp->end==true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len=prefix.size();
        struct Node* temp=root;
        for(int i=0;i<len;i++){
            int index=prefix[i]-'a';
            if(temp->next[index]==NULL){
                return false;
            }
            temp=temp->next[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
