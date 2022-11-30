class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> answer(n,0);
        deque<int> dq1;
        for(int curr_day = 0; curr_day < n; curr_day++){
            int curr_temp = T[curr_day];
            while(!dq1.empty() && T[dq1.back()] < curr_temp){
                int prev_day = dq1.back();
                dq1.pop_back();
                answer[prev_day] = curr_day - prev_day;
            }
            dq1.push_back(curr_day);
        }
        return answer;
    }
};
