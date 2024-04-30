// @leet start
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
    int sumOfTree(TreeNode* root) {
        if(!root) return 0;
        return root->val + sumOfTree(root->left) + sumOfTree(root->right);
    }

    bool checkTree(TreeNode* root) {
        return root->val == sumOfTree(root->left) + sumOfTree(root->right);
    }
};
// @leet end
