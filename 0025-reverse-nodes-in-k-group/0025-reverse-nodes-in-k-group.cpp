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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode *first = head, *end = head;
        for(int i = 0; i < k - 1; ++i)
        {
            end = end->next;
            if (!end) return first;
        }
        end->next = reverseKGroup(end->next, k);
        return invertList(first, end);
    }
    ListNode* invertList(ListNode* first, ListNode* end)
    {
        if (first == end) return first;
        ListNode *tmp = end->next;
        ListNode *p = invertList(first->next, end);
        first->next->next = first;
        first->next = tmp;
        return p;
    }
};

 