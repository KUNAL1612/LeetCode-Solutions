class Solution {
public:
    
//     int boolsearch(vector<vector<int>>& intervals,bool lower, int n, int i){
//         if(lower==true){
            
//         }
        
    // }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
        int i = 0;
        vector<vector<int>> resultInterval;
        while(i <  intervals.size() && newInterval.front() > intervals[i].back())
        {
            resultInterval.push_back(intervals[i]);
            i++;
        }
         while(i <  intervals.size() &&  intervals[i].front() <=  newInterval.back())
         {
             newInterval.front() = min ( newInterval.front() , intervals[i].front());
             newInterval.back() = max ( newInterval.back() , intervals[i].back());
             i++;
         }
        resultInterval.push_back(newInterval);
        while(i <  intervals.size())
        {
            resultInterval.push_back(intervals[i]);
            i++;
        }
        return resultInterval;
    }
};