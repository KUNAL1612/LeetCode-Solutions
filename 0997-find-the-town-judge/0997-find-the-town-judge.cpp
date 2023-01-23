class Solution {
public:
    
    int ans=-1;
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int>> adjacency;
        vector<int> visited (N,0);
        for(int i=0;i<trust.size();i++){
            visited[trust[i][1]-1]++;
        }
        bool one=false;
        vector<int> s;
        for(int i=0;i<N;i++){
            if(visited[i]==N-1){
                s.push_back(i+1);
                
            }
        }
        for(int i=0;i<s.size();i++){
            int t=s[i];
            ans=s[i];
            for(int j=0;j<trust.size();j++){
                if(trust[j][0]==t){
                    ans=-1;
                    break;
                }
            }
        }
        
        return ans;
        
    }
};