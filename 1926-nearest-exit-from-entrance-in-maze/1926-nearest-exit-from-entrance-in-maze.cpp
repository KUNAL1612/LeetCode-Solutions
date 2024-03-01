class Solution {
public:
//     int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
//         // if entrance itself is a wall return -1
//         // initially set maze[entrance[0]][entrance[1]] = 
        
//         queue<pair<int,int>> q;
//         int m = maze.size();
//         int n = maze[0].size();
//         vector<pair<int,int>> directions{{0,1},{1,0},{-1,0},{0,-1}};
//         q.insert({entrace[0], entrance[1]});
//         while(!q.empty()){
//             auto& r = q.front();
//             q.pop();
//             for(auto direction:directions){
                
//             }
//         }
//         return 1;
//         // for(int i=0;i<m;i++){
//         //     for(int j=0;j<n;j++){
//         //         if(maze[i][j])
//         //     }
//         // }
            
        
//     }
    
    int nearestExit(vector<vector<char>>& a, vector<int>& e) {
    int n=a.size();
    int m=a[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    if(a[e[0]][e[1]]=='+') return -1;
    q.push({e[0],e[1]});
    vis[e[0]][e[1]]=1;
    vector<pair<int,int>> mu{
        {1,0},{0,1},
        {-1,0},{0,-1}
    };
    int c=0;
    while(!q.empty()){
        int sz=q.size();
        c++;
        while(sz--){
            auto x=q.front();
            q.pop();
            for(auto mo : mu){
                int nx=x.first+mo.first,ny=x.second+mo.second;
                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && a[nx][ny]=='.'){
                    if(nx==0 || ny==0 || nx==n-1 || ny==m-1) return c;
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
    }
    return -1;
}
};