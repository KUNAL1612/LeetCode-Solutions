class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        
        vector<pair<int, int>> steps = 
        {
            {2, 1},
            {1, 2},
            {-1, 2},
            {-2, 1},
            {-2, -1},
            {-1, -2},
            {1, -2},
            {2, -1},
        };
        unordered_map<int, unordered_map<int, bool>> visited;
        queue<pair<int, int>> Q;
        Q.push(make_pair(0, 0));
        visited[0][0] = true;
    
        int ans = 0;
        
        while (!Q.empty())
        {
            ans++;
            int len = Q.size();
            for (size_t i = 0; i < len; i++)
            {
                auto curr = Q.front();
                Q.pop();

                for (const auto& step : steps)
                {
                    int nextX = curr.first + step.first;
                    int nextY = curr.second + step.second;

                    if (nextX == x && nextY == y)
                    {
                        return ans;
                    }
                    // ideas from https://leetcode.com/problems/minimum-knight-moves/discuss/387000/c++-bfs-solution/418539
					// one long move or two short moves into negative direction in order to have access to (0,1) and similar targets
                    if(!visited[nextX][nextY])
                    {
                        visited[nextX][nextY] = true;
                        Q.push(make_pair(nextX, nextY));
                    }
                }
            }
        }
        
        return -1;
    }
};