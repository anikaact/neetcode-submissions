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
 
 /*
            4
        3        5
                    8
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == q) {
            return p;
        }
        if ((root->val == p->val) || (root->val == q->val)) {
            return root;
        }
        int greater = max(p->val, q->val);
        int less = min(p->val, q->val);
        if ((root->val >= less) && (root->val <= greater)) {
            return root;
        }
        if (root->val > greater) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return lowestCommonAncestor(root->right, p, q);
        }

    }
};
