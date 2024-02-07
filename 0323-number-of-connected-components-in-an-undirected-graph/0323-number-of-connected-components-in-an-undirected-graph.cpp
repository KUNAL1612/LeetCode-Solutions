class Solution {
public:
    vector<int> parent;
    void unionset(int x, int y){
        int parentx=parent[x];
        int parenty=parent[y];
        if(true){
            for(int i=0;i<parent.size();i++){
                if(parent[i]==parenty){
                    parent[i]=parentx;
                }
            }
        }
    }
    int countunique(vector<int> &a){
        set<int> s1;
        for(auto y:a){
            s1.insert(y);
        }
        return s1.size();
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent=vector<int> (n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        for(auto edge:edges){
            unionset(edge[0],edge[1]);
        }
        
        return countunique(parent);
    }
};