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
    int res = INT_MIN;

    int maxGain(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        res = max(res, node->val + leftGain + rightGain);

        return node->val + max(leftGain, rightGain);
        
    }

    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        maxGain(root);
        return res;
    }
};
