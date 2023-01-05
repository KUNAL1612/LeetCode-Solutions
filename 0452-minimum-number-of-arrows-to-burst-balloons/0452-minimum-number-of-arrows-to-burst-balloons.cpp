class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0){
            return 0;
        }
        sort(points.begin(),points.end());
        vector<int> curr=points[0];
        int ans=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>curr[1]){
                ans++;
                curr=points[i];
            }
            else{
                curr[0]=max(points[i][0], curr[0]);
                curr[1]=min(curr[1],points[i][1]);
            }
        }
        
        
        return ans;
    }
};
