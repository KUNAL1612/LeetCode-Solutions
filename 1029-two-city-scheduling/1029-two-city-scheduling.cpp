class Solution {
public:
    static bool sort_order(vector<int> a, vector<int> b){
        int diff1=a[1]-a[0];
        int diff2=b[1]-b[0];
        return diff1>diff2;
    } // how much you gain by choosing one over the other
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), sort_order);
        int res=0;
        int i=0;
        for(;i<costs.size()/2;i++){
            res+=costs[i][0];
        }
        for(;i<costs.size();i++){
            res+=costs[i][1];
        }
        return res;
        
    }
};