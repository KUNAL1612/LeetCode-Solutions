class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for(int i=1;i<9;i++){
            q.push(i);
        }
        
        while(!q.empty()){
            int a=q.front();
            q.pop();
            if(a<=high && a>=low){
                ans.push_back(a);
            }
            
            if (a > high)
                break;
            int d = a%10;
            if (d < 9)
                q.push(a*10 + d+1);
        }
        
        return ans;
    }
};