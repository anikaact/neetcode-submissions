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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //brute force: put every node into a map (value, node) then go through the map to link nodes together

        //step 1: put all nodes into a vector of pairs {value, node}
        vector<pair<int, ListNode*>> nodes;

        for (ListNode* node : lists) {
            while (node != nullptr) {
                nodes.push_back({node->val, node});
                node = node->next;
            }
        } 

        //step 2: sort vector
        sort(nodes.begin(), nodes.end());

        //step 3: go through map to link all nodes together 

        //case 1: head
        //case 2: middle
        //case 3: tail
        if (nodes.empty()) return nullptr;
        ListNode* head = nodes[0].second;
        ListNode* past = nullptr;
        for (const auto &[val, node] : nodes) {
            if (past != nullptr) past->next = node;
            past = node;
        }

        nodes[nodes.size() - 1].second->next = nullptr;
        return head;
    }
};
