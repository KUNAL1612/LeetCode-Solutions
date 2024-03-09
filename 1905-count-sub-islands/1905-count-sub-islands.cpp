class Solution {
public:
    int c;
    void dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2,int i,int j)
    {
        if(i<0||j<0||i>=grid2.size()||j>=grid2[0].size()||grid2[i][j]==0)
        {
            return ;
        }
        if(grid1[i][j]==0)
        {
            c++;
            return ;
        }
        grid2[i][j]=0;
        dfs(grid1,grid2,i,j+1);
        dfs(grid1,grid2,i,j-1);
        dfs(grid1,grid2,i+1,j);
        dfs(grid1,grid2,i-1,j);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
      int i,j,f=0;
        for(i=0;i<grid2.size();i++)
        {
            for(j=0;j<grid2[0].size();j++)
            {
                if(grid2[i][j]&&grid1[i][j])
                {
                    c=0;
                    dfs(grid1,grid2,i,j);
                    if(c==0)
                    {
                        f++;
                    }
                }
            }
        }
        return f;
    }

};

// set of indices indicating an island