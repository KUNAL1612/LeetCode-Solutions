class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int val= -1; int v= INT_MAX;
        for (int i=0; i<points.size(); i++){
            if (x!=points[i][0] && y!= points[i][1])continue;
            if (v > (abs(points[i][0]-x)+abs(points[i][1]-y))){
                val= i; 
                v=(abs(points[i][0]-x)+abs(points[i][1]-y));}
        }
        return val;
    }
};