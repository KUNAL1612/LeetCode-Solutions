class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        vector<int> rooms;
        bool foundRoom = false;
        
        sort(intervals.begin(), intervals.end());
        rooms.push_back(intervals[0][1]);
        
        for (int i = 1; i < intervals.size(); i++) {
            for (int j = 0; j < rooms.size(); j++) {
                if (intervals[i][0] >= rooms[j]) {
                    rooms[j] = intervals[i][1];
                    foundRoom = true;
                    break;
                }
            }
            if (!foundRoom) rooms.push_back(intervals[i][1]);
            foundRoom = false;
        }
        
        return rooms.size();
    }
};

// rooms can be a pq instead of a vector