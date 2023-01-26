class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        unordered_map<int,vector<pair<int,int>>> connections;
        
        for(auto flight:flights){
            connections[flight[1]].push_back({flight[0], flight[2]});
        }
        vector<vector<int>> dp(k+2, vector<int> (n,INT_MAX));
        dp[0][src] = 0; //beginning
        for(int i=1;i<=k+1;i++){
            
            for(int j=0;j<n;j++){
                
                for(auto edge:connections[j]){
                    
                    if(dp[i-1][edge.first]!=INT_MAX){
                        
                        // we can go to the src with one less edge
                        dp[i][j] = min(dp[i][j] ,dp[i-1][edge.first] + edge.second);
                    }
                }
                
                dp[i][j] = min(dp[i-1][j], dp[i][j]); // for if we already reached this node with lesser edges, or lesser stops
                
            }
             
        }
        return dp[k+1][dst] < INT_MAX? dp[k+1][dst] : -1;
        
    }
};

// this is bellman ford. good algorithm. 