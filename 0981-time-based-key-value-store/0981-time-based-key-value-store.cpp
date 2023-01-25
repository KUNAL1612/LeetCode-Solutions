class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto find = mp[key].upper_bound(timestamp); // find the best up to that time
        if(find == mp[key].begin()) return ""; // nothing found
        find--; // find is one indexed
        return find->second;
    }
};