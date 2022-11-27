/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int cnt = 0;
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        
        dfs(sea, topRight, bottomLeft, cnt);
        return cnt;
    }
    
    inline void dfs(Sea sea, vector<int> topRight, vector<int> bottomLeft, int &cnt) {
        int horizontalDis = topRight[0] - bottomLeft[0];
        int verticalDis = topRight[1] - bottomLeft[1];
        if (horizontalDis == 0 && verticalDis == 0) {
            // just one point
            cnt += (int)sea.hasShips(topRight, bottomLeft);
            return;
        }
        if (horizontalDis > verticalDis) { // splitting along the major axis instead of always picking the same axes
            int end = bottomLeft[0] + horizontalDis / 2;
            if (sea.hasShips({end, topRight[1]}, bottomLeft)) {
                // left half 
                dfs(sea, {end, topRight[1]}, bottomLeft, cnt);
            } 
            if (sea.hasShips(topRight, {end + 1, bottomLeft[1]})) {
                // right half 
                dfs(sea, topRight, {end + 1, bottomLeft[1]}, cnt);
            }
        } else {
            int end = bottomLeft[1] + verticalDis / 2;
            if (sea.hasShips({topRight[0], end}, bottomLeft)) {
                dfs(sea, {topRight[0], end}, bottomLeft, cnt);
                // top half
            }
            if (sea.hasShips(topRight, {bottomLeft[0], end + 1})) {
                dfs(sea, topRight, {bottomLeft[0], end + 1}, cnt);
                // bottom half
            }
        }
    }
};