/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        queue<Node*> q1;
        q1.push(root);
        q1.push(NULL);
        while(!q1.empty()){
            Node* temp=q1.front();
            q1.pop();
            
            if(temp==NULL){
                
                // either we have reached the end or next level
                if (q1.size() > 0){
                    
                    q1.push(NULL);
                } 
            }
            else{
                
                temp->next=q1.front();
                if(temp->left!=NULL) q1.push(temp->left);
                if(temp->right!=NULL) q1.push(temp->right);
            }
        }
        return root;
    }
};