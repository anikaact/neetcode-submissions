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
        vector<ListNode*> nodes;

        //for (int i = 0; i < 3; i++) {
        while (head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }

        int front = 0;
        int back = nodes.size() - 1;

        while (front < back) {
            nodes[front]->next = nodes[back];
            front++;
            nodes[back]->next = nodes[front];
            back--;
        }
        nodes[front]->next = nullptr;
    }
};
