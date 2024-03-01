class Solution {
public:
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        vector<vector<int>> graph(n);
        vector<int> degrees(n, 0), res;
        int V = n;
        
        //Make the graph and also increment each node's degrees simultaneously.
        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        
        /*Push all 1 degree nodes into Q. These 1 degree nodes will include the originating roots and the leaf nodes. 
        Ex:         0
                    |
                    1
                   / \
                  2   3
    The Q will have {0, 2, 3}. All these have 1 degree nodes. Make these degrees as -1, just so that they will not be included in the result vector.*/
        while(V > 2)
        {
            vector<int> Q; // Q is inside this loop because we are doing layer by layer starting with the outermost layer
            for(int i = 0; i < n; i++)
            {
                if(degrees[i] == 1)
                {
                    Q.push_back(i);
                    degrees[i] = -1;
                    V--;
                }
            }
    
        /*Do BFS and iterate through neighbors of each node. The key here is to find the middle nodes of the graph. They are roots for MHTs.
            While iterating through the negihbors, decrement their in-degrees.
            If you consider above example, its basically moving one step closer towards middle node (1) from either ends.
            You have 0, 2, 3. You decrement its neighbor's node(1) degree. You move one down from 0, one up from 2 and 3.
            Finally, in the end, the degrees which have 1 or 0 are your middle nodes of the graph and those are the roots for MHTs.
        */
            for(auto i : Q)
            {
                for(int neighbor : graph[i])
                    degrees[neighbor]--;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(degrees[i] == 1 || degrees[i] == 0) //central node. there can be either two or one central node. If the central node is made of 2 nodes, then they each will have degree 1, if not then the single central node will have degree 0
                res.push_back(i);
        }
        return res;
    }
};