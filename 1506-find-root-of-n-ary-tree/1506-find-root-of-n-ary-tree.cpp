/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, int> size_from_here;
    
    // unordered_set<Node*> seen;
    
    int size_of_tree(Node* root){
        if(root == NULL){
            return 0;
        }
        // if(seen.find(root)!=seen.end()){
        //     return;
        // }
        
        if(size_from_here[root]!=0){
            return size_from_here[root];
        }
        
        int size = 1;
        for(auto c:root->children){
            size += size_of_tree(c);
        }
        
        size_from_here[root] = size;
        return size;
    }
    
    Node* findRoot(vector<Node*> tree) {
        int max_size = INT_MIN;
        Node* max_node;
        for(auto node: tree){
            cout<<node->val;
            int size = size_of_tree(node);
            if(size>max_size){
                max_size = size;
                max_node = node;
            }
            
        }
        
        return max_node;
    }
};



// 1 