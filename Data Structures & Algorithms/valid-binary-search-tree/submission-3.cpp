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
    bool validate(TreeNode* node, long minimum, long maximum) {
        if (node == nullptr) return true;
        if (node->val > minimum && node->val < maximum) {
            return validate(node->left, minimum, node->val) && validate(node->right, node->val, maximum);
        }

        return false;
        //cout << minimum << ", " << maximum << ", " << node->val << "\n";

        
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }       
};
