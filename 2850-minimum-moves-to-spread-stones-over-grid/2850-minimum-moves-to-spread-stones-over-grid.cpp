class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        // Base Case
        bool flag=true;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]!=1) flag=false;
            }
        }
        if(flag) return 0;
        // list of >1
        // list of 0's
        
        int ans=INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int k=0;
                if(grid[i][j]==0){
                    for(int a=0;a<3;a++)
                    {
                        for(int b=0;b<3;b++){
                            if(grid[a][b]>1){
                                grid[a][b]--;
                                grid[i][j]++;
                                k+=abs(i-a);
                                k+=abs(j-b);
                                ans=min(ans,k+minimumMoves(grid));
                                grid[a][b]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }

        }
        return ans;
    }
};

