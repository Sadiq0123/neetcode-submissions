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
        unordered_map<int, ListNode*> mp;
        int i=0;
        while(head) {
            mp[i] = head;
            head = head->next;
            i++;
        }

        int n = i;
        i=0;
        while(i<n/2) {
            mp[i]->next = mp[n-1-i];
            mp[n-1-i]->next = mp[i+1];
            i++;
        }
        mp[i]->next = nullptr;
    }
};
