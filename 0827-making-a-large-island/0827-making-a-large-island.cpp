class Solution {
public:
    
    unordered_map<int,int> id_to_area;
    int recent_id = 10;
    int calc_area(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>= grid.size() || j>=grid[0].size() || grid[i][j] != 1){
            return 0;
        }
        
        
        
        grid[i][j] = recent_id;
        int area = 1;
        area += calc_area(grid,i-1,j);
        area += calc_area(grid,i+1,j);
        area += calc_area(grid,i,j-1);
        area += calc_area(grid,i,j+1);
        
        return area;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int max_island = INT_MIN;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int area = calc_area(grid,i,j);
                if(area!=0){
                    max_island = max(max_island, area);
                    id_to_area[recent_id] = area;             
                    recent_id++;
                }
            }
        }
        
        int retval = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                   unordered_set<int> areas;
                    if(i>0){
                        areas.insert(grid[i-1][j]);
                    }
                    if(j>0){
                        areas.insert(grid[i][j-1]);
                    }
                    if(i<grid.size()-1){
                        areas.insert(grid[i+1][j]);
                    }
                    if(j<grid.size()-1){
                        areas.insert(grid[i][j+1]);
                    }
                    
                    int val = 1;
                    for(auto id:areas){
                        val += id_to_area[id];
                    }
                    retval = max(val,retval);
                }
                
            }
        }
        
        return retval>0? retval:max_island;
        
    }
};