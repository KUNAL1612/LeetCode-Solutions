#define pii pair<int, int>
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pii>> g;
        vector<bool> visited(n);
        int count = 0;
        for(auto con: connections){
            g[con[0]].push_back({con[1], 1});
            g[con[1]].push_back({con[0], 0});
        }
        queue<int> q;
        q.push(0);
        while(q.size()){
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            for(auto p: g[curr]){
                if(!visited[p.first]){
                    count += p.second; // 0 if is the "right" direction and 1 if is inverted
                    q.push(p.first);
                }
            }
        }
        return count;
    }
};