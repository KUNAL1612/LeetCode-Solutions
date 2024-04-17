// class AllOne {
// public:
//   set<pair<int,string>>st;
//   unordered_map<string,int> table;
  
//   void inc(string key) {
//     if(table.count(key)) st.erase({table[key], key});
//       st.insert({table[key]+1,key});
//       table[key] += 1;
//   }
    
  
//   void dec(string key) {
//      //no need to check since if dec is called it is guaranteed that string is present in table 
//     st.erase({table[key], key}); 
//     if(--table[key] != 0) st.insert({table[key], key});
//   }
    
//   string getMaxKey() {
//     // rbegin is reverse iterator
//      if(!st.empty()){
//          return st.rbegin()->second;
//      }
//      else{
//          return "";
//      }
//   }
    
  
//   string getMinKey() {
//     return st.empty() ? "" : st.begin()->second;    
//   }
// };


// #include <unordered_map>
// #include <list>
// #include <string>

// using namespace std;

// Define a bucket structure to hold strings with the same count
struct Bucket {
    int count;
    unordered_set<string> keys;
};

class AllOne {
private:
    unordered_map<string, list<Bucket>::iterator> keyMap; // Map to store key and its corresponding iterator in the buckets list
    list<Bucket> buckets; // Doubly linked list of buckets

public:
    /** Initialize your data structure here. */
    AllOne() {}

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (keyMap.find(key) == keyMap.end()) {
            // If key doesn't exist, insert it into a new bucket with count 1
            if (buckets.empty() || buckets.front().count != 1) {
                // If there are no buckets or the first bucket's count is not 1, insert a new bucket at the beginning
                buckets.push_front({1, {key}});
            } else {
                // Otherwise, insert the key into the first bucket
                buckets.front().keys.insert(key);
            }
            keyMap[key] = buckets.begin(); // Update the key's iterator in the map
        } else {
            // If key already exists, increment its count
            auto curBucket = keyMap[key];
            auto nextBucket = next(curBucket);
            if (nextBucket == buckets.end() || nextBucket->count != curBucket->count + 1) {
                // If the next bucket doesn't exist or its count is not curBucket's count + 1, create a new bucket
                nextBucket = buckets.insert(nextBucket, {curBucket->count + 1, {}});
            }
            nextBucket->keys.insert(key); // Insert the key into the next bucket
            keyMap[key] = nextBucket; // Update the key's iterator in the map

            // Remove the key from the current bucket
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) {
                // If the current bucket becomes empty, remove it
                buckets.erase(curBucket);
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (keyMap.find(key) == keyMap.end()) return; // Key not found
        
        auto curBucket = keyMap[key];
        if (curBucket->count == 1) {
            // If the count is 1, remove the key from the map and the current bucket
            keyMap.erase(key);
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) {
                // If the current bucket becomes empty, remove it
                buckets.erase(curBucket);
            }
        } else {
            // Decrement the count of the key
            auto prevBucket = prev(curBucket);
            if (prevBucket == buckets.end() || prevBucket->count != curBucket->count - 1) {
                // If the previous bucket doesn't exist or its count is not curBucket's count - 1, create a new bucket
                prevBucket = buckets.insert(curBucket, {curBucket->count - 1, {}});
            }
            prevBucket->keys.insert(key); // Insert the key into the previous bucket
            keyMap[key] = prevBucket; // Update the key's iterator in the map

            // Remove the key from the current bucket
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) {
                // If the current bucket becomes empty, remove it
                buckets.erase(curBucket);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (buckets.empty()) return ""; // No elements
        return *(buckets.back().keys.begin()); // Get the first key in the last bucket
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (buckets.empty()) return ""; // No elements
        return *(buckets.front().keys.begin()); // Get the first key in the first bucket
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */