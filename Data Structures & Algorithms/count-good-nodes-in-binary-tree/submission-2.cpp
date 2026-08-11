/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodnodes = 0;

    void getPaths(TreeNode* node, int maximum) {
        if (node == nullptr) return;

        if (node->val >= maximum) {
            goodnodes++;
            maximum = node->val;
        }
        //cout << node->val << ", " << maximum << "\n";

        getPaths(node->left, maximum);
        getPaths(node->right, maximum);
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        getPaths(root, INT_MIN);
        return goodnodes;
    }
};
