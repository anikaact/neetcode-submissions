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
vector<int> values;
    void val(TreeNode* node) {
        if (node == nullptr) return;

        values.push_back(node->val);
        val(node->left);
        val(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        val(root);
        sort(values.begin(), values.end());
        return values[k - 1];
    }
};
