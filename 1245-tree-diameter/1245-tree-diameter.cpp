class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(edges.size() + 1);
        // ^ intuition for the above: n edges connect a tree of n+1 nodes
        for (int i = 0; i < edges.size() + 1; ++i) {
            graph[i] = unordered_set<int>(); // create an empty set
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }

        vector<int> nodeDistance = bfs(0, graph);
        nodeDistance = bfs(nodeDistance[0], graph);

        return nodeDistance[1];
    }

private:
    vector<int> bfs(int start, const vector<unordered_set<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        visited[start] = true;

        queue<int> que;
        que.push(start);
        int lastNode = start, distance = -1;

        while (!que.empty()) {
            queue<int> nextQue;

            while (!que.empty()) {
                int nextNode = que.front();
                que.pop();

                for (int neighbor : graph[nextNode]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nextQue.push(neighbor);
                        lastNode = neighbor;
                    }
                }
            }

            // increase the distance for each level of BFS traversal.
            distance += 1;
            que = nextQue; // bleh way of doing bfs. best way is to use for loop and check size before it. 
        }

        return { lastNode, distance };
    }
};




// main thing here is that, farthest node from any given node is always going to be a leaf node