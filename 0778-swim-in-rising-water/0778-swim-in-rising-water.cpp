class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int N = grid.size();
        if(N==0){
            return 0;
        }
        if(N == 1){
            return grid[0][0];
        }
        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push({-grid[0][0], make_pair(0,0)});
        vector<vector<bool>> visited(N, vector<bool> (N,false));
        // bool visited[N][N] {};
        visited[0][0] = true;
        
        const int di[] {-1, 1, 0, 0};
        const int dj[] {0, 0, -1, 1};
        int ij, i, j, ii, jj, val;
        while (true) {
            val = -pq.top().first;
            
            i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();
            
            for (int k = 0; k < 4; ++k) {
                ii = i + di[k];
                jj = j + dj[k];
                if (ii < 0 || ii == N || jj < 0 || jj == N) {
                    continue;
                }
                if (visited[ii][jj]) {
                    continue;
                }
                if (ii == N - 1 && jj == N - 1) {
                    return max(val, grid[ii][jj]);
                }                
                visited[ii][jj] = true;
                pq.push({-max(val, grid[ii][jj]), make_pair(ii,jj)});
            }
        }
    }
};