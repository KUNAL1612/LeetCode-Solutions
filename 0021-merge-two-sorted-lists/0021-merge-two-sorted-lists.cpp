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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyhead = new ListNode();
        ListNode* prevNode = dummyhead;
        bool isFirst;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                prevNode->next = list1;
                prevNode = prevNode -> next;
                list1 = list1->next;
            }
            else{
                prevNode -> next  = list2;
                prevNode = prevNode -> next;
                list2 = list2 -> next;
            }
        }
        
        while(list1!=NULL){
            prevNode->next = list1;
            prevNode = prevNode -> next;
            list1 = list1->next;
        }
        
        while(list2!=NULL){
            prevNode->next = list2;
            prevNode = prevNode -> next;
            list2 = list2->next;
        }
        
        return dummyhead->next;
    }
};