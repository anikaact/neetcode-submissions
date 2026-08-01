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
        int sz = 0;
        ListNode* cur = head;

        while (cur != nullptr) {
            sz++;
            cur = cur->next;
        }

        int remove = sz - n;

        cur = head;
        ListNode* past = nullptr;
        for (int i = 0; i < remove; i++) {
            past = cur;
            cur = cur->next;
        }

        if (past == nullptr && n == 1) return nullptr;
        if (past == nullptr) return cur->next;
        past->next = cur->next;
        return head;
    }
};
