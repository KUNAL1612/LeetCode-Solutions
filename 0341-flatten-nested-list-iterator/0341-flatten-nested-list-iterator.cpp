/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    // store the start and end pointer of nestedLists
    stack<pair<NestedInteger*,NestedInteger*>> list;
    
    NestedIterator(vector<NestedInteger> &nestedList) {

        if(nestedList.empty()) return;
        
        int size = nestedList.size();
        list.push({&nestedList[0],&nestedList[size-1]});
    }
    
    int next() {
        
        // return top element of the stack and increment top start pointer
        return list.top().first++->getInteger();
    }
    
    bool hasNext() {
        
        if(list.empty()) return false;
        
        // check if currrent top start > end, means all elements of the list are explored
        // then pop from stack and increment next top start pointer
        while(!list.empty() && list.top().first > list.top().second)
        {
            list.pop();
            if(!list.empty())list.top().first++;
        }
          
        if(!list.empty())
        {
            // store all the nested lists of stack top start pointer
            while(list.top().first->getList().size())
            {
                vector<NestedInteger> &nestedList = list.top().first->getList();
                int size = nestedList.size();
                list.push({&nestedList[0],&nestedList[size-1]});            
            }

            // check if stack top start element is an integer
            // if not then it is an empty object and so need to ignore it
            // increment top start pointer and call hasNext to get next element
            if(!list.top().first->isInteger())
            {
                list.top().first++;
                hasNext();
            }
        }
        
        return !list.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */