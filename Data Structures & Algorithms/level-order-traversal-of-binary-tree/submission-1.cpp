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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode* > bfs;

        if (root == nullptr) return {};
        bfs.push(root);

        while (!bfs.empty()) {
            vector<int> level;
            int size = bfs.size();

            for (int i = 0; i < size; i++) {
                level.push_back(bfs.front()->val);
                if (bfs.front()->left != nullptr) bfs.push(bfs.front()->left);
                if (bfs.front()->right != nullptr) bfs.push(bfs.front()->right);
                bfs.pop();
            }

            result.push_back(level);
        }

        return result;

    }
};
