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
        if (head == nullptr) return;

        // find the middle of linked list [Problem 876]
        // in 1->2->3->4->5->6 find 4 
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second part of the list [Problem 206]
        // convert 1->2->3->4->5->6 into 1->2->3->4 and 6->5->4
        // reverse the second half in-place
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* tmp;
        while (curr != nullptr) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // merge two sorted linked lists [Problem 21]. More like interweave two linked lists
        // merge 1->2->3->4 and 6->5->4 into 1->6->2->5->3->4
        ListNode* first = head;
        ListNode* second = prev;
        while (second->next != nullptr) {
            tmp = first->next;
            first->next = second;
            first = tmp;
            tmp = second->next;
            second->next = first;
            second = tmp;
        }
    }
};

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         deque<ListNode*> q1;
//         ListNode* temp=head;
//         while(temp!=NULL){
//             q1.push_back(temp);
//             temp=temp->next;
//         }
//         if(q1.size()==0){
//             return;
//         }
//         temp=q1.front();
//         q1.pop_front();
//         int f=1; //1 is take from the back
//         while(!q1.empty()){
//             if(f==1){
//                 temp->next=q1.back();
//                 temp=temp->next;
//                 q1.pop_back();
//                 f=0;
//             }
//             else{
//                 temp->next=q1.front();
//                 temp=temp->next;
//                 q1.pop_front();
//                 f=1;
//             }
//         }
//         temp->next=NULL;
        
//     }
// };
//IDEA: Put everything in a dequeue, and pop from front and back