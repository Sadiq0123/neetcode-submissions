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
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;

        ListNode* ans = head;
        ListNode* prev=nullptr;
        while(ans->next!=nullptr) {
            ListNode* nxt = ans->next;
            ans->next = prev;
            prev = ans;
            ans = nxt;
        }

        ans->next = prev;
        return ans;
    }
};
