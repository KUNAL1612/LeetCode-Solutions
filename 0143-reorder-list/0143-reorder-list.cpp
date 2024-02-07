/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> q1;
        ListNode* temp=head;
        while(temp!=NULL){
            q1.push_back(temp);
            temp=temp->next;
        }
        if(q1.size()==0){
            return;
        }
        temp=q1.front();
        q1.pop_front();
        int f=1; //1 is take from the back
        while(!q1.empty()){
            if(f==1){
                temp->next=q1.back();
                temp=temp->next;
                q1.pop_back();
                f=0;
            }
            else{
                temp->next=q1.front();
                temp=temp->next;
                q1.pop_front();
                f=1;
            }
        }
        temp->next=NULL;
        
    }
};
//IDEA: Put everything in a dequeue, and pop from front and back