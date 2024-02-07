class Solution {
public:
    unordered_map<int, int> connect;
    
    void fillup(int n){
        for(int i=0;i<n;i++){
            connect[i] = i;
        }
    }
    
    void unionate(int x, int y){
        if(connect[x] == connect[y]){
            return;
        }
        
        int val_x = connect[x]; 
        int val_y = connect[y]; 
        for(auto& i:connect){
            if(i.second == val_y){
                i.second = val_x;
            }
        }
    }
    
    
    
    void add_edge(vector<vector<int>>& edges){
        for(int i=0;i<edges.size();i++){
            unionate(edges[i][0], edges[i][1]);
        }
    }
    
    bool checkval(){
        int val = connect[0];
        for(auto& i :connect){
            if(i.second != val){
                return false;
            }
        }
        return true;
    }
    
    
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return true;
        }
        
        if(edges.size() == 0){
            return false;
        }
        fillup(n);
        add_edge(edges);
        return checkval() && edges.size()==(n-1); // no cycles
        
    }
};