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
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        ListNode* single = head;
        ListNode* doubl = head->next;

        while(doubl->next && doubl->next->next && single!=doubl) {
            single = single->next;
            doubl = doubl->next->next;
        }

        if (doubl->next && doubl->next->next) return true;

        return false;
    }
};
