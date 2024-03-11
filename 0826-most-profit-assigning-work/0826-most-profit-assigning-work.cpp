class Solution {
public:
    bool customComparator(const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<vector<int>> point;
        for(int i=0;i<n;i++){
            vector<int> temp = {difficulty[i], profit[i]};
            point.push_back(temp);
        }
        sort(point.begin(), point.end());
        
        vector<int> maxProfitAt(n,-1);
        maxProfitAt[0] = point[0][1];
        for(int i=1;i<n;i++){
            maxProfitAt[i] = max(maxProfitAt[i-1], point[i][1]);
        }
        
        int result = 0;
        for(int i=0;i<worker.size();i++){
            int j =0;
            while(j<n){
                if(point[j][0] <= worker[i]){
                    j++;
                }
                else{
                    break;
                }
            }
            
            j--;
            j>=0? result+=maxProfitAt[j] : result+=0;
            
        }
        
        return result;
    }
};