//following solution from https://leetcode.com/explore/learn/card/graph/623/kahns-algorithm-for-topological-sorting/3886/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        // vector<int> outdegree(numCourses,0);
        vector<vector<int>> adjacency_list(numCourses);
        for(auto pr:prerequisites){
            adjacency_list[pr[1]].push_back(pr[0]);
            indegree[pr[0]]++;
            // outdegree[pr[1]]++;
        }
        
        queue<int> q1;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q1.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q1.empty()){
            int course=q1.front();
            q1.pop();
            ans.push_back(course);
            for(auto c:adjacency_list[course]){
                indegree[c]--;
                if(indegree[c]==0){
                    q1.push(c);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        else{
            vector<int> a;
            return a;
        }
    }
};