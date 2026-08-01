/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        
        //store all nodes in array
        Node* cur = head;

        vector<Node*> nodes = {};

        while (cur != nullptr) {
            nodes.push_back(cur);
            cur = cur->next;
        }

        //for each value in the array, create a copy
        vector<Node*> newNodes(nodes.size());
        
        for (int i = 0; i < nodes.size(); i++) {
            newNodes[i] = new Node(nodes[i]->val);
            if (i != 0) {
                newNodes[i - 1]->next = newNodes[i];
            }
        }
        cout << nodes.size() << ", " << newNodes.size();

        for (int i = 0; i < nodes.size(); i++) {
            for (int j = 0; j < nodes.size(); j++) {
                if (nodes[i]->random == nullptr) {
                    newNodes[i]->random == nullptr;
                    continue;
                }
                if (nodes[i]->random == nodes[j]) {
                    newNodes[i]->random = newNodes[j];
                }
            }
        }
        
        return newNodes[0];
    }
};
