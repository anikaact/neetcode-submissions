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
    vector<vector<int>> result;
    void insertLevel(vector<TreeNode*> nodeList) {
        if (nodeList.empty()) return;

        vector<int> level;
        for (TreeNode* node : nodeList) {
            level.push_back(node->val);
        }
        result.push_back(level);

        vector<TreeNode* > nextLevel;
        for (TreeNode* node : nodeList) {
            if (node->left !=  nullptr) nextLevel.push_back(node->left);
            if (node->right != nullptr) nextLevel.push_back(node->right);
        }
        insertLevel(nextLevel);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        insertLevel({root});
        return result;
    }
};
