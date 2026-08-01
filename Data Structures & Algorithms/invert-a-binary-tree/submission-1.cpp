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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) {
            return NULL;
        }
        
        if (root->left != nullptr || root->right != nullptr) {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }

        //invert rest of tree
        invertTree(root->left);
        invertTree(root->right);


        return root;
        
    }
};
