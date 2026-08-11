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
    vector<int> res;
    
    void recurs(vector<TreeNode*> nodes) {
        if (nodes.empty()) return;
        res.push_back(nodes[nodes.size() - 1]->val);

        vector<TreeNode*> newnodes;
        for (TreeNode* node : nodes) {
            if (node->left != nullptr) {
                newnodes.push_back(node->left);
            }
            if (node->right != nullptr) {
                newnodes.push_back(node->right);
            }
        }

        recurs(newnodes);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        recurs({root});
        return res;
    }
};
