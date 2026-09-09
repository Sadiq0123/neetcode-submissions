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
        int l=0;
        ListNode* temp = head;
        while(temp) {
            l++;
            temp = temp->next;
        }
        int ind = l-n;
        temp = head;
        if (ind==0) return head->next;
        while(ind>0) {
            if (ind==1) {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
            ind--;
        }
        return head;
    }
};
