/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        
        Node* temp = head;
        while(temp!=NULL){
            Node* clone = new Node(temp->val);
            clone->next = temp->next;
            temp->next = clone;
            temp = clone->next;
        }
        
        temp = head;
        
        while(temp!=NULL){
            Node* randomClone = temp->random == NULL? NULL : temp->random->next;
            Node* currentClone = temp->next;
            currentClone->random = randomClone;
            temp = currentClone->next;
        }
        
        // two pointers. one for each node and the clone. 
        temp = head;
        Node* temp2 = head->next;
        Node* toReturn = temp2;
        while(temp!=NULL){
            temp->next = temp->next->next;
            temp2->next = temp2->next == NULL? NULL:temp2->next->next;
            temp = temp->next;
            temp2 = temp2->next;
        }
        

        return toReturn;
    }
};


/// a a b b c c 