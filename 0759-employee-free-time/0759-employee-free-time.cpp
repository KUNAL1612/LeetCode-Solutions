/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    map<int, int> time;
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        for (auto p:schedule){
            for (Interval i:p){
                time[i.start]++;
                time[i.end]--;
            }
        }
        vector<Interval> res;
        int started = -1, cur = 0;
        for (auto it=time.begin(); it!=time.end(); it++){
            cur += it->second;
            if (cur==0){
                started = it->first;
            }else if (started>=0){
                res.push_back(Interval(started, it->first));
                started = -1;
            }
        }
        return res;
    }
};