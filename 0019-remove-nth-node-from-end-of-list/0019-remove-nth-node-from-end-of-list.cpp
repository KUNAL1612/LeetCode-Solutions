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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*prev=head;
        ListNode*first=head;
        ListNode*second=head;
        int i=1;
        for(i=1;i<n;i++){
            second=second->next;
        }
        cout<<second->val;
        int flag=0;
        while(second->next!=NULL){
            second=second->next;
            first=first->next;
            if(flag==1){
                prev=prev->next;
            }
            flag=1;
        }
        if(first==head)
        {
            
            head=head->next;
            
        }
        else
        {
            
            prev->next=first->next;
            
        }
        return head;
    }
};
