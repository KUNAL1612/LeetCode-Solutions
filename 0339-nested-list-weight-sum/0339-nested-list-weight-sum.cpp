/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// class Solution {
// public:
//     int depthSum(vector<NestedInteger>& nestedList, int depth=1) {
//         int sum=0;
//         for(int i=0;i<nestedList.size();i++){
//             if(nestedList[i].isInteger()){
//                 sum+=(depth*nestedList[i].getInteger());
//             }
//             else{
//                 sum+=depthSum(nestedList[i].getList(),depth+1);
//             }
//         }
//         return sum;
        
//     }
// };


class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        stack<pair<vector<NestedInteger>, int>> stk;
        int sum = 0;
        stk.push({nestedList, 1}); // Initial depth is 1
        
        while (!stk.empty()) {
            auto [list, depth] = stk.top();
            stk.pop();
            
            for (auto& nestedInt : list) {
                if (nestedInt.isInteger()) {
                    sum += nestedInt.getInteger() * depth;
                } else {
                    stk.push({nestedInt.getList(), depth + 1});
                }
            }
        }
        
        return sum;
    }
};



//bfs, dfs, arrays, hashtables, linkedlists