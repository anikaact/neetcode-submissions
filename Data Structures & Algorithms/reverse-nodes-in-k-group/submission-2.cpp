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
        vector<ListNode*> nodeList;

        while (head != nullptr) {
            nodeList.push_back(head);
            head = head->next;
        }

        for (int i = 0; i < nodeList.size() / k; i++) {
            for (int j = 0; j < k / 2; j++) {
                //cout << j + i*k << ", " << i*k + k - j - 1 << "\n";
                ListNode* temp = nodeList[j + i*k];
                nodeList[j + i*k] = nodeList[i*k + k - j - 1];
                nodeList[i*k + k - j - 1] = temp;
            }
        }

        for (int i = 0; i < nodeList.size() - 1; i++) {
            //cout << nodeList[i]->val;
            nodeList[i]->next = nodeList[i + 1];
        }

        nodeList[nodeList.size() - 1]->next = nullptr;
        return nodeList[0];
    }
};
