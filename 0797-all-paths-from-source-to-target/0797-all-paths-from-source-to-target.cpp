class Solution {
public:
    
    vector<vector<int>> paths;
    
    void backstrack(vector<vector<int>>& graph, vector<int>& visited, int curr, vector<int>& p){
        if(curr==graph.size()-1){
            paths.push_back(p);
            return;
        }
        
        int len=graph[curr].size();
        
        for(int i=0;i<len;i++){
            if(!visited[graph[curr][i]]){
                visited[graph[curr][i]]=1;
                p.push_back(graph[curr][i]);
                backstrack(graph,visited,graph[curr][i],p);
                visited[graph[curr][i]]=0;
                p.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size(); //this bit is weird but they do mention that graph.size = n 
        vector<int> visited(n,0);
        vector<int> p;
        p.push_back(0);
        visited[0]=1;
        backstrack(graph,visited, 0, p);
        return paths;
    }
};