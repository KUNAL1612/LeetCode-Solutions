class FileSystem {
public:
    struct TrieNode {
        string name;
        int val = -1;
        unordered_map<string, TrieNode*> map;
        
        TrieNode (string name) : name(name) {}
    };
    
    TrieNode* root;
    
    
    FileSystem() {
        root = new TrieNode("");
    }
    
    bool createPath(string path, int value) {
        istringstream pss(path);
        string temp;
        vector<string> pathSplit;
        while(getline(pss,temp,'/')){
            if (!temp.empty()) {  // Check if the component is not empty
            pathSplit.push_back(temp);
        }
        }
        
        TrieNode* curr = root;
        for(int i=0;i<pathSplit.size();i++){
            string currPath = pathSplit[i];
            if(curr->map.find(currPath) == curr->map.end()){
                if(i == pathSplit.size()-1){
                    curr->map[currPath] = new TrieNode(currPath);
                }
                else{
                    return false;
                }
            }
            
            curr = curr->map[currPath];
        }
        
        if(curr->val!=-1){
            return false;
        }
        curr->val = value;
        return true;
    }
    
    int get(string path) {
        istringstream pss(path);
        string temp;
        vector<string> pathSplit;
        while(getline(pss,temp,'/')){
            if (!temp.empty()) {  // Check if the component is not empty
            pathSplit.push_back(temp);
        }
         
        }
        TrieNode* curr = root;
        for(int i=0;i<pathSplit.size();i++){
            string currPath = pathSplit[i];
            if(curr->map.find(currPath) == curr->map.end()){
                return -1;
            }
            curr = curr->map[currPath];
        }
        
        return curr->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */